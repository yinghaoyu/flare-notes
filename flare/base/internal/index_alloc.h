#ifndef FLARE_BASE_INTERNAL_INDEX_ALLOC_H_
#define FLARE_BASE_INTERNAL_INDEX_ALLOC_H_

#include <cstddef>
#include <mutex>
#include <vector>

#include "flare/base/never_destroyed.h"

namespace flare::internal {

// This class helps you allocate indices. Indices are numbered from 0.
//
// Note that this class does NOT perform well. It's not intended for use in
// scenarios where efficient index allocation is needed.
class IndexAlloc {
 public:
  // To prevent interference between index allocation for different purpose, you
  // can use tag type to separate different allocations.
  template <class Tag>
  static IndexAlloc* For() {
    static NeverDestroyedSingleton<IndexAlloc> ia;
    return ia.Get();
  }

  // Get next available index. If there's previously freed index (via `Free`),
  // it's returned, otherwise a new one is allocated.
  std::size_t Next();

  // Free an index. It can be reused later.
  void Free(std::size_t index);

 private:
  friend class NeverDestroyedSingleton<IndexAlloc>;
  // You shouldn't instantiate this class yourself, call `For<...>()` instead.
  IndexAlloc() = default;
  ~IndexAlloc() = default;

  std::mutex lock_;
  std::size_t current_{};
  std::vector<std::size_t> recycled_;
};

}  // namespace flare::internal

#endif  // FLARE_BASE_INTERNAL_INDEX_ALLOC_H_
