#ifndef FLARE_FIBER_DETAIL_TESTING_H_
#define FLARE_FIBER_DETAIL_TESTING_H_

//////////////////////////////////////////////
// Mostly used by flare.fiber internally.   //
//                                          //
// For non-flare developers, consider using //
// `flare/testing/main.h` instead.          //
//////////////////////////////////////////////

#include <atomic>
#include <thread>
#include <utility>

#include "flare/fiber/detail/fiber_desc.h"
#include "flare/fiber/detail/fiber_entity.h"
#include "flare/fiber/detail/scheduling_group.h"
#include "flare/fiber/fiber.h"
#include "flare/fiber/runtime.h"

namespace flare::fiber::testing {

template <class F>
void RunAsFiber(F&& f) {
  fiber::StartRuntime();
  std::atomic<bool> done{};
  Fiber([&, f = std::forward<F>(f)] {
    f();
    done = true;
  }).detach();
  while (!done) {
    std::this_thread::sleep_for(std::chrono::microseconds(1));
  }
  fiber::TerminateRuntime();
}

template <class F>
void StartFiberEntityInGroup(detail::SchedulingGroup* sg, bool system_fiber,
                             F&& f) {
  auto desc = detail::NewFiberDesc();
  desc->start_proc = std::move(f);
  desc->system_fiber = system_fiber;
  desc->scheduling_group_local = false;
  sg->StartFiber(desc);
}

}  // namespace flare::fiber::testing

#endif  // FLARE_FIBER_DETAIL_TESTING_H_
