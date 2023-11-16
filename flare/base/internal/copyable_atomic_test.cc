#include "flare/base/internal/copyable_atomic.h"

#include "gtest/gtest.h"

namespace flare::internal {

TEST(CopyableAtomic, int) {
  CopyableAtomic<int> x{123};
  auto y = x;
  EXPECT_EQ(123, y);
}

}  // namespace flare::internal
