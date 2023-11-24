#include "flare/base/crypto/md5.h"

#include "gtest/gtest.h"

#include "flare/base/buffer.h"
#include "flare/base/encoding.h"

using namespace std::literals;

namespace flare {

TEST(Md5, All) {
  auto result = "827ccb0eea8a706c4c34a16891f84e7b";
  EXPECT_EQ(result, EncodeHex(Md5(CreateBufferSlow("12345"))));
  EXPECT_EQ(result, EncodeHex(Md5("12345")));
  EXPECT_EQ(result, EncodeHex(Md5({"123", "45"})));
}

TEST(HmacMd5, All) {
  auto result = "8f8afda40668a73d8dcbee1508559c91";
  EXPECT_EQ(result, EncodeHex(HmacMd5("key", CreateBufferSlow("12345"))));
  EXPECT_EQ(result, EncodeHex(HmacMd5("key", "12345")));
  EXPECT_EQ(result, EncodeHex(HmacMd5("key", {"123", "45"})));
}

}  // namespace flare
