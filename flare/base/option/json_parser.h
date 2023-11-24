#ifndef FLARE_BASE_OPTION_JSON_PARSER_H_
#define FLARE_BASE_OPTION_JSON_PARSER_H_

#include <optional>
#include <string>

#include "json/value.h"

namespace flare::option {

// Parses `std::string` to `Json::Value`.
struct JsonParser {
  static std::optional<Json::Value> TryParse(const std::string& str);
};

}  // namespace flare::option

#endif  // FLARE_BASE_OPTION_JSON_PARSER_H_
