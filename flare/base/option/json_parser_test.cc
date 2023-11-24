#include "flare/base/option/json_parser.h"

#include "gtest/gtest.h"

namespace flare::option {

TEST(JsonParser, Ok) {
  auto parsed = JsonParser().TryParse(R"({"key":"value"})");
  ASSERT_TRUE(parsed);
  EXPECT_EQ("value", (*parsed)["key"].asString());
}

TEST(JsonParser, Error) {
  EXPECT_FALSE(JsonParser().TryParse(R"({"key":"value})"));
}

}  // namespace flare::option
