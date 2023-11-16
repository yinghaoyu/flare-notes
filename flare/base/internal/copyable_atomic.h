#ifndef FLARE_BASE_INTERNAL_COPYABLE_ATOMIC_H_
#define FLARE_BASE_INTERNAL_COPYABLE_ATOMIC_H_

#include <atomic>

namespace flare::internal {

// Make `std::atomic<T>` copyable.
template <class T>
class CopyableAtomic : public std::atomic<T> {
 public:
  CopyableAtomic() = default;
  /* implicit */ CopyableAtomic(T value) : std::atomic<T>(std::move(value)) {}

  constexpr CopyableAtomic(const CopyableAtomic& from)
      : std::atomic<T>(from.load()) {}

  constexpr CopyableAtomic& operator=(const CopyableAtomic& from) {
    store(from.load());
    return *this;
  }
};

}  // namespace flare::internal

#endif  // FLARE_BASE_INTERNAL_COPYABLE_ATOMIC_H_
