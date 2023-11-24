#ifndef FLARE_BASE_ENCODING_BASE64_H_
#define FLARE_BASE_ENCODING_BASE64_H_

#include <optional>
#include <string>
#include <string_view>

#include "flare/base/internal/early_init.h"

namespace flare {

std::string EncodeBase64(std::string_view from);
std::optional<std::string> DecodeBase64(std::string_view from);

void EncodeBase64(std::string_view from, std::string* to);
bool DecodeBase64(std::string_view from, std::string* to);

}  // namespace flare

#endif  // FLARE_BASE_ENCODING_BASE64_H_
