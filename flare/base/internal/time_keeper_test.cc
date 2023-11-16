#include "flare/base/internal/time_keeper.h"

#include <vector>

#include "gtest/gtest.h"

#include "flare/base/chrono.h"
#include "flare/testing/main.h"

using namespace std::literals;

namespace flare::internal {

TEST(TimeKeeper, FastTimer) {
  int x = 0;
  auto timer_id = TimeKeeper::Instance()->AddTimer(
      ReadSteadyClock(), 10ms, [&](auto) { ++x; }, false);
  std::this_thread::sleep_for(1s);
  TimeKeeper::Instance()->KillTimer(timer_id);
  ASSERT_NEAR(x, 100, 10);
}

TEST(TimeKeeper, SlowTimer) {
  std::vector<std::uint64_t> timers;
  std::atomic<int> x{};
  for (int i = 0; i != 1000; ++i) {
    timers.push_back(TimeKeeper::Instance()->AddTimer(
        ReadSteadyClock(), 10ms, [&](auto) { ++x; }, true));
  }
  std::this_thread::sleep_for(1s);
  for (auto&& e : timers) {
    TimeKeeper::Instance()->KillTimer(e);
  }
  ASSERT_NEAR(x, 1000 * 100, 1000 * 10);
}

}  // namespace flare::internal

FLARE_TEST_MAIN
