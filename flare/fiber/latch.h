#ifndef FLARE_FIBER_LATCH_H_
#define FLARE_FIBER_LATCH_H_

#include "flare/base/function.h"
#include "flare/fiber/condition_variable.h"
#include "flare/fiber/mutex.h"

namespace flare::fiber {

// Analogous to `std::latch`, but it's for fiber.
//
// TODO(luobogao): We do not perfectly match `std::latch` yet.
class Latch {
 public:
  // TODO(luobogao): static constexpr ptrdiff_t max() noexcept;

  explicit Latch(std::ptrdiff_t count);

  // Count the latch down.
  //
  // If total number of call to this method reached `count` (passed to
  // constructor), all waiters are waken up.
  //
  // `std::latch` support specifying count here, we don't support it for the
  // moment.
  void count_down(std::ptrdiff_t update = 1);

  // Test if the latch's internal counter has become zero.
  bool try_wait() const noexcept;

  // Wait until the latch's internal counter becomes zero.
  void wait() const;

  // Extension to `std::latch`.
  template <class Rep, class Period>
  bool wait_for(std::chrono::duration<Rep, Period> timeout) {
    std::unique_lock lk(lock_);
    FLARE_CHECK_GE(count_, 0);
    return cv_.wait_for(lk, timeout, [this] { return count_ == 0; });
  }

  // Extension to `std::latch`.
  template <class Clock, class Duration>
  bool wait_until(std::chrono::time_point<Clock, Duration> timeout) {
    std::unique_lock lk(lock_);
    FLARE_CHECK_GE(count_, 0);
    return cv_.wait_until(lk, timeout, [this] { return count_ == 0; });
  }

  // Count the latch down and wait for it to become zero.
  //
  // If total number of call to this method reached `count` (passed to
  // constructor), all waiters are waken up.
  void arrive_and_wait(std::ptrdiff_t update = 1);

 private:
  mutable Mutex lock_;
  mutable ConditionVariable cv_;
  std::ptrdiff_t count_;
};

}  // namespace flare::fiber

#endif  // FLARE_FIBER_LATCH_H_
