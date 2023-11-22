#include "flare/fiber/work_queue.h"

#include "gtest/gtest.h"

#include "flare/fiber/async.h"
#include "flare/fiber/detail/testing.h"
#include "flare/fiber/fiber.h"
#include "flare/fiber/future.h"
#include "flare/fiber/this_fiber.h"

using namespace std::literals;

namespace flare::fiber {

TEST(WorkQueue, All) {
  testing::RunAsFiber([] {
    int x = 0;  // Not `atomic`.
    auto s = std::chrono::steady_clock::now();
    WorkQueue wq;

    for (int i = 0; i != 10; ++i) {
      wq.Push([&] {
        ++x;
        this_fiber::SleepFor(100ms);
      });
    }
    EXPECT_LE(std::chrono::steady_clock::now() - s, 50ms);
    wq.Stop();
    wq.Join();
    EXPECT_GE(std::chrono::steady_clock::now() - s, 950ms);
    EXPECT_EQ(10, x);
  });
}

TEST(WorkQueue, RaceOnExit) {
  testing::RunAsFiber([] {
    std::atomic<std::size_t> finished = 0;
    constexpr auto kWorkers = 100;
    for (int i = 0; i != kWorkers; ++i) {
      Async([&finished] {
        for (int j = 0; j != 1000; ++j) {
          int x = 0;  // Not `atomic`.
          WorkQueue wq;

          for (int k = 0; k != 10; ++k) {
            wq.Push([&] { fiber::BlockingGet(Async([&] { ++x; })); });
          }
          wq.Stop();
          wq.Join();
          ASSERT_EQ(10, x);
        }
        ++finished;
      });
    }
    while (finished != kWorkers) {
      this_fiber::SleepFor(1ms);
    }
  });
}

}  // namespace flare::fiber
