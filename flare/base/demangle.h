#ifndef FLARE_BASE_DEMANGLE_H_
#define FLARE_BASE_DEMANGLE_H_

#include <string>
#include <typeinfo>
#include <utility>

namespace flare {

std::string Demangle(const char* s);

template <class T>
std::string GetTypeName() {
  return Demangle(typeid(T).name());
}

#if __GNUC__ >= 12
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnonnull-compare"
#endif

template <class T>
std::string GetTypeName(T&& o) {
  return Demangle(typeid(std::forward<T>(o)).name());
}

#if __GNUC__ >= 12
#pragma GCC diagnostic pop
#endif

}  // namespace flare

#endif  // FLARE_BASE_DEMANGLE_H_
