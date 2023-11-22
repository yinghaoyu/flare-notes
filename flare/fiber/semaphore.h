#ifndef FLARE_FIBER_SEMAPHORE_H_
#define FLARE_FIBER_SEMAPHORE_H_

#include <chrono>
#include <cinttypes>
#include <limits>
#include <type_traits>

#include "flare/base/thread/semaphore.h"
#include "flare/fiber/condition_variable.h"
#include "flare/fiber/mutex.h"

namespace flare::fiber {

// Same as `flare::CountingSemaphore` except that this one is for fiber. That
// is, this only only blocks the calling fiber, but not the underlying pthread.
template <std::ptrdiff_t kLeastMaxValue =
              std::numeric_limits<std::uint32_t>::max()>
class CountingSemaphore
    : public flare::BasicCountingSemaphore<
          fiber::Mutex, fiber::ConditionVariable, kLeastMaxValue> {
 public:
  explicit CountingSemaphore(std::ptrdiff_t desired)
      : BasicCountingSemaphore<fiber::Mutex, fiber::ConditionVariable,
                               kLeastMaxValue>(desired) {}
};

using BinarySemaphore = CountingSemaphore<1>;

}  // namespace flare::fiber

#endif  // FLARE_FIBER_SEMAPHORE_H_
