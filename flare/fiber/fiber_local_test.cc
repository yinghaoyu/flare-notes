#include "flare/fiber/fiber_local.h"

#include <atomic>
#include <thread>
#include <vector>

#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

#include "flare/base/random.h"
#include "flare/fiber/detail/testing.h"
#include "flare/fiber/fiber.h"
#include "flare/fiber/this_fiber.h"

using namespace std::literals;

namespace flare {

TEST(FiberLocal, All) {
  for (int k = 0; k != 10; ++k) {
    fiber::testing::RunAsFiber([] {
      static FiberLocal<int> fls;
      static FiberLocal<int> fls2;
      static FiberLocal<double> fls3;
      static FiberLocal<std::vector<int>> fls4;
      constexpr auto N = 10000;

      std::atomic<std::size_t> run{};
      std::vector<Fiber> fs(N);

      for (int i = 0; i != N; ++i) {
        fs[i] = Fiber([i, &run] {
          *fls = i;
          *fls2 = i * 2;
          *fls3 = i + 3;
          fls4->push_back(123);
          fls4->push_back(456);
          while (Random(20) > 1) {
            this_fiber::SleepFor(Random(1000) * 1us);
            ASSERT_EQ(i, *fls);
            ASSERT_EQ(i * 2, *fls2);
            ASSERT_EQ(i + 3, *fls3);
            ASSERT_THAT(*fls4, ::testing::ElementsAre(123, 456));
          }
          ++run;
        });
      }

      for (auto&& e : fs) {
        ASSERT_TRUE(e.joinable());
        e.join();
      }

      ASSERT_EQ(N, run);
    });
  }
}

}  // namespace flare
