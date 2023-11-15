#ifndef FLARE_BASE_INTERNAL_EARLY_INIT_H_
#define FLARE_BASE_INTERNAL_EARLY_INIT_H_

#include "flare/base/never_destroyed.h"

namespace flare::internal {

namespace detail {

// CAUTION: Global object initialization order fiasco.
template <class T, class Tag = void>
struct EarlyInitInstance {
  inline static NeverDestroyed<T> object;
};

}  // namespace detail

// Returns a const ref to `T` instance.
//
// This method can be handy for initializing default arguments.
//
// For better code-gen, this method can be used when necessary. However, unlike
// its counterpart in `lazy_init.h`, here you risk global object initialization
// order fiasco.
//
// Note that instance returned by this method is NEVER destroyed.
template <class T, class Tag = void>
const T& EarlyInitConstant() {
  return *detail::EarlyInitInstance<T, Tag>::object.Get();
}

}  // namespace flare::internal

#endif  // FLARE_BASE_INTERNAL_EARLY_INIT_H_
