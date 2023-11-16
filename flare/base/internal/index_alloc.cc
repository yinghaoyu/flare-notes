#include "flare/base/internal/index_alloc.h"

namespace flare::internal {

std::size_t IndexAlloc::Next() {
  std::scoped_lock _(lock_);
  if (!recycled_.empty()) {
    auto rc = recycled_.back();
    recycled_.pop_back();
    return rc;
  }
  return current_++;
}

void IndexAlloc::Free(std::size_t index) {
  std::scoped_lock _(lock_);
  recycled_.push_back(index);
}

}  // namespace flare::internal
