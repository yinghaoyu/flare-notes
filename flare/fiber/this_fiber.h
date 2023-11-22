#ifndef FLARE_FIBER_THIS_FIBER_H_
#define FLARE_FIBER_THIS_FIBER_H_

#include <chrono>

#include "flare/base/chrono.h"
#include "flare/fiber/fiber.h"

namespace flare::this_fiber {

// Yield execution.
//
// If there's no other fiber is ready to run, the caller will be rescheduled
// immediately.
void Yield();

// Block calling fiber until `expires_at`.
void SleepUntil(std::chrono::steady_clock::time_point expires_at);

// Block calling fiber for `expires_in`.
void SleepFor(std::chrono::nanoseconds expires_in);

// `SleepUntil` for clocks other than `std::steady_clock`.
template <class Clock, class Duration>
void SleepUntil(std::chrono::time_point<Clock, Duration> expires_at) {
  return SleepUntil(ReadSteadyClock() + (expires_at - Clock::now()));
}

// `SleepFor` for durations other than `std::chrono::nanoseconds`.
template <class Rep, class Period>
void SleepFor(std::chrono::duration<Rep, Period> expires_in) {
  return SleepFor(static_cast<std::chrono::nanoseconds>(expires_in));
}

// Returns fiber ID of the calling fiber.
Fiber::Id GetId();

}  // namespace flare::this_fiber

#endif  // FLARE_FIBER_THIS_FIBER_H_
