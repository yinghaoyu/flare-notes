#include "flare/base/thread/out_of_duty_callback.h"

#include <chrono>
#include <thread>

#include "gtest/gtest.h"

using namespace std::literals;

namespace flare {

TEST(OutOfDutyCallback, All) {
  int x = 0;

  auto id = SetThreadOutOfDutyCallback([&] { ++x; }, 1ms);

  std::this_thread::sleep_for(100ms);
  std::thread([] { NotifyThreadOutOfDutyCallbacks(); }).join();
  EXPECT_EQ(1, x);  // Every Thread Matters.

  NotifyThreadOutOfDutyCallbacks();
  EXPECT_EQ(2, x);  // Callback fired.
  NotifyThreadOutOfDutyCallbacks();
  EXPECT_EQ(2, x);  // Rate-throttled.

  std::this_thread::sleep_for(100ms);
  NotifyThreadOutOfDutyCallbacks();
  EXPECT_EQ(3, x);  // Fired again.

  DeleteThreadOutOfDutyCallback(id);
  std::this_thread::sleep_for(100ms);
  NotifyThreadOutOfDutyCallbacks();
  EXPECT_EQ(3, x);  // Our callback has been removed, nothing changed.
}

}  // namespace flare
