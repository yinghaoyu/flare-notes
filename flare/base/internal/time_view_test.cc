#include "flare/base/internal/time_view.h"

#include "gtest/gtest.h"

using namespace std::literals;

namespace flare::internal {

template <class Expecting>
auto GetTime(TimeView<Expecting> view) {
  return view.Get();
}

#define TIME_NEAR(x, y, diff) ASSERT_NEAR(((x) - (y)) / 1ns, 0, (diff) / 1ns)

TEST(TimeView, TimePoint) {
  TIME_NEAR(GetTime<std::chrono::steady_clock::time_point>(
                std::chrono::system_clock::now() + 1s),
            ReadSteadyClock() + 1s, 100us);
  TIME_NEAR(GetTime<std::chrono::steady_clock::time_point>(
                std::chrono::steady_clock::now() + 1s),
            ReadSteadyClock() + 1s, 100us);
  TIME_NEAR(
      // Do NOT remove the plus sign here.
      GetTime<std::chrono::steady_clock::time_point>(+1s),
      ReadSteadyClock() + 1s, 100us);
  TIME_NEAR(
      GetTime<std::chrono::steady_clock::time_point>(ReadSteadyClock() + 1s),
      ReadSteadyClock() + 1s, 100us);
  TIME_NEAR(
      GetTime<std::chrono::steady_clock::time_point>(ReadSystemClock() + 1s),
      ReadSteadyClock() + 1s, 100us);
}

TEST(TimeView, Duration) {
  TIME_NEAR(
      +1s,
      GetTime<std::chrono::nanoseconds>(std::chrono::system_clock::now() + 1s),
      100us);
  TIME_NEAR(
      +1s,
      GetTime<std::chrono::nanoseconds>(std::chrono::steady_clock::now() + 1s),
      100us);
  TIME_NEAR(+1s, GetTime<std::chrono::nanoseconds>(+1s), 100us);
  TIME_NEAR(+1s, GetTime<std::chrono::nanoseconds>(ReadSteadyClock() + 1s),
            100us);
  TIME_NEAR(+1s, GetTime<std::chrono::nanoseconds>(ReadSystemClock() + 1s),
            100us);
}

}  // namespace flare::internal
