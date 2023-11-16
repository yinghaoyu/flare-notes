#include <sys/resource.h>
#include <sys/time.h>

#include "gtest/gtest.h"

#include "flare/base/logging.h"
#include "flare/init/override_flag.h"
#include "flare/testing/main.h"

FLARE_OVERRIDE_FLAG(flare_override_rlimit_core, 0);
FLARE_OVERRIDE_FLAG(flare_override_rlimit_core_only_if_less, false);

namespace flare::init {

TEST(OverrideFlag, All) {
  rlimit current;
  FLARE_PCHECK(getrlimit(RLIMIT_CORE, &current) == 0);
  ASSERT_EQ(0, current.rlim_cur);
}

}  // namespace flare::init

FLARE_TEST_MAIN
