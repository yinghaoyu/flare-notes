#include "flare/fiber/semaphore.h"

#include <atomic>
#include <thread>
#include <vector>

#include "gtest/gtest.h"

#include "flare/fiber/detail/testing.h"
#include "flare/fiber/fiber.h"

namespace flare::fiber {

std::atomic<int> counter{};

TEST(Semaphore, All) {
  testing::RunAsFiber([] {
    std::vector<Fiber> fibers;
    CountingSemaphore semaphore(100);

    for (int i = 0; i != 10000; ++i) {
      fibers.emplace_back([&] {
        semaphore.acquire();
        ++counter;
        EXPECT_LE(counter, 100);
        --counter;
        semaphore.release();
      });
    }
    for (auto&& e : fibers) {
      e.join();
    }
  });
}

}  // namespace flare::fiber
