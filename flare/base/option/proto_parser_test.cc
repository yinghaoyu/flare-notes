#include "flare/base/option/proto_parser.h"

#include "gtest/gtest.h"

#include "flare/testing/message.pb.h"

namespace flare::option {

TEST(ProtoTextFormatParser, Ok) {
  auto parsed = ProtoTextFormatParser<flare::testing::One>().TryParse(
      R"(str:"str",integer:1)");
  ASSERT_TRUE(parsed);
  EXPECT_EQ("str", parsed->str());
  EXPECT_EQ(1, parsed->integer());
}

TEST(ProtoTextFormatParser, Error) {
  EXPECT_FALSE(ProtoTextFormatParser<flare::testing::One>().TryParse("1234"));
}

}  // namespace flare::option
