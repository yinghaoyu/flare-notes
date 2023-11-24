#ifndef FLARE_BASE_ENCODING_HEX_H_
#define FLARE_BASE_ENCODING_HEX_H_

#include <optional>
#include <string>
#include <string_view>

namespace flare {

std::string EncodeHex(std::string_view from, bool uppercase = false);
std::optional<std::string> DecodeHex(std::string_view from);

void EncodeHex(std::string_view from, std::string* to, bool uppercase = false);
bool DecodeHex(std::string_view from, std::string* to);

}  // namespace flare

#endif  // FLARE_BASE_ENCODING_HEX_H_
