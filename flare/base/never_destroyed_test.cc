#include "flare/base/never_destroyed.h"

#include "gtest/gtest.h"

namespace flare {

struct C {
  C() { ++instances; }
  ~C() { --instances; }
  inline static std::size_t instances{};
};

struct D {
  void foo() {
    [[maybe_unused]] static NeverDestroyedSingleton<D> test_compilation2;
  }
};

NeverDestroyed<int> test_compilation2;

TEST(NeverDestroyed, All) {
  ASSERT_EQ(0, C::instances);
  {
    C c1;
    ASSERT_EQ(1, C::instances);
    [[maybe_unused]] NeverDestroyed<C> c2;
    ASSERT_EQ(2, C::instances);
  }
  // Not 0, as `NeverDestroyed<C>` is not destroyed.
  ASSERT_EQ(1, C::instances);
}

}  // namespace flare
