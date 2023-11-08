#include "flare/base/erased_ptr.h"

#include <gtest/gtest.h>

namespace flare {

struct C {
  C() { ++instances; }
  ~C() { --instances; }
  inline static int instances = 0;
};

TEST(ErasedPtr, All) {
  ASSERT_EQ(0, C::instances);
  {
    ErasedPtr ptr(new C{});
    ASSERT_EQ(1, C::instances);
    auto deleter = ptr.GetDeleter();
    auto p = ptr.Leak();
    ASSERT_EQ(1, C::instances);
    deleter(p);
    ASSERT_EQ(0, C::instances);
  }
  ASSERT_EQ(0, C::instances);
  {
    ErasedPtr ptr(new C{});
    ASSERT_EQ(1, C::instances);
  }
  ASSERT_EQ(0, C::instances);
}

}  // namespace flare
