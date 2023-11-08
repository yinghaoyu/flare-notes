#ifndef FLARE_BASE_DEFERRED_H_
#define FLARE_BASE_DEFERRED_H_

#include <utility>

#include "flare/base/function.h"

namespace flare {

// Call `F` on destruction.
template <class F>
class ScopedDeferred {
 public:
  explicit ScopedDeferred(F&& f) : action_(std::move(f)) {}
  ~ScopedDeferred() { action_(); }

  // Noncopyable / nonmovable.
  ScopedDeferred(const ScopedDeferred&) = delete;
  ScopedDeferred& operator=(const ScopedDeferred&) = delete;

 private:
  F action_;
};

// Call action on destruction. Moveable. Dismissable.
class Deferred {
 public:
  Deferred() = default;

  template <class F>
  explicit Deferred(F&& f) : action_(std::forward<F>(f)) {}
  Deferred(Deferred&& other) noexcept { action_ = std::move(other.action_); }
  Deferred& operator=(Deferred&& other) noexcept {
    if (&other == this) {
      return *this;
    }
    Fire();
    action_ = std::move(other.action_);
    return *this;
  }
  ~Deferred() {
    if (action_) {
      action_();
    }
  }

  explicit operator bool() const noexcept { return !!action_; }

  void Fire() noexcept {
    if (auto op = std::move(action_)) {
      op();
    }
  }

  void Dismiss() noexcept { action_ = nullptr; }

 private:
  Function<void()> action_;
};

// Do we need a `FLARE_DEFER`?

}  // namespace flare

#endif  // FLARE_BASE_DEFERRED_H_
