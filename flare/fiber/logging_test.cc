#include "flare/fiber/logging.h"

#include <string>

#include "gtest/gtest.h"

#include "flare/base/logging.h"
#include "flare/fiber/execution_context.h"
#include "flare/testing/main.h"

namespace flare::fiber {

struct AwesomeLogSink : public google::LogSink {
  void send(google::LogSeverity severity, const char* full_filename,
            const char* base_filename, int line, const struct ::tm* tm_time,
            const char* message, size_t message_len) override {
    last.assign(message, message_len);
  }
  std::string last;
};

TEST(Logging, Prefix) {
  AwesomeLogSink sink;
  google::AddLogSink(&sink);

  FLARE_LOG_INFO("something");
  ASSERT_EQ("something", sink.last);

  AddLoggingItemToFiber("prefix");
  FLARE_LOG_INFO("something");
  ASSERT_EQ("[prefix] something", sink.last);

  AddLoggingItemToFiber("prefix2");
  FLARE_LOG_INFO("something");
  ASSERT_EQ("[prefix] [prefix2] something", sink.last);

  ExecutionContext::Create()->Execute([&] {
    AddLoggingItemToFiber("prefix3");
    FLARE_LOG_INFO("something");
    ASSERT_EQ("[prefix] [prefix2] [prefix3] something", sink.last);

    AddLoggingItemToExecution("exec-prefix");
    FLARE_LOG_INFO("something");
    ASSERT_EQ("[prefix] [prefix2] [prefix3] [exec-prefix] something",
              sink.last);
  });

  // Execution context logging prefix should be gone now.

  FLARE_LOG_INFO("something");
  ASSERT_EQ("[prefix] [prefix2] [prefix3] something", sink.last);

  AddLoggingTagToFiber("key", "value");
  FLARE_LOG_INFO("something");
  ASSERT_EQ("[prefix] [prefix2] [prefix3] [key: value] something", sink.last);

  google::RemoveLogSink(&sink);
}

}  // namespace flare::fiber

FLARE_TEST_MAIN
