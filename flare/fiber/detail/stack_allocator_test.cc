#include "flare/fiber/detail/stack_allocator.h"

#include <unistd.h>

#include "gflags/gflags.h"
#include "gtest/gtest.h"

#include "flare/base/internal/annotation.h"
#include "flare/base/logging.h"

DECLARE_int32(flare_fiber_stack_size);

namespace flare::fiber::detail {

// If ASan is present, the death test below triggers ASan and aborts.
#ifndef FLARE_INTERNAL_USE_ASAN

TEST(StackAllocatorDeathTest, SystemStackCanaryValue) {
  auto stack = CreateSystemStack();
  ASSERT_TRUE(stack);
  memset(stack, 0, 8192);  // Canary value is overwritten.
  ASSERT_DEATH(FreeSystemStack(stack), "stack is corrupted");
}

#endif

TEST(StackAllocator, UserStack) {
  auto stack = CreateUserStack();
  ASSERT_TRUE(stack);
  memset(stack, 0, FLAGS_flare_fiber_stack_size);
  FreeUserStack(stack);
}

#ifndef FLARE_INTERNAL_USE_ASAN

TEST(StackAllocator, SystemStack) {
  auto stack = CreateSystemStack();
  ASSERT_TRUE(stack);
  memset(reinterpret_cast<char*>(stack) + 16 /* Canary value */, 0,
         kSystemStackSize - 16);
  FreeSystemStack(stack);
}

#else

TEST(StackAllocator, SystemStack) {
  auto stack = CreateSystemStack();
  ASSERT_TRUE(stack);
  memset(reinterpret_cast<char*>(stack) +
             kSystemStackPoisonedSize /* Poisoned page */,
         0, kSystemStackSize - kSystemStackPoisonedSize);
  FreeSystemStack(stack);
}

#endif

}  // namespace flare::fiber::detail
