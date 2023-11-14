#include "flare/base/logging.h"

#include <thread>
#include <vector>

#include "gtest/gtest.h"

#include "flare/base/chrono.h"

namespace foreign_ns {

struct AwesomeLogSink : public google::LogSink {
  void send(google::LogSeverity severity, const char* full_filename,
            const char* base_filename, int line, const struct ::tm* tm_time,
            const char* message, size_t message_len) override {
    ++count;
  }
  std::atomic<int> count{};
};

TEST(Logging, LogEverySecond) {
  AwesomeLogSink sink;
  google::AddLogSink(&sink);

  std::vector<std::thread> ts(100);
  for (auto&& t : ts) {
    t = std::thread([] {
      auto start = flare::ReadSteadyClock();
      while (start + std::chrono::seconds(10) > flare::ReadSteadyClock()) {
        FLARE_LOG_WARNING_EVERY_SECOND("Some warning.");
      }
    });
  }
  for (auto&& t : ts) {
    t.join();
  }
  google::RemoveLogSink(&sink);
  ASSERT_NEAR(11 /* Plus the initial one. */, sink.count, 1);
}

}  // namespace foreign_ns
