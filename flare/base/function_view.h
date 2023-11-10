#ifndef FLARE_BASE_FUNCTION_VIEW_H_
#define FLARE_BASE_FUNCTION_VIEW_H_

#include <functional>
#include <type_traits>
#include <utility>

namespace flare {

template <class T>
class FunctionView;

// Deduction of `noexcept` is not part of C++17, actually.
//
// It's an extension: https://gcc.gnu.org/ml/gcc-patches/2016-11/msg00665.html
template <class R, class... Args, bool kNoexcept>
class FunctionView<R(Args...) noexcept(kNoexcept)> {
 public:
  // Same as the constraints in `Function`.
  //
  // `constexpr auto` doesn't work here since Clang 9. LLVM Bug 43459 seems
  // related: https://bugs.llvm.org/show_bug.cgi?id=43459 .
  template <class T>
  static constexpr bool implicitly_convertible_v =
      std::is_invocable_r_v<R, T, Args...> &&
      !std::is_same_v<std::decay_t<T>, FunctionView> &&
      (!kNoexcept || std::is_nothrow_invocable_v<T, Args...>);

  // Default construction is not supported. I'm not sure if it's of any use.
  //
  // Copy & move is trivial, if the user wants to. (Although I'm not sure if
  // they can do it correctly. This is as dangerous as copying / moving
  // `std::string_view`.).

  // Construct `FunctionView` by referring to a `functor`.
  template <class T, class = std::enable_if_t<implicitly_convertible_v<T>>>
  constexpr /* implicit */ FunctionView(T&& functor) {
    using RefRemoved = std::remove_reference_t<T>;
    constexpr auto kConstantFunctor = std::is_const_v<RefRemoved>;

    // `functor` is casted to `const ...` unconditionally to simplify coding.
    //
    // We'll strip the `const` if appropriate in `invoker_`.
    object_ = reinterpret_cast<const void*>(&functor);
    invoker_ = [](const void* object, Args&&... args) -> R {
      if constexpr (kConstantFunctor) {
        return Invoke(std::forward<T>(*reinterpret_cast<RefRemoved*>(object)),
                      std::forward<Args>(args)...);
      } else {
        // Otherwise we need to strip `const` we've added to `object_`.
        return Invoke(std::forward<T>(*reinterpret_cast<RefRemoved*>(
                          const_cast<void*>(object))),
                      std::forward<Args>(args)...);
      }
    };
  }

  // Call the functor used to construct us.
  R operator()(Args... args) const noexcept(kNoexcept) {
    return invoker_(object_, std::forward<Args>(args)...);
  }

 private:
  using Invoker = R (*)(const void* object, Args&&... args);

  // Helper method for calling `functor`. Specializes for case where `R` is
  // `void`.
  template <class T>
  static R Invoke(T&& functor, Args&&... args) noexcept(kNoexcept) {
    if constexpr (std::is_void_v<R>) {
      std::invoke(std::forward<T>(functor), std::forward<Args>(args)...);
    } else {
      return std::invoke(std::forward<T>(functor), std::forward<Args>(args)...);
    }
  }

  const void* object_;
  Invoker invoker_;
};

// Deduction guides are not provided. As the template parameter is always
// required when declaring function parameter's type.
}  // namespace flare

#endif  // FLARE_BASE_FUNCTION_VIEW_H_
