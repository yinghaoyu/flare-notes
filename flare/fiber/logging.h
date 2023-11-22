#ifndef FLARE_FIBER_LOGGING_H_
#define FLARE_FIBER_LOGGING_H_

#include <string>
#include <string_view>

#include "flare/base/string.h"

namespace flare::fiber {

// Add a logging prefix to current fiber.
//
// Usage: `AddLoggingItemToExecution(some_id_var);`
void AddLoggingItemToFiber(std::string s);

// Add a logging prefix to current "execution context".
void AddLoggingItemToExecution(const std::string& s);

// Same as above, except that what's actually get added is in form of `key:
// value`.
template <class T>
void AddLoggingTagToFiber(std::string_view key, const T& value) {
  return AddLoggingItemToFiber(Format("{}: {}", key, value));
}

template <class T>
void AddLoggingTagToExecution(std::string_view key, const T& value) {
  return AddLoggingItemToExecution(Format("{}: {}", key, value));
}

}  // namespace flare::fiber

#endif  // FLARE_FIBER_LOGGING_H_
