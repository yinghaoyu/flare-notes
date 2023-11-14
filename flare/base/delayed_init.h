#ifndef FLARE_BASE_DELAYED_INIT_H_
#define FLARE_BASE_DELAYED_INIT_H_

#include <optional>
#include <utility>

#include "flare/base/internal/logging.h"

namespace flare {

// This class allows you to delay initialization of an object.
template <class T>
class DelayedInit {
 public:
  template <class... Args>
  void Init(Args&&... args) {
    value_.emplace(std::forward<Args>(args)...);
  }

  void Destroy() { value_ = std::nullopt; }

  T* operator->() {
    FLARE_DCHECK(value_);
    return &*value_;
  }

  const T* operator->() const {
    FLARE_DCHECK(value_);
    return &*value_;
  }

  T& operator*() {
    FLARE_DCHECK(value_);
    return *value_;
  }

  const T& operator*() const {
    FLARE_DCHECK(value_);
    return *value_;
  }

  explicit operator bool() const { return !!value_; }

 private:
  std::optional<T> value_;
};

}  // namespace flare

#endif  // FLARE_BASE_DELAYED_INIT_H_
