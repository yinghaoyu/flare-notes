#include "flare/base/object_pool.h"

namespace flare::object_pool {

namespace internal {

void InitializeObjectPoolForCurrentThread() {
  // Only `MemoryNodeShared` support this for now.
  detail::memory_node_shared::EarlyInitializeForCurrentThread();
}

}  // namespace internal

}  // namespace flare::object_pool
