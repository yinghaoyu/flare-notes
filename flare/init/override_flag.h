#ifndef FLARE_INIT_OVERRIDE_FLAG_H_
#define FLARE_INIT_OVERRIDE_FLAG_H_

#include <string>

#include "flare/base/internal/macro.h"

// GFlags are parsed by Flare, and in certain cases, used prior to calling
// user's entry point. Unable to override flags before Flare read them can be
// inconvenient in some cases. Here we provide this macro to accomplish this.
//
// Once Flare finishes parsing GFlags, new value specified by this macro is
// applied. Only after all new values are applied will Flare start to read them.
//
// Note that if the same flag is specified explicitly when starting the program,
// that value will take precedence.
#define FLARE_OVERRIDE_FLAG(Name, NewValue)                                \
  static ::flare::detail::FlagOverriderRegistration FLARE_INTERNAL_PP_CAT( \
      flare_anonymous_flag_overrider_, __COUNTER__)(#Name, NewValue, false)

// Same as `FLARE_OVERRIDE_FLAG` except that this one overrides flag regardless
// of whether the user set it manually when running the program.
#define FLARE_FORCE_OVERRIDE_FLAG(Name, NewValue)                          \
  static ::flare::detail::FlagOverriderRegistration FLARE_INTERNAL_PP_CAT( \
      flare_anonymous_flag_overrider_, __COUNTER__)(#Name, NewValue, true)

// Implementation goes below.
namespace flare::detail {

void RegisterFlagOverrider(const std::string& name, const std::string& value,
                           bool forcibly);

// Called by `flare::Start`.
void ApplyFlagOverrider();

// Register a pending flag override operation.
class FlagOverriderRegistration {
 public:
  template <class T,
            std::enable_if_t<std::is_trivial_v<T> &&
                             !std::is_same_v<T, const char*>>* = nullptr>
  FlagOverriderRegistration(const std::string& name, T value, bool forcibly) {
    RegisterFlagOverrider(name, std::to_string(value), forcibly);
  }

  FlagOverriderRegistration(const std::string& name, const std::string& value,
                            bool forcibly) {
    RegisterFlagOverrider(name, value, forcibly);
  }
};

}  // namespace flare::detail

#endif  // FLARE_INIT_OVERRIDE_FLAG_H_
