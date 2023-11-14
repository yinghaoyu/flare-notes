
#include "flare/base/down_cast.h"

#include <gtest/gtest.h>

namespace flare {

struct A {
  virtual ~A() = default;
};

struct B : A {};

TEST(Cast, All) {
  B b;
  A* ptr = &b;
  ASSERT_NE(nullptr, down_cast<B>(ptr));
  ASSERT_NE(nullptr, down_cast<B>(const_cast<const A*>(ptr)));
}

#ifndef NDEBUG

TEST(CastDeathTest, InvalidCast) {
  A a;
  A* ptr = &a;
  ASSERT_DEATH(down_cast<B>(ptr), "");
}

#endif

}  // namespace flare
