#ifndef FLARE_BASE_OPTION_PROTO_PARSER_H_
#define FLARE_BASE_OPTION_PROTO_PARSER_H_

#include <optional>
#include <string>

#include "google/protobuf/text_format.h"

namespace flare::option {

// Parses "debug string" to Protocol Buffers message.
template <class T>
struct ProtoTextFormatParser {
  static std::optional<T> TryParse(const std::string& str) {
    T result;
    if (google::protobuf::TextFormat::ParseFromString(str, &result)) {
      return result;
    }
    return std::nullopt;
  }
};

}  // namespace flare::option

#endif  // FLARE_BASE_OPTION_PROTO_PARSER_H_
