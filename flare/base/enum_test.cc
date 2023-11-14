#include "flare/base/enum.h"

#include <cstddef>

#include <gtest/gtest.h>

namespace ns1 {

enum class Byte : int {};

FLARE_DEFINE_ENUM_BITMASK_OPS(Byte);

}  // namespace ns1

namespace ns2 {

// This should interfere with operator&(ns1::Byte, ns1::Byte);
template <class T, class U>
int operator&(T&&, U&&) {
  return 0;
}

TEST(Enum, UnderlyingValue) {
  ns1::Byte b{10};
  ASSERT_EQ(10, flare::underlying_value(b));
}

TEST(Enum, OperatorOr) {
  ns1::Byte a{1}, b{2};
  ASSERT_EQ(3, flare::underlying_value(a | b));
  a |= b;
  ASSERT_EQ(3, flare::underlying_value(a));
}

TEST(Enum, OperatorAnd) {
  ns1::Byte a{3}, b{2};
  ASSERT_EQ(2, flare::underlying_value(a & b));
  a &= b;
  ASSERT_EQ(2, flare::underlying_value(a));
}

TEST(Enum, OperatorXor) {
  ns1::Byte a{2}, b{2};
  ASSERT_EQ(0, flare::underlying_value(a ^ b));
  a ^= b;
  ASSERT_EQ(0, flare::underlying_value(a));
}

}  // namespace ns2
