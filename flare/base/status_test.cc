#include "flare/base/status.h"

#include "gtest/gtest.h"

namespace flare {

TEST(Status, Success) {
  Status st;
  ASSERT_TRUE(st.ok());
  ASSERT_EQ(0, st.code());
  ASSERT_EQ("", st.message());
  Status st2 = st;
  ASSERT_TRUE(st2.ok());
  ASSERT_EQ(0, st2.code());
  ASSERT_EQ("", st2.message());
}

TEST(Status, Failure) {
  Status st(1, "err");
  ASSERT_FALSE(st.ok());
  ASSERT_EQ(1, st.code());
  ASSERT_EQ("err", st.message());
  Status st2 = st;
  ASSERT_FALSE(st2.ok());
  ASSERT_EQ(1, st2.code());
  ASSERT_EQ("err", st2.message());
}

enum class SomeEnum { Enum1 = 2 };

TEST(Status, FromEnum) {
  Status st(SomeEnum::Enum1);
  EXPECT_EQ(2, st.code());
}

}  // namespace flare
