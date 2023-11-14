#include "flare/base/thread/latch.h"

#include <atomic>
#include <chrono>
#include <memory>
#include <thread>

#include "gtest/gtest.h"

#include "flare/base/chrono.h"

using namespace std::literals;

namespace flare {

std::atomic<bool> exiting{false};

void RunTest() {
  std::size_t local_count = 0, remote_count = 0;
  while (!exiting) {
    auto called = std::make_shared<std::atomic<bool>>(false);
    std::this_thread::yield();  // Wait for thread pool to start.
    Latch l(1);
    auto t = std::thread([&] {
      if (!called->exchange(true)) {
        std::this_thread::yield();  // Something costly.
        l.count_down();
        ++remote_count;
      }
    });
    std::this_thread::yield();  // Something costly.
    if (!called->exchange(true)) {
      l.count_down();
      ++local_count;
    }
    l.wait();
    t.join();
  }
  std::cout << local_count << " " << remote_count << std::endl;
}

TEST(Latch, Torture) {
  std::thread ts[10];
  for (auto&& t : ts) {
    t = std::thread(RunTest);
  }
  std::this_thread::sleep_for(10s);
  exiting = true;
  for (auto&& t : ts) {
    t.join();
  }
}

TEST(Latch, CountDownTwo) {
  Latch l(2);
  l.arrive_and_wait(2);
  ASSERT_TRUE(1);
}

TEST(Latch, WaitFor) {
  Latch l(1);
  ASSERT_FALSE(l.wait_for(100ms));
  l.count_down();
  ASSERT_TRUE(l.wait_for(0ms));
}

TEST(Latch, WaitUntil) {
  Latch l(1);
  ASSERT_FALSE(l.wait_until(ReadSteadyClock() + 100ms));
  l.count_down();
  ASSERT_TRUE(l.wait_until(ReadSteadyClock()));
}

}  // namespace flare
