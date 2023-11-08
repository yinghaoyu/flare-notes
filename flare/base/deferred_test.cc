#include "flare/base/deferred.h"

#include <gtest/gtest.h>

using namespace std::literals;

namespace flare {

TEST(ScopedDeferred, All) {
  bool f = false;
  {
    ScopedDeferred defer([&] { f = true; });
    ASSERT_FALSE(f);
  }
  ASSERT_TRUE(f);
}

TEST(Deferred, All) {
  bool f1 = false, f2 = false;
  {
    Deferred defer([&] { f1 = true; });
    ASSERT_FALSE(f1);
    Deferred defer2([&] { f2 = true; });
    defer2.Dismiss();
    ASSERT_FALSE(f2);
  }
  ASSERT_TRUE(f1);
  ASSERT_FALSE(f2);

  bool f3 = false;
  Deferred defer3([&] { f3 = true; });
  ASSERT_FALSE(f3);
  defer3.Fire();
  ASSERT_TRUE(f3);

  bool f4;
  Deferred defer5;
  {
    Deferred defer4([&] { f4 = true; });
    ASSERT_FALSE(f4);
    defer5 = std::move(defer4);
  }
  ASSERT_FALSE(f4);
  auto defer6 = std::move(defer5);
  defer5.Fire();
  ASSERT_FALSE(f4);
  defer6.Fire();
  ASSERT_TRUE(f4);

  Deferred().Fire();     // Nothing happens.
  Deferred().Dismiss();  // Nothing happens.
}

}  // namespace flare
