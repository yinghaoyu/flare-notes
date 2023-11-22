#include "flare/fiber/detail/fiber_desc.h"

#include "gtest/gtest.h"

namespace flare::fiber::detail {

TEST(FiberDesc, All) {
  // Not much to test.
  auto ptr = NewFiberDesc();
  ASSERT_TRUE(isa<FiberDesc>(ptr));
  DestroyFiberDesc(ptr);
}

}  // namespace flare::fiber::detail
