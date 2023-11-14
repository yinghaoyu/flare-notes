#include "flare/base/delayed_init.h"

#include <gtest/gtest.h>

using namespace std::literals;

namespace flare {

bool initialized = false;

struct DefaultConstructibleInitialization {
  DefaultConstructibleInitialization() { initialized = true; }
};

struct InitializeCtorArgument {
  explicit InitializeCtorArgument(bool* ptr) { *ptr = true; }
};

TEST(DelayedInit, DefaultConstructible) {
  DelayedInit<DefaultConstructibleInitialization> dc;
  ASSERT_FALSE(initialized);
  dc.Init();
  ASSERT_TRUE(initialized);
}

TEST(DelayedInit, InitializeCtorArgument) {
  bool f = false;
  DelayedInit<InitializeCtorArgument> ica;
  ASSERT_FALSE(f);
  ica.Init(&f);
  ASSERT_TRUE(f);
}

}  // namespace flare
