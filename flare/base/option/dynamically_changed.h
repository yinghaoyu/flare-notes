#ifndef FLARE_BASE_OPTION_DYNAMICALLY_CHANGED_H_
#define FLARE_BASE_OPTION_DYNAMICALLY_CHANGED_H_

#include <atomic>
#include <type_traits>
#include <utility>

#include "flare/base/thread/thread_cached.h"

namespace flare::option::detail {

namespace detail {

// `std::atomic<T>::is_lock_free` cannot be used with `std::string` (or other
// non-trivially-copyable types), so we roll our own SFINAE-friendly one.
template <class T, class = void>
struct is_atomic_lock_free : std::false_type {};
template <class T>
struct is_atomic_lock_free<T, std::enable_if_t<std::is_trivially_copyable_v<T>>>
    : std::integral_constant<bool, std::atomic<T>::is_always_lock_free> {};
template <class T>
constexpr auto is_atomic_always_lock_free_v = is_atomic_lock_free<T>::value;

}  // namespace detail

// This class supports reading dynamically (infrequently) changed data
// efficiently.
//
// FIXME: Need a better name (`ReadMostly`?).
template <class T, class = void>
class DynamicallyChanged {
 public:
  // Those types are handled separately (see specialization below).
  static_assert(!detail::is_atomic_always_lock_free_v<T>);

  explicit DynamicallyChanged(T default_value = {})
      : value_(std::move(default_value)) {}

  // CAUTION: Consecutive calls to `Get()` (can possibly) invalidate ref.
  // returned by previous calls.
  const T& Get() const noexcept { return value_.NonIdempotentGet(); }

  template <class... Us>
  void Emplace(Us&&... args) {
    value_.Emplace(std::forward<Us>(args)...);
  }

 private:
  // Trade space for time.
  ThreadCached<T> value_;
};

// Easy case. `std::atomic<T>` satisfied all our needs.
template <class T>
class DynamicallyChanged<
    T,
    // Overkill.
    //
    // So long as `std::atomic<T>::load` / `std::atomic<T>::store` is lock free,
    // we're good.
    std::enable_if_t<detail::is_atomic_always_lock_free_v<T>>> {
 public:
  explicit DynamicallyChanged(T default_value = {}) : val_(default_value) {}

  T Get() const noexcept { return val_.load(std::memory_order_relaxed); }

  void Emplace(T value) noexcept {
    val_.store(value, std::memory_order_release);
  }

 private:
  std::atomic<T> val_;
};

}  // namespace flare::option::detail

#endif  // FLARE_BASE_OPTION_DYNAMICALLY_CHANGED_H_
