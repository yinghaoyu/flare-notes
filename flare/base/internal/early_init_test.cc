#include "flare/base/internal/early_init.h"

#include "gtest/gtest.h"

namespace flare::internal {

struct A {
  A() { ++instances; }
  ~A() { --instances; }
  inline static int instances = 0;
};

TEST(EarlyInit, All) {
  // Instantiated even before first call to `EarlyInit`.
  ASSERT_EQ(3, A::instances);

  EarlyInitConstant<A>();
  ASSERT_EQ(3, A::instances);
  EarlyInitConstant<A>();
  ASSERT_EQ(3, A::instances);
  EarlyInitConstant<A, int>();
  ASSERT_EQ(3, A::instances);
  EarlyInitConstant<A, int>();
  ASSERT_EQ(3, A::instances);
  EarlyInitConstant<A, struct X>();
  ASSERT_EQ(3, A::instances);
}

}  // namespace flare::internal
