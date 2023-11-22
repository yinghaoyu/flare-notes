#include "flare/fiber/detail/fiber_desc.h"

#include <chrono>
#include <cstddef>
#include <limits>

#include "flare/base/object_pool.h"
#include "flare/fiber/detail/waitable.h"

namespace flare {

template <>
struct PoolTraits<fiber::detail::FiberDesc> {
  static constexpr auto kType = PoolType::MemoryNodeShared;

  // Chosen arbitrarily. TODO(luobogao): Fine tuning.
  static constexpr auto kLowWaterMark = 16384;
  static constexpr auto kHighWaterMark =
      std::numeric_limits<std::size_t>::max();
  static constexpr auto kMaxIdle = std::chrono::seconds(10);
  static constexpr auto kMinimumThreadCacheSize = 4096;
  static constexpr auto kTransferBatchSize = 1024;

  static void OnPut(fiber::detail::FiberDesc* desc) {
    FLARE_CHECK(!desc->start_proc,
                "Unexpected: `FiberDesc` is destroyed without ever run.");
    FLARE_CHECK(
        !desc->exit_barrier,
        "Unexpected: `FiberDesc` is destroyed without being detached first.");
  }
};

}  // namespace flare

namespace flare::fiber::detail {

FiberDesc::FiberDesc() { SetRuntimeTypeTo<FiberDesc>(); }

FiberDesc* NewFiberDesc() noexcept {
  return object_pool::Get<FiberDesc>().Leak();
}

void DestroyFiberDesc(FiberDesc* desc) noexcept {
  object_pool::Put<FiberDesc>(desc);
}

}  // namespace flare::fiber::detail
