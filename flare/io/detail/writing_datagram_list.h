#ifndef FLARE_IO_DETAIL_WRITING_DATAGRAM_LIST_H_
#define FLARE_IO_DETAIL_WRITING_DATAGRAM_LIST_H_

#include <deque>
#include <mutex>
#include <tuple>

#include "flare/base/buffer.h"
#include "flare/base/net/endpoint.h"

namespace flare::io::detail {

// Like `WritingBufferList`, specialized for datagrams.
class WritingDatagramList {
 public:
  // Write a datagram into `fd`.
  ssize_t FlushTo(int fd, std::uintptr_t* flushed_ctx, bool* emptied);

  // Thread-safe.
  //
  // Return true if the list is empty before. (Hence the caller is responsible
  // for starting writing.
  bool Append(Endpoint to, NoncontiguousBuffer buffer, std::uintptr_t ctx);

 private:
  // TODO(luobogao): Optimize this.
  //
  // Do NOT use fiber::Mutex here, we're using TLS internally.
  mutable std::mutex lock_;
  std::deque<std::tuple<Endpoint, NoncontiguousBuffer, std::uintptr_t>>
      buffers_;
};

}  // namespace flare::io::detail

#endif  // FLARE_IO_DETAIL_WRITING_DATAGRAM_LIST_H_
