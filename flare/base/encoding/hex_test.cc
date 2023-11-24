#include "flare/base/encoding/hex.h"

#include "gtest/gtest.h"

namespace flare {

const char Hex123456FF[] = "\x12\x34\x56\xFF";

TEST(Hex, Default) {
  EXPECT_EQ("123456ff", EncodeHex(Hex123456FF));
  EXPECT_EQ("123456FF", EncodeHex(Hex123456FF, true));
  EXPECT_EQ(Hex123456FF, DecodeHex("123456ff"));
  EXPECT_EQ(Hex123456FF, DecodeHex("123456FF"));
}

}  // namespace flare
