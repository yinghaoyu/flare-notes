#include "flare/io/detail/writing_datagram_list.h"

#include <limits.h>

#include <algorithm>
#include <string>
#include <utility>

#include "flare/base/internal/annotation.h"
#include "flare/io/detail/eintr_safe.h"

namespace flare::io::detail {

ssize_t WritingDatagramList::FlushTo(int fd, std::uintptr_t* flushed_ctx,
                                     bool* emptied) {
  // This array is likely to be large, so make it TLS to prevent StackOverflow
  // (tm).
  FLARE_INTERNAL_TLS_MODEL thread_local iovec iov[IOV_MAX];
  std::unique_lock lk(lock_);
  std::size_t nv = 0;
  CHECK(!buffers_.empty());
  auto&& [to, datagram, ctx] = buffers_.front();
  bool overflowed = false;
  std::string flatten;  // Used if `overflowed` holds.

  // Build iovec.
  for (auto bi = datagram.begin(); bi != datagram.end(); ++bi) {
    if (nv >= std::size(iov)) {  // Highly fragmented, see below.
      overflowed = true;
      break;
    }
    auto&& b = *bi;
    auto&& e = iov[nv++];
    e.iov_base = const_cast<char*>(b.data());
    e.iov_len = b.size();
  }

  if (overflowed) {  // The datagram is highly fragmented and cannot be suited
                     // into `IOV_MAX` `iovec`s. Here we flatten the buffer into
                     // a big contiguous block.
    FLARE_LOG_WARNING_EVERY_SECOND(
        "Datagram is highly fragmented and cannot be handled by `iovec`s. "
        "Flattening.");
    flatten = FlattenSlow(datagram);
    auto&& v = iov[0];
    v.iov_base = flatten.data();
    v.iov_len = flatten.size();
    nv = 1;
  }
  *flushed_ctx = ctx;
  lk.unlock();

  // Technically we'd better accessing `to` under lock, but accessing it without
  // lock shouldn't hurt here.
  msghdr msg = {
      .msg_name = const_cast<void*>(reinterpret_cast<const void*>(to.Get())),
      .msg_namelen = to.Length(),
      .msg_iov = iov,
      .msg_iovlen = nv,
      .msg_control = nullptr,
      .msg_controllen = 0,
      .msg_flags = 0};
  auto rc = detail::EIntrSafeSendMsg(fd, &msg, 0);
  if (rc <= 0) {
    return rc;
  }

  // We're the only writer, thus the first block should not be touched by
  // others between `unlock()` and `lock()`.
  lk.lock();
  buffers_.pop_front();
  *emptied = buffers_.empty();
  return rc;
}

bool WritingDatagramList::Append(Endpoint to, NoncontiguousBuffer buffer,
                                 std::uintptr_t ctx) {
  std::scoped_lock lk(lock_);
  buffers_.emplace_back(std::tuple(std::move(to), std::move(buffer), ctx));
  return buffers_.size() == 1;  // Was empty.
}

}  // namespace flare::io::detail
