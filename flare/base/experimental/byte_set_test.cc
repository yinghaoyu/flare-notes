#include "flare/base/experimental/byte_set.h"

#include "gtest/gtest.h"

namespace flare::experimental {

constexpr ByteSet empty;
constexpr ByteSet digits("0123456789");
constexpr ByteSet uppers("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
constexpr ByteSet lowers("abcdefghijklmnopqrstuvwxyz");
constexpr ByteSet alphas(uppers | lowers);
constexpr ByteSet alnums(alphas | digits);

TEST(ByteSet, Empty) {
  for (int i = 0; i < UCHAR_MAX; ++i) {
    EXPECT_FALSE(empty.contains(i));
  }
}

TEST(ByteSet, InsertAndFind) {
  ByteSet bs;
  EXPECT_FALSE(bs.contains('A'));
  bs.insert('A');
  EXPECT_TRUE(bs.contains('A'));
  for (int i = 0; i < UCHAR_MAX; ++i) {
    EXPECT_EQ(i >= 'A' && i <= 'Z', uppers.contains(i));
    EXPECT_EQ(i >= '0' && i <= '9', digits.contains(i));
  }
}

TEST(ByteSet, CharPtr) {
  const char* s = "ABCD";
  ByteSet bs(s);
  const char* const cs = "ABCD";
  ByteSet cbs(cs);
  EXPECT_EQ(bs, cbs);
}

TEST(ByteSet, Or) {
  EXPECT_EQ(alphas, uppers | lowers);
  EXPECT_EQ(alnums, alphas | digits);
}

TEST(ByteSet, And) {
  EXPECT_EQ(empty, uppers & lowers);
  EXPECT_EQ(alnums, alphas | digits);
}

TEST(ByteSet, OrEq) {
  ByteSet bs(lowers);
  bs |= uppers;
  EXPECT_EQ(alphas, bs);
}

TEST(ByteSet, AndEq) {
  ByteSet bs(alnums);
  bs &= digits;
  EXPECT_EQ(digits, bs);
}

}  // namespace flare::experimental
