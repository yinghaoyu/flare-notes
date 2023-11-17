#include "flare/base/thread/spinlock.h"

#include <thread>

#include "gtest/gtest.h"

#include "flare/base/thread/latch.h"

namespace flare {

std::uint64_t counter{};

TEST(Spinlock, All) {
  constexpr auto T = 100;
  constexpr auto N = 100000;
  std::thread ts[100];
  Latch latch(1);
  Spinlock splk;

  for (auto&& t : ts) {
    t = std::thread([&] {
      latch.wait();
      for (int i = 0; i != N; ++i) {
        std::scoped_lock lk(splk);
        ++counter;
      }
    });
  }
  latch.count_down();
  for (auto&& t : ts) {
    t.join();
  }
  ASSERT_EQ(T * N, counter);
}

}  // namespace flare
