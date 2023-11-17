#include "flare/base/thread/thread_local/ref_counted.h"

#include <thread>
#include <vector>

#include "gtest/gtest.h"

namespace flare::internal {

struct C : public RefCounted<C> {
  C() { ++instances; }
  ~C() { --instances; }
  inline static int instances = 0;
};

TEST(ThreadLocalRefCounted, All) {
  ThreadLocalRefCounted<C> tls;

  (void)*tls;
  EXPECT_EQ(1, C::instances);

  std::thread([&] {
    (void)*tls;
    EXPECT_EQ(2, C::instances);
  }).join();

  EXPECT_EQ(1, C::instances);

  std::atomic<bool> tls_initialized{};
  std::atomic<bool> ready_to_leave{};

  std::thread t2([&] {
    (void)*tls;
    EXPECT_EQ(2, C::instances);
    tls_initialized = true;
    while (!ready_to_leave) {
    }
  });

  while (!tls_initialized) {
  }

  EXPECT_EQ(2, C::instances);

  std::vector<RefPtr<C>> ptrs;
  tls.ForEach([&](C* ptr) { ptrs.push_back(RefPtr(ref_ptr, ptr)); });

  ready_to_leave = true;
  t2.join();

  EXPECT_EQ(2, C::instances);

  ptrs.clear();
  EXPECT_EQ(1, C::instances);
}

}  // namespace flare::internal
