#include "flare/base/option/json_parser.h"

#include "json/json.h"

namespace flare::option {

std::optional<Json::Value> JsonParser::TryParse(const std::string& str) {
  if (str.empty()) {  // Special case for empty default value.
    return Json::Value{};
  }
  Json::Value value;
  if (Json::Reader().parse(str, value)) {
    return value;
  }
  return std::nullopt;
}

}  // namespace flare::option
