#include "flare/base/internal/thread_pool.h"

#include "gtest/gtest.h"

using namespace std::literals;

namespace flare::internal {

TEST(ThreadPool, All) {
  for (int nice_value : {0, 10}) {
    std::atomic<int> ct{};
    ThreadPool tp(10, std::vector<int>(), nice_value);
    for (int i = 0; i != 1000; ++i) {
      tp.QueueJob([&] {
        for (int j = 0; j != 1000; ++j) {
          tp.QueueJob([&] { ++ct; });
        }
      });
    }
    while (ct != 1000 * 1000) {
      // NOTHING.
    }
    tp.Stop();
    tp.Join();
    ASSERT_EQ(1000 * 1000, ct);  // ...
  }
}

}  // namespace flare::internal
