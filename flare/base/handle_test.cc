#include "flare/base/handle.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "gtest/gtest.h"

using namespace std::literals;

namespace flare {

TEST(Handle, InvalidValues) {
  Handle h(0), h2(-1);
  ASSERT_FALSE(h);
  ASSERT_FALSE(h2);
}

TEST(Handle, ValidHandle) {
  int fd = 0;
  {
    Handle h(open("/dev/null", O_WRONLY));
    fd = h.Get();
    ASSERT_EQ(1, write(fd, "1", 1));
    ASSERT_TRUE(h);
  }
  ASSERT_EQ(-1, write(fd, "1", 1));
}

}  // namespace flare
