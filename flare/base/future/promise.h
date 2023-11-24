#ifndef FLARE_BASE_FUTURE_PROMISE_H_
#define FLARE_BASE_FUTURE_PROMISE_H_

#include <memory>
#include <tuple>

#include "flare/base/future/basics.h"
#include "flare/base/future/core.h"

namespace flare::future {

// `Promise` is used to notify the holder of `Future` about event completion.
// It's valid even if it's orphaned (i.e., the corresponding `Future` is
// destroyed).
template <class... Ts>
class Promise {
 public:
  using value_type = std::tuple<Ts...>;

  Promise();
  // Non-copyable.
  Promise(const Promise&) = delete;
  Promise& operator=(const Promise&) = delete;
  // Movable.
  Promise(Promise&&) = default;
  Promise& operator=(Promise&&) = default;

  static_assert(!types_contains_v<Types<Ts...>, void>,
                "There's no point in specifying `void` in `Ts...`, use "
                "`Promise<>` if you meant to declare a future with no value.");

  // Returns: `Future` that is satisfied when one of `SetXxx` is called.
  //
  // May only be called once. (But how should we check this?)
  Future<Ts...> GetFuture();

  // Satisfy the future with values.
  template <class... Us, class = std::enable_if_t<
                             std::is_constructible_v<value_type, Us&&...>>>
  void SetValue(Us&&... values);

  // Satisfy the future with a boxed value.
  void SetBoxed(Boxed<Ts...> boxed);

 private:
  template <class... Us>
  friend class Future;

  // Construct a `Promise` with `executor` instead of what
  // `GetDefaultExecutor()` gives.
  //
  // There's not much harm if we expose this constructor to the users, but
  // I'm not sure if we want to give the user the ability to choose a different
  // executor for each `Promise` they make.
  explicit Promise(Executor executor);

  std::shared_ptr<Core<Ts...>> core_;
};

// Implemented in a separate header.
}  // namespace flare::future

#endif  // FLARE_BASE_FUTURE_PROMISE_H_
