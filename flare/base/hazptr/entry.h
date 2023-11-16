#ifndef FLARE_BASE_HAZPTR_ENTRY_H_
#define FLARE_BASE_HAZPTR_ENTRY_H_

#include <atomic>

namespace flare {

class HazptrDomain;

}  // namespace flare

namespace flare::hazptr {

class Object;

struct Entry {
  std::atomic<const Object*> ptr;
  std::atomic<bool> active{false};
  HazptrDomain* domain;
  Entry* next{nullptr};

  bool TryAcquire() noexcept {
    return !active.load(std::memory_order_relaxed) &&
           !active.exchange(true, std::memory_order_relaxed);
  }

  void Release() noexcept { active.store(false, std::memory_order_relaxed); }

  const Object* TryGetPtr() noexcept {
    return ptr.load(std::memory_order_acquire);
  }

  void ExposePtr(const Object* ptr) noexcept {
    this->ptr.store(ptr, std::memory_order_release);
  }
};

}  // namespace flare::hazptr

#endif  // FLARE_BASE_HAZPTR_ENTRY_H_
