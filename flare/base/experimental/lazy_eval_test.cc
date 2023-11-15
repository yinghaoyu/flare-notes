#include "flare/base/experimental/lazy_eval.h"

#include <string>

#include "gtest/gtest.h"

using namespace std::literals;

namespace flare::experimental {

TEST(LazyEval, All) {
  LazyEval<std::string> val;
  ASSERT_FALSE(val);

  val = [] { return "asdf"s; };
  ASSERT_TRUE(val);
  EXPECT_FALSE(val.IsEvaluated());
  EXPECT_EQ("asdf", val.Evaluate());
  EXPECT_TRUE(val.IsEvaluated());
  EXPECT_EQ("asdf", val.Evaluate());
  EXPECT_EQ("asdf", val.Evaluate());
  EXPECT_EQ("asdf", val.Get());

  val = "asdfg";
  ASSERT_TRUE(val);
  EXPECT_EQ("asdfg", val.Evaluate());
  EXPECT_EQ("asdfg", val.Evaluate());
}

}  // namespace flare::experimental
