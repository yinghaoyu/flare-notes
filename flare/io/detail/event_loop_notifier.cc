#include "flare/io/detail/event_loop_notifier.h"

#include <fcntl.h>
#include <sys/eventfd.h>
#include <unistd.h>

#include "flare/base/logging.h"
#include "flare/fiber/alternatives.h"
#include "flare/io/detail/eintr_safe.h"

namespace flare::io::detail {

namespace {

Handle CreateEvent() {
  Handle fd(eventfd(0, EFD_CLOEXEC | EFD_NONBLOCK));
  FLARE_PCHECK(fd, "Cannot create eventfd.");
  return fd;
}

}  // namespace

EventLoopNotifier::EventLoopNotifier() : fd_(CreateEvent()) {}

int EventLoopNotifier::fd() const noexcept { return fd_.Get(); }

void EventLoopNotifier::Notify() noexcept {
  std::uint64_t v = 1;
  PCHECK(io::detail::EIntrSafeWrite(fd(), &v, sizeof(v)) == sizeof(v));
}

void EventLoopNotifier::Reset() noexcept {
  std::uint64_t v;
  int rc;

  // Keep reading until EOF is met.
  //
  // This shouldn't take too long, as there should be only
  // number-of-Notify-calls bytes readable anyway.
  do {
    rc = io::detail::EIntrSafeRead(fd(), &v, sizeof(v));
    PCHECK(rc >= 0 || fiber::GetLastError() == EAGAIN ||
           fiber::GetLastError() == EWOULDBLOCK);
  } while (rc > 0);
}

}  // namespace flare::io::detail
