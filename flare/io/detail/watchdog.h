#ifndef FLARE_IO_DETAIL_WATCHDOG_H_
#define FLARE_IO_DETAIL_WATCHDOG_H_

#include <atomic>
#include <thread>
#include <vector>

#include "flare/base/delayed_init.h"
#include "flare/base/thread/latch.h"

namespace flare {

class EventLoop;

}  // namespace flare

namespace flare::io::detail {

// `Watchdog` is responsible for monitoring healthiness of `EventLoop`s.
//
// If one (or more) `EventLoop` has not run for a sufficient long time,
// `Watchdog` has a right to crash the whole system.
class Watchdog {
 public:
  Watchdog();

  // Add a new `EventLoop` for watching.
  //
  // Thread-compatible. All `EventLoop`s must be added before calling `Start()`.
  void AddEventLoop(EventLoop* watched);

  void Start();
  void Stop();

  // Caveat: Even if `Join()` returns, it's well possible the task posted
  // to `EventLoop` by `*this` is being called (or even pending for being
  // called). And `*this` consequently could not be destroyed.
  //
  // `Stop()` & `Join()` the `EventLoop` before destroying `*this`.
  void Join();

 private:
  void WorkerProc();

 private:
  std::atomic<bool> exiting_{false};
  Latch exiting_latch_{1};  // For notify `WorkerProc()`.
  std::vector<EventLoop*> watched_;
  DelayedInit<std::thread> watcher_;
};

}  // namespace flare::io::detail

#endif  // FLARE_IO_DETAIL_WATCHDOG_H_
