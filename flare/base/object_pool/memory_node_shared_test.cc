#include "flare/base/object_pool.h"

#include <atomic>
#include <thread>
#include <vector>

#include "gtest/gtest.h"

#include "flare/base/random.h"
#include "flare/base/thread/latch.h"

using namespace std::literals;

namespace flare {

std::atomic<int> c_alive = 0;

struct C {
  C() { ++c_alive; }
  ~C() { CHECK_GE(--c_alive, 0); }
};

template <>
struct PoolTraits<C> {
  static constexpr auto kType = PoolType::MemoryNodeShared;
  static constexpr auto kLowWaterMark = 0;
  static constexpr auto kHighWaterMark = 10;
  static constexpr auto kMaxIdle = 10s;
  static constexpr auto kMinimumThreadCacheSize = 0;
  static constexpr auto kTransferBatchSize = 1;
};

// Destruction of `Outer` recursively triggers destruction of `Inner3` /
// `Inner2` / `Inner1` / `Inner0`.
struct Inner0 {};

struct Inner1 {
  PooledPtr<Inner0> ptr = object_pool::Get<Inner0>();
};

struct Inner2 {
  PooledPtr<Inner1> ptr = object_pool::Get<Inner1>();
};

struct Inner3 {
  PooledPtr<Inner2> ptr = object_pool::Get<Inner2>();
};

struct Outer {
  PooledPtr<Inner3> ptr = object_pool::Get<Inner3>();
};

template <>
struct PoolTraits<Inner0> {
  static constexpr auto kType = PoolType::MemoryNodeShared;
  static constexpr auto kLowWaterMark = 0;
  static constexpr auto kHighWaterMark = 10;
  static constexpr auto kMaxIdle = 1s;
  static constexpr auto kMinimumThreadCacheSize = 0;
  static constexpr auto kTransferBatchSize = 1;
};

template <>
struct PoolTraits<Inner1> : PoolTraits<Inner0> {};
template <>
struct PoolTraits<Inner2> : PoolTraits<Inner0> {};
template <>
struct PoolTraits<Inner3> : PoolTraits<Inner0> {};
template <>
struct PoolTraits<Outer> : PoolTraits<Inner0> {};

namespace object_pool {

namespace {

template <class T>
void TriggerCacheWashOut() {
  for (int i = 0; i != 50; ++i) {
    std::this_thread::sleep_for(50ms);
    Get<T>();
  }
}

}  // namespace

TEST(MemoryNodeShared, WithCache) {
  std::vector<PooledPtr<C>> ptrs;
  for (int i = 0; i != 100; ++i) {
    ptrs.push_back(Get<C>());
  }
  ASSERT_EQ(100, c_alive);
  ptrs.clear();
  TriggerCacheWashOut<C>();
  ASSERT_EQ(10, c_alive);  // In global cache.
  std::this_thread::sleep_for(1s);
  Get<C>();
  ASSERT_EQ(10, c_alive);  // In global cache.
}

TEST(MemoryNodeShared, RecursivePut) {
  std::thread ts[100];
  std::atomic<bool> leaving{};

  for (auto&& t : ts) {
    t = std::thread([&] {
      std::vector<PooledPtr<Outer>> objs;
      while (!leaving.load(std::memory_order_relaxed)) {
        auto op = Random() % 10;
        if (op == 0) {
          if (!objs.empty()) {
            objs.pop_back();
          }
        } else if (op == 1) {
          objs.clear();
        } else {
          objs.push_back(object_pool::Get<Outer>());
        }
      }
    });
  }
  std::this_thread::sleep_for(20s);
  leaving = true;
  for (auto&& t : ts) {
    t.join();
  }
}

}  // namespace object_pool
}  // namespace flare
