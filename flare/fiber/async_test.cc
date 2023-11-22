#include "flare/fiber/async.h"

#include "gtest/gtest.h"

#include "flare/base/future.h"
#include "flare/fiber/alternatives.h"
#include "flare/fiber/detail/testing.h"
#include "flare/fiber/future.h"
#include "flare/fiber/this_fiber.h"

using namespace std::literals;

namespace flare::fiber {

TEST(Async, Execute) {
  testing::RunAsFiber([] {
    for (int i = 0; i != 10000; ++i) {
      int rc = 0;
      auto tid = GetCurrentThreadId();
      auto ff = Async(Launch::Dispatch, [&] {
        rc = 1;
        ASSERT_EQ(tid, GetCurrentThreadId());
      });
      fiber::BlockingGet(&ff);
      ASSERT_EQ(1, rc);
      Future<int> f = Async([&] {
        // Which thread is running this fiber is unknown. No assertion here.
        return 5;
      });
      this_fiber::Yield();
      ASSERT_EQ(5, fiber::BlockingGet(&f));
    }
  });
}

}  // namespace flare::fiber
