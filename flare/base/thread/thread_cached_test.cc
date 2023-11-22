#include "flare/base/thread/thread_cached.h"

#include <string>
#include <thread>
#include <vector>

#include "gtest/gtest.h"

#include "flare/base/chrono.h"
#include "flare/base/random.h"
#include "flare/base/string.h"
#include "flare/base/thread/latch.h"

using namespace std::literals;

namespace flare {

TEST(ThreadCached, Basic) {
  ThreadCached<std::string> tc_str("123");
  for (int i = 0; i != 1000; ++i) {
    Latch latch1(1), latch2(1);
    auto t = std::thread([&] {
      ASSERT_EQ("123", tc_str.NonIdempotentGet());
      latch1.count_down();
      latch2.wait();
      ASSERT_EQ("456", tc_str.NonIdempotentGet());
    });
    latch1.wait();
    tc_str.Emplace("456");
    latch2.count_down();
    t.join();
    tc_str.Emplace("123");
  }

  // Were `thread_local` keyword used internally, the assertion below would
  // fail.
  ThreadCached<std::string> tc_str2("777");
  std::thread([&] { ASSERT_EQ("777", tc_str2.NonIdempotentGet()); }).join();
}

TEST(ThreadCached, Torture) {
  ThreadCached<std::string> str;
  std::vector<std::thread> ts;

  for (int i = 0; i != 100; ++i) {
    ts.push_back(std::thread([&, s = ReadSteadyClock()] {
      while (ReadSteadyClock() + 10s < s) {
        if (Random() % 1000 == 0) {
          str.Emplace(std::to_string(Random() % 33333));
        } else {
          auto opt = TryParse<int>(str.NonIdempotentGet());
          ASSERT_TRUE(opt);
          ASSERT_LT(*opt, 33333);
        }
      }
    }));
  }
  for (auto&& e : ts) {
    e.join();
  }
}

}  // namespace flare
