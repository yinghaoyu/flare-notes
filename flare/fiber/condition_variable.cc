#include "flare/fiber/condition_variable.h"

namespace flare::fiber {

void ConditionVariable::notify_one() noexcept { impl_.notify_one(); }

void ConditionVariable::notify_all() noexcept { impl_.notify_all(); }

void ConditionVariable::wait(std::unique_lock<Mutex>& lock) {
  impl_.wait(lock);
}

}  // namespace flare::fiber
