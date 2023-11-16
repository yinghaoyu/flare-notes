#include "flare/base/internal/cpu.h"

#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace flare::internal {

TEST(TryParseProcesserList, All) {
  EXPECT_FALSE(TryParseProcesserList("-12345678"));
  EXPECT_FALSE(TryParseProcesserList("a-b"));
  EXPECT_FALSE(TryParseProcesserList("1-a"));
  EXPECT_FALSE(TryParseProcesserList("2-1"));
  auto opt = TryParseProcesserList("1-3,4-4,6,-1");
  ASSERT_TRUE(opt);
  EXPECT_THAT(*opt, ::testing::UnorderedElementsAre(
                        1, 2, 3, 4, 6, GetNumberOfProcessorsConfigured() - 1));
}

}  // namespace flare::internal
