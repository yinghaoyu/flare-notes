#include "flare/base/internal/lazy_init.h"

#include "gtest/gtest.h"

namespace flare::internal {

struct A {
  A() { ++instances; }
  ~A() { --instances; }
  inline static int instances = 0;
};

TEST(LazyInit, All) {
  ASSERT_EQ(0, A::instances);
  LazyInit<A>();
  ASSERT_EQ(1, A::instances);
  LazyInit<A>();
  ASSERT_EQ(1, A::instances);
  LazyInit<A>();
  ASSERT_EQ(1, A::instances);
  LazyInit<A>();
  ASSERT_EQ(1, A::instances);
  LazyInit<A>();
  ASSERT_EQ(1, A::instances);
  LazyInit<A, int>();
  ASSERT_EQ(2, A::instances);
  LazyInit<A, int>();
  ASSERT_EQ(2, A::instances);
  LazyInit<A, struct X>();
  ASSERT_EQ(3, A::instances);
}

}  // namespace flare::internal
