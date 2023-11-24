#include "flare/base/encoding/base64.h"

#include <string>

#include "gtest/gtest.h"

#include "flare/base/random.h"

using namespace std::literals;

namespace flare {

static constexpr auto kText = ".<>@????????";
static constexpr auto kBase64Text = "Ljw+QD8/Pz8/Pz8/";
static constexpr auto kText2 = ".<>@???????";
static constexpr auto kBase64Text2 = "Ljw+QD8/Pz8/Pz8=";

std::string RandomString() {
  std::string result(Random(100000), 0);
  for (auto&& e : result) {
    e = Random(255);
  }
  return result;
}

TEST(Base64, Default) {
  EXPECT_EQ(kBase64Text, EncodeBase64(kText));
  auto decoded = DecodeBase64(kBase64Text);
  ASSERT_TRUE(decoded);
  EXPECT_EQ(kText, *decoded);
  EXPECT_FALSE(DecodeBase64("some-invalid-base64-encoded!!"));
}

TEST(Base64, Padding) {
  EXPECT_EQ(kBase64Text2, EncodeBase64(kText2));

  auto decoded = DecodeBase64(kBase64Text2);
  ASSERT_TRUE(decoded);
  EXPECT_EQ(kText2, *decoded);
}

TEST(Base64, Empty) {
  EXPECT_EQ("", EncodeBase64(""));
  auto decoded = DecodeBase64("");
  ASSERT_TRUE(decoded);
  EXPECT_EQ("", *decoded);
}

TEST(Base64, Torture) {
  for (int i = 0; i != 1000; ++i) {
    auto x = RandomString();
    auto encoded = EncodeBase64(x);
    auto decoded = DecodeBase64(encoded);
    ASSERT_TRUE(decoded);
    EXPECT_EQ(x, *decoded);
  }
}

}  // namespace flare
