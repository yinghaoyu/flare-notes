#include "flare/base/option/key.h"

#include "gtest/gtest.h"

namespace flare::option {

TEST(Key, MultiKey) {
  MultiKey key(DynamicKey("name"), FixedKey("fixed"));
  SetDynamicKey("name", "dynamic");

  ASSERT_EQ("dynamic", key.GetKeys()[0].Get());
  ASSERT_EQ("fixed", key.GetKeys()[1].Get());
  ASSERT_EQ("dynamic/fixed", key.ToString());
}

TEST(Key, FromStr) {
  Key key("asdf");
  ASSERT_EQ("asdf", key.Get());
}

TEST(Key, FixedKey) {
  Key key(FixedKey("asdf"));
  ASSERT_EQ("asdf", key.Get());
}

TEST(Key, DynamicKey) {
  Key key(DynamicKey("key name"));
  SetDynamicKey("key name", "value");
  ASSERT_EQ("value", key.Get());
}

std::string refee;

TEST(Key, ReferencingKey) {
  refee = "abcd";
  Key key{ReferencingKey(refee)};
  ASSERT_EQ("abcd", key.Get());
}

}  // namespace flare::option
