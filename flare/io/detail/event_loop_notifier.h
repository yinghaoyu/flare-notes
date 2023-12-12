#ifndef FLARE_IO_DETAIL_EVENT_LOOP_NOTIFIER_H_
#define FLARE_IO_DETAIL_EVENT_LOOP_NOTIFIER_H_

#include "flare/io/descriptor.h"

namespace flare::io::detail {

// This class is used to wake event loop thread up in certain cases.
//
// A notifier is implemented in terms of an eventfd. `Notify` would signal the
// event, which in turn, wakes up event loop thread if it's sleeping now.
class EventLoopNotifier final {
 public:
  EventLoopNotifier();

  int fd() const noexcept;

  // Wake up the event loop.
  void Notify() noexcept;

  // Once woken up, it's the event loop's responsibility to call this to drain
  // any pending events signaled by `Notify`.
  void Reset() noexcept;

 private:
  Handle fd_;
};

}  // namespace flare::io::detail

#endif  // FLARE_IO_DETAIL_EVENT_LOOP_NOTIFIER_H_
