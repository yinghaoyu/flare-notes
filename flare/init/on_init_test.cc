#include "flare/init/on_init.h"

#include "gtest/gtest.h"

#include "flare/testing/main.h"

int v = 0;

FLARE_ON_INIT(0, [] { v = 1; })

namespace flare::init {

TEST(OnInit, All) { EXPECT_EQ(1, v); }

}  // namespace flare::init

FLARE_TEST_MAIN
