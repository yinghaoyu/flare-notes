#include "flare/base/internal/circular_buffer.h"

#include <string>
#include <thread>

#include "gtest/gtest.h"

namespace flare::internal {

TEST(CircularBuffer, Capacity) {
  static constexpr auto kCapacity = 12345;
  CircularBuffer<std::string> buffer(kCapacity);

  for (int i = 0; i != kCapacity; ++i) {
    ASSERT_TRUE(buffer.Emplace("asdf"));
  }
  ASSERT_FALSE(buffer.Emplace("asdf"));
}

TEST(CircularBuffer, Torture) {
  CircularBuffer<std::string> buffer(10000);
  static constexpr auto kObjectsToPush = 100'000'000;

  std::thread prod([&] {
    std::size_t pushed = 0;

    while (pushed != kObjectsToPush) {
      pushed += buffer.Emplace("my fancy string") ? 1 : 0;
    }
  });

  std::thread consumer([&] {
    std::size_t consumed = 0;

    while (consumed != kObjectsToPush) {
      thread_local std::vector<std::string> objects;
      objects.clear();
      buffer.Pop(&objects);
      for (auto&& e : objects) {
        ASSERT_EQ("my fancy string", e);
      }
      consumed += objects.size();
      ASSERT_LE(consumed, kObjectsToPush);
    }
  });

  prod.join();
  consumer.join();
}

}  // namespace flare::internal
