#include "flare/base/experimental/flyweight.h"

#include <string>
#include <unordered_map>

#include "gtest/gtest.h"

using namespace std::literals;

namespace flare::experimental {

TEST(Flyweight, All) {
  auto x = MakeFlyweight<std::string>("hello world");
  auto y = MakeFlyweight<std::string>(
      {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'});
  auto z = MakeFlyweight<std::string>("hi world");
  EXPECT_TRUE(x);
  EXPECT_EQ(x, y);
  EXPECT_EQ(*x, *y);
  EXPECT_NE(x, z);
  EXPECT_EQ("hello world", *x);
  EXPECT_EQ("hello world"s, x->c_str());

  std::unordered_map<Flyweight<std::string>, bool> m;
  m[x] = true;
  EXPECT_TRUE(m[x]);
  EXPECT_TRUE(m[y]);
  EXPECT_FALSE(m[z]);

  Flyweight<int> f;
  EXPECT_FALSE(f);
}

}  // namespace flare::experimental
