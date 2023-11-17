#include "flare/base/object_pool.h"

#include <thread>
#include <vector>

#include "gtest/gtest.h"

using namespace std::literals;

namespace flare {

int alive = 0;

struct C {
  C() { ++alive; }
  ~C() { --alive; }
};

template <>
struct PoolTraits<C> {
  static constexpr auto kType = PoolType::Disabled;
};

namespace object_pool {

TEST(DisabledPool, All) {
  std::vector<PooledPtr<C>> ptrs;
  for (int i = 0; i != 1000; ++i) {
    ptrs.push_back(Get<C>());
  }
  ASSERT_EQ(1000, alive);
  ptrs.clear();
  ASSERT_EQ(0, alive);
  Get<C>();
  ASSERT_EQ(0, alive);
}

}  // namespace object_pool
}  // namespace flare
