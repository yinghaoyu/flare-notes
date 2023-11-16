#include "flare/base/thread/attribute.h"

#include <pthread.h>

#include <chrono>
#include <thread>
#include <vector>

#include "gtest/gtest.h"

#include "flare/base/internal/cpu.h"
#include "flare/base/logging.h"
#include "flare/base/random.h"

using namespace std::literals;

namespace flare {

TEST(Thread, SetCurrentAffinity) {
  auto nprocs = internal::GetNumberOfProcessorsConfigured();
  for (int j = 0; j != 1000; ++j) {
    for (int i = 0; i != nprocs; ++i) {
      if (internal::IsProcessorAccessible(i)) {
        SetCurrentThreadAffinity(std::vector<int>{i});
        if (Random(100) < 10) {
          std::this_thread::sleep_for(1ms);
        }
        ASSERT_EQ(i, internal::GetCurrentProcessorId());
      }
    }
  }
}

TEST(Thread, SetCurrentName) {
  SetCurrentThreadName("asdf");
  char buffer[30] = {};
  pthread_getname_np(pthread_self(), buffer, sizeof(buffer));
  ASSERT_EQ("asdf", std::string(buffer));
}

}  // namespace flare
