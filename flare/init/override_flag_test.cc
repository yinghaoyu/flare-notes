#include "flare/init/override_flag.h"

#include "gflags/gflags.h"
#include "gtest/gtest.h"

#include "flare/testing/main.h"

DEFINE_bool(test, true, "");

FLARE_OVERRIDE_FLAG(test, false);

namespace flare::init {

TEST(OverrideFlag, All) { EXPECT_FALSE(FLAGS_test); }

}  // namespace flare::init

FLARE_TEST_MAIN
