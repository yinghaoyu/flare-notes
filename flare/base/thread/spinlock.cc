#include "flare/base/thread/spinlock.h"

#include <chrono>

using namespace std::literals;

#if defined(__x86_64__)
#define FLARE_CPU_RELAX() asm volatile("pause" ::: "memory")
#else
// TODO(luobogao): Implement this macro for non-x86 ISAs.
#define FLARE_CPU_RELAX()
#endif

namespace flare {

// @s: https://code.woboq.org/userspace/glibc/nptl/pthread_spin_lock.c.html
void Spinlock::LockSlow() noexcept {
  do {
    // Test ...
    while (locked_.load(std::memory_order_relaxed)) {
      FLARE_CPU_RELAX();
    }

    // ... and set.
  } while (locked_.exchange(true, std::memory_order_acquire));
}

}  // namespace flare
