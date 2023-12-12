#include "flare/io/detail/watchdog.h"

#include <chrono>
#include <thread>

#include "gflags/gflags.h"
#include "gtest/gtest.h"

#include "flare/io/event_loop.h"
#include "flare/testing/main.h"

using namespace std::literals;

DECLARE_int32(flare_watchdog_check_interval);
DECLARE_int32(flare_watchdog_maximum_tolerable_delay);

// No, gtest does not handle death in other threads well.
TEST(DISABLED_WatchdogDeathTest, Unresponsive) {
  FLAGS_flare_watchdog_check_interval = 1000;
  FLAGS_flare_watchdog_maximum_tolerable_delay = 100;
  flare::GetGlobalEventLoop(0)->AddTask(
      [] { std::this_thread::sleep_for(10s); });
  ASSERT_DEATH(std::this_thread::sleep_for(2s),
               "The event loop is likely unresponsive");
}

TEST(WatchdogTest, Alive) {
  auto start = std::chrono::system_clock::now();
  while (std::chrono::system_clock::now() - start < 2s) {
    std::atomic<int> x = 0;
    flare::GetGlobalEventLoop(0)->AddTask([&] { x = 1; });
    while (x == 0) {
      // NOTHING.
    }
    ASSERT_EQ(1, x.load());
  }
}

TEST(WatchdogTest, UnresponsiveNoUseAfterFree) {
  flare::GetGlobalEventLoop(0)->AddTask(
      [&] { std::this_thread::sleep_for(2s); });
  std::this_thread::sleep_for(2500ms);
}

int main(int argc, char** argv) {
  FLAGS_flare_watchdog_check_interval = 1000;
  FLAGS_flare_watchdog_maximum_tolerable_delay = 1000;
  return ::flare::testing::InitAndRunAllTests(&argc, argv);
}
