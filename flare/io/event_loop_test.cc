#include "flare/io/event_loop.h"

#include <chrono>

#include "gtest/gtest.h"

#include "flare/testing/main.h"

using namespace std::literals;

namespace flare {

TEST(EventLoop, Task) {
  std::atomic<int> x = 0;
  GetGlobalEventLoop(0)->AddTask([&] { x = 1; });
  while (x == 0) {
  }
  ASSERT_EQ(1, x);
}

}  // namespace flare

FLARE_TEST_MAIN
