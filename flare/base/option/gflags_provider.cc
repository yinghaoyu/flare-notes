#include "flare/base/option/option_provider.h"

#include <optional>

#include "gflags/gflags.h"

#include "flare/base/status.h"
#include "flare/base/string.h"

namespace flare::option {

// Supports reading values from GFlags. Mostly used for testing / illustration
// purpose.
class GFlagsProvider : public OptionPassiveProvider {
 public:
  bool GetAll(const std::vector<const option::MultiKey*>& names) override {
    return true;
  }

#define DEFINE_GFLAGS_PROVIDER_IMPL_FOR(Type, TypeName, GFlagTypeName)      \
  Status Get##TypeName(const option::MultiKey& name,                        \
                       std::optional<Type>* value) override {               \
    auto&& info =                                                           \
        google::GetCommandLineFlagInfoOrDie(name.ToString().c_str());       \
    auto val_opt = TryParse<Type>(info.current_value);                      \
    /* This is absolutely a programming error, as both GFlags and */        \
    /* `Option<T>` are defined programatically. */                          \
    FLARE_CHECK(val_opt, "Failed to read flag [{}] of type [{}].",          \
                name.ToString(), #Type);                                    \
    FLARE_CHECK_EQ(info.type, GFlagTypeName, "Type mismatch on flag [{}].", \
                   name.ToString());                                        \
    *value = *val_opt;                                                      \
    return Status(0);                                                       \
  }

  DEFINE_GFLAGS_PROVIDER_IMPL_FOR(bool, Bool, "bool")
  DEFINE_GFLAGS_PROVIDER_IMPL_FOR(std::int32_t, Int32, "int32")
  DEFINE_GFLAGS_PROVIDER_IMPL_FOR(std::int64_t, Int64, "int64")
  DEFINE_GFLAGS_PROVIDER_IMPL_FOR(std::uint64_t, UInt64, "uint64")
  DEFINE_GFLAGS_PROVIDER_IMPL_FOR(double, Double, "double")

#define DEFINE_NOT_SUPPORTED_IMPL_FOR(Type, TypeName)                 \
  Status Get##TypeName(const option::MultiKey& name,                  \
                       std::optional<Type>* value) override {         \
    FLARE_CHECK(0, "Not supported: GFlags does not allow type [{}].", \
                #TypeName);                                           \
    return Status(-1);                                                \
  }

  DEFINE_NOT_SUPPORTED_IMPL_FOR(std::int8_t, Int8)
  DEFINE_NOT_SUPPORTED_IMPL_FOR(std::uint8_t, UInt8)
  DEFINE_NOT_SUPPORTED_IMPL_FOR(std::int16_t, Int16)
  DEFINE_NOT_SUPPORTED_IMPL_FOR(std::uint16_t, UInt16)
  DEFINE_NOT_SUPPORTED_IMPL_FOR(std::uint32_t, UInt32)
  DEFINE_NOT_SUPPORTED_IMPL_FOR(float, Float)

  Status GetString(const option::MultiKey& name,
                   std::optional<std::string>* value) override {
    auto&& info = google::GetCommandLineFlagInfoOrDie(name.ToString().c_str());
    FLARE_CHECK_EQ(info.type, "string", "Type mismatch on flag [{}].",
                   name.ToString());
    *value = info.current_value;
    return Status(0);
  }
};

FLARE_OPTION_REGISTER_OPTION_PROVIDER("gflags", GFlagsProvider);

}  // namespace flare::option
