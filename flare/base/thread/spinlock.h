#ifndef FLARE_BASE_THREAD_SPINLOCK_H_
#define FLARE_BASE_THREAD_SPINLOCK_H_

#include <atomic>

#include "flare/base/likely.h"

namespace flare {

// The class' name explains itself well.
//
// FIXME: Do we need TSan annotations here?
class Spinlock {
 public:
  void lock() noexcept {
    // Here we try to grab the lock first before failing back to TTAS.
    //
    // If the lock is not contend, this fast-path should be quicker.
    // If the lock is contended and we have to fail back to slow TTAS, this
    // single try shouldn't add too much overhead.
    //
    // What's more, by keeping this method small, chances are higher that this
    // method get inlined by the compiler.
    if (FLARE_LIKELY(try_lock())) {
      return;
    }

    // Slow path otherwise.
    LockSlow();
  }

  bool try_lock() noexcept {
    return !locked_.exchange(true, std::memory_order_acquire);
  }

  void unlock() noexcept { locked_.store(false, std::memory_order_release); }

 private:
  void LockSlow() noexcept;

 private:
  std::atomic<bool> locked_{false};
};

}  // namespace flare

#endif  // FLARE_BASE_THREAD_SPINLOCK_H_
