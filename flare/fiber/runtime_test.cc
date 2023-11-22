#include "flare/fiber/runtime.h"

#include <set>

#include "gflags/gflags.h"
#include "gtest/gtest.h"

#include "flare/base/internal/cpu.h"
#include "flare/base/thread/attribute.h"
#include "flare/base/thread/latch.h"
#include "flare/fiber/fiber.h"

DECLARE_string(flare_fiber_worker_inaccessible_cpus);

namespace flare::fiber {

TEST(Runtime, All) {
  google::FlagSaver _;
  FLAGS_flare_fiber_worker_inaccessible_cpus = "-1";

  StartRuntime();
  Latch latch(1);

  StartFiberFromPthread([&] {
    auto affinity = GetCurrentThreadAffinity();
    std::set<int> using_cpus{affinity.begin(), affinity.end()};

    // The last CPU shouldn't be usable to us.
    EXPECT_EQ(0, using_cpus.count(
                     flare::internal::GetNumberOfProcessorsConfigured() - 1));
    latch.count_down();
  });
  latch.wait();
  TerminateRuntime();
}

}  // namespace flare::fiber
