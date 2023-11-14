#include "flare/base/internal/logging.h"

#include <string>
#include <vector>

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace foreign_ns {

struct AwesomeLogSink : public google::LogSink {
  void send(google::LogSeverity severity, const char* full_filename,
            const char* base_filename, int line, const struct ::tm* tm_time,
            const char* message, size_t message_len) override {
    msgs.emplace_back(message, message_len);
  }
  std::vector<std::string> msgs;
};

std::string my_prefix, my_prefix2;

void WriteLoggingPrefix(std::string* s) { *s += my_prefix; }
void WriteLoggingPrefix2(std::string* s) { *s += my_prefix2; }

TEST(Logging, Prefix) {
  AwesomeLogSink sink;
  google::AddLogSink(&sink);

  FLARE_LOG_INFO("something");

  my_prefix = "[prefix]";
  FLARE_LOG_INFO("something");

  my_prefix = "[prefix1]";
  FLARE_LOG_INFO("something");

  my_prefix2 = "[prefix2]";
  FLARE_LOG_INFO("something");

  ASSERT_THAT(sink.msgs,
              ::testing::ElementsAre("something", "[prefix] something",
                                     "[prefix1] something",
                                     "[prefix1] [prefix2] something"));
  google::RemoveLogSink(&sink);
}

TEST(Logging, DontPanicOnFormatFailure) {
  FLARE_LOG_INFO("Don't panic!{}{}", 1);
  // No assertion here, so long as the test runs without error, it passes.
}

}  // namespace foreign_ns

FLARE_INTERNAL_LOGGING_REGISTER_PREFIX_PROVIDER(0,
                                                foreign_ns::WriteLoggingPrefix)
FLARE_INTERNAL_LOGGING_REGISTER_PREFIX_PROVIDER(1,
                                                foreign_ns::WriteLoggingPrefix2)
