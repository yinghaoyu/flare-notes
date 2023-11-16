#include "flare/base/internal/background_task_host.h"

#include "gtest/gtest.h"

#include "flare/base/thread/latch.h"

namespace flare::internal {

TEST(BackgroundTaskHost, All) {
  int x = 1;
  Latch latch(1);
  BackgroundTaskHost::Instance()->Start();
  BackgroundTaskHost::Instance()->Queue([&] {
    x = 2;
    latch.count_down();
  });
  latch.wait();
  ASSERT_EQ(2, x);
  BackgroundTaskHost::Instance()->Stop();
  BackgroundTaskHost::Instance()->Join();
}

}  // namespace flare::internal
