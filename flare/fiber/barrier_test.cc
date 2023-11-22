#include "flare/fiber/barrier.h"

#include "gtest/gtest.h"

#include "flare/fiber/detail/testing.h"

namespace flare::fiber {

TEST(Barrier, ArriveAndWait) {
  testing::RunAsFiber([] {
    bool i = false;
    Barrier b(1, [&] { i = true; });
    b.arrive_and_wait();
    ASSERT_TRUE(i);
    i = false;
    b.arrive_and_wait();
    ASSERT_TRUE(i);
  });
}

TEST(Barrier, ArriveAndDrop) {
  testing::RunAsFiber([] {
    int n = 0;
    Barrier b(1, [&n] { ++n; });
    b.arrive_and_drop();
    ASSERT_EQ(n, 1);
  });
}

// Same as https://en.cppreference.com/w/cpp/thread/barrier example
TEST(Barrier, Simple) {
  testing::RunAsFiber([] {
    const auto workers = {"anil", "busara", "carl"};

    auto on_completion = []() noexcept {
      // locking not needed here
      static auto phase =
          "... done\n"
          "Cleaning up...\n";
      std::cout << phase;
      phase = "... done\n";
    };
    Barrier sync_point(workers.size(), on_completion);

    auto work = [&](std::string name) {
      std::string product = "  " + name + " worked\n";
      std::cout << product;  // ok, op<< call is atomic
      sync_point.arrive_and_wait();

      product = "  " + name + " cleaned\n";
      std::cout << product;
      sync_point.arrive_and_wait();
    };

    std::cout << "Starting...\n";
    std::vector<Fiber> fibers;
    for (auto const& worker : workers) {
      fibers.emplace_back(work, worker);
    }
    for (auto& fiber : fibers) {
      fiber.join();
    }
  });
}

}  // namespace flare::fiber
