#include "flare/base/chrono.h"

#include <chrono>
#include <thread>

#include <gtest/gtest.h>

using namespace std::literals;

namespace flare {

TEST(SystemClock, Compare) {
  auto diff = (ReadSystemClock() - std::chrono::system_clock::now()) / 1ms;
  ASSERT_NEAR(diff, 0, 2);
}

TEST(SteadyClock, Compare) {
  auto diff = (ReadSteadyClock() - std::chrono::steady_clock::now()) / 1ms;
  ASSERT_NEAR(diff, 0, 2);
}

TEST(CoarseSystemClock, Compare) {
  auto diff =
      (ReadCoarseSystemClock() - std::chrono::system_clock::now()) / 1ms;
  ASSERT_NEAR(diff, 0, 10);
}

TEST(CoarseSteadyClock, Compare) {
  auto diff =
      (ReadCoarseSteadyClock() - std::chrono::steady_clock::now()) / 1ms;
  ASSERT_NEAR(diff, 0, 10);
}

}  // namespace flare
