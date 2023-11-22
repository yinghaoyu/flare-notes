#include "flare/fiber/shared_mutex.h"

#include <atomic>
#include <thread>
#include <vector>

#include "gtest/gtest.h"

#include "flare/base/chrono.h"
#include "flare/base/random.h"
#include "flare/fiber/detail/testing.h"
#include "flare/fiber/fiber.h"

using namespace std::literals;

namespace flare::fiber {

int counter1, counter2;

TEST(SharedMutex, Simple) {
  testing::RunAsFiber([] {
    SharedMutex rwlock;
    for (int i = 0; i != 100000; ++i) {
      std::shared_lock _(rwlock);
      // NOTHING.
    }
    for (int i = 0; i != 100000; ++i) {
      std::scoped_lock _(rwlock);
      // NOTHING.
    }
    for (int i = 0; i != 100000; ++i) {
      std::shared_lock _(rwlock);
      // NOTHING.
    }
  });
}

TEST(SharedMutex, All) {
  testing::RunAsFiber([] {
    SharedMutex rwlock;
    std::vector<Fiber> fibers;
    std::atomic<int> try_read_lock{}, try_write_lock{};

    for (int i = 0; i != 10000; ++i) {
      fibers.emplace_back([&] {
        auto start = ReadCoarseSteadyClock();
        while (ReadCoarseSteadyClock() < start + 5s) {
          auto op = Random(100);
          if (op < 90) {  // Read.
            std::shared_lock _(rwlock);
            EXPECT_EQ(counter1, counter2);
          } else if (op < 95) {
            std::scoped_lock _(rwlock);
            ++counter1;
            ++counter2;
            EXPECT_EQ(counter1, counter2);
          } else if (op < 99) {
            std::shared_lock lk(rwlock, std::try_to_lock);
            if (lk) {
              ++try_read_lock;
              EXPECT_EQ(counter1, counter2);
            }
          } else {
            std::unique_lock lk(rwlock, std::try_to_lock);
            if (lk) {
              ++try_write_lock;
              ++counter1;
              ++counter2;
              EXPECT_EQ(counter1, counter2);
            }
          }
        }
      });
    }
    for (auto&& e : fibers) {
      e.join();
    }
    FLARE_LOG_ERROR(
        "Try read lock succeeded {} times, try write lock succeeded {} times.",
        try_read_lock.load(), try_write_lock.load());
  });
}

}  // namespace flare::fiber
