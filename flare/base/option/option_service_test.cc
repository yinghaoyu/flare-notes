#include "flare/base/option/option_service.h"

#include <iostream>

#include "gflags/gflags.h"
#include "gtest/gtest.h"

#include "flare/base/option.h"

DEFINE_int32(int_test, 1, "");
DEFINE_int64(int64_test, 2, "");
DEFINE_string(string_test, "abc", "");

namespace flare::option {

GflagsOptions<int> opt_int("int_test");
GflagsOptions<std::int64_t> opt_int64("int64_test");
GflagsOptions<std::string> opt_str("string_test");

TEST(OptionService, Dump) {
  InitializeOptions();
  auto options = OptionService::Instance()->Dump();

  std::cout << options.toStyledString() << std::endl;
  ASSERT_EQ(3, options["gflags"].size());
  ASSERT_EQ(1, options["gflags"]["int_test"].asInt());
  ASSERT_EQ(2, options["gflags"]["int64_test"].asInt64());
  ASSERT_EQ("abc", options["gflags"]["string_test"].asString());

  FLAGS_int64_test = 5;
  SynchronizeOptions();
  options = OptionService::Instance()->Dump();
  ASSERT_EQ(5, options["gflags"]["int64_test"].asInt64());

  ShutdownOptions();
}

}  // namespace flare::option
