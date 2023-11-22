#include "flare/fiber/alternatives.h"

#include <errno.h>

#include <iostream>
#include <thread>

#include "gtest/gtest.h"

#include "flare/fiber/detail/testing.h"
#include "flare/fiber/this_fiber.h"

namespace flare::fiber {

TEST(LastError, All) {
  fiber::testing::RunAsFiber([&] {
    auto was = GetCurrentThreadId();
    SetLastError(9999);
    EXPECT_EQ(9999, errno);
    EXPECT_EQ(9999, GetLastError());
    while (was == GetCurrentThreadId()) {
      this_fiber::Yield();
    }
    EXPECT_NE(9999, GetLastError());
    std::cout << "errno = " << errno << std::endl;  // May or may not be 9999.
  });
}

TEST(ThreadId, All) {
  fiber::testing::RunAsFiber(
      [&] { EXPECT_EQ(GetCurrentThreadId(), std::this_thread::get_id()); });
}

}  // namespace flare::fiber
