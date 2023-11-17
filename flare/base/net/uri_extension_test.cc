#include "flare/base/net/uri.h"

#include "gtest/gtest.h"

#include "flare/base/string.h"
#include "flare/init/override_flag.h"
#include "flare/testing/main.h"

FLARE_OVERRIDE_FLAG(flare_extension_non_conformant_uri_for_gdt, true);

namespace flare {

TEST(Uri, NonConformantQuery) {
  auto parsed = TryParse<Uri>("http://x.y.z/?a=a&b={'k':'v'}");
  ASSERT_TRUE(parsed);
  EXPECT_EQ("a=a&b={'k':'v'}", parsed->query());
}

}  // namespace flare

FLARE_TEST_MAIN
