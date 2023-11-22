#include "flare/base/thread/semaphore.h"

#include <atomic>
#include <thread>
#include <vector>

#include "gtest/gtest.h"

namespace flare {

std::atomic<int> counter{};

TEST(Semaphore, All) {
  for (int j = 0; j != 100; ++j) {
    CountingSemaphore semaphore(100);
    std::vector<std::thread> ts;

    for (int i = 0; i != 10000; ++i) {
      ts.emplace_back([&] {
        semaphore.acquire();
        ++counter;
        EXPECT_LE(counter, 100);
        --counter;
        semaphore.release();
      });
    }

    for (auto&& e : ts) {
      e.join();
    }
  }
}

}  // namespace flare
