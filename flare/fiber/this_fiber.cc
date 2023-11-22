#include "flare/fiber/this_fiber.h"

#include "flare/fiber/detail/fiber_entity.h"
#include "flare/fiber/detail/scheduling_group.h"
#include "flare/fiber/detail/waitable.h"

namespace flare::this_fiber {

Fiber::Id GetId() {
  auto self = fiber::detail::GetCurrentFiberEntity();
  FLARE_CHECK(self,
              "this_fiber::GetId may only be called in fiber environment.");
  return reinterpret_cast<Fiber::Id>(self);
}

void Yield() {
  auto self = fiber::detail::GetCurrentFiberEntity();
  FLARE_CHECK(self,
              "this_fiber::Yield may only be called in fiber environment.");
  self->scheduling_group->Yield(self);
}

void SleepUntil(std::chrono::steady_clock::time_point expires_at) {
  fiber::detail::WaitableTimer wt(expires_at);
  wt.wait();
}

void SleepFor(std::chrono::nanoseconds expires_in) {
  SleepUntil(ReadSteadyClock() + expires_in);
}

}  // namespace flare::this_fiber
