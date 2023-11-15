#include "flare/base/experimental/seqlocked.h"

#include <thread>

#include "gtest/gtest.h"

#include "flare/base/chrono.h"
#include "flare/base/random.h"

using namespace std::literals;

namespace flare::experimental {

struct ABigPOD {
  int asc_seq[128];
};

Seqlocked<ABigPOD> a_big_pod;

std::atomic<bool> leaving_{};

ABigPOD NewValue() {
  ABigPOD result;
  auto start = Random(12345678);
  for (int i = 0; i != 128; ++i) {
    result.asc_seq[i] = i + start;
  }
  return result;
}

void Reader() {
  while (!leaving_.load(std::memory_order_relaxed)) {
    auto read = a_big_pod.Load();
    for (int i = 1; i != 128; ++i) {
      ASSERT_EQ(read.asc_seq[i], read.asc_seq[i - 1] + 1);
    }
  }
}

TEST(Seqlocked, All) {
  auto end = ReadCoarseSteadyClock() + 10s;
  a_big_pod.Store(NewValue());

  std::thread readers[32];
  for (auto&& t : readers) {
    t = std::thread(Reader);
  }

  while (ReadCoarseSteadyClock() < end) {
    a_big_pod.Store(NewValue());
    a_big_pod.Update([](ABigPOD* p) {
      for (auto&& e : p->asc_seq) {
        ++e;
      }
    });
  }
  leaving_.store(true, std::memory_order_relaxed);
  for (auto&& t : readers) {
    t.join();
  }
}

}  // namespace flare::experimental
