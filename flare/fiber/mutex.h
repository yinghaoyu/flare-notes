#ifndef FLARE_FIBER_MUTEX_H_
#define FLARE_FIBER_MUTEX_H_

#include "flare/fiber/detail/waitable.h"

namespace flare::fiber {

// Analogous to `std::mutex`, but it's for fiber.
using Mutex = detail::Mutex;

}  // namespace flare::fiber

#endif  // FLARE_FIBER_MUTEX_H_
