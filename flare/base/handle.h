#ifndef FLARE_BASE_HANDLE_H_
#define FLARE_BASE_HANDLE_H_

#include <unistd.h>

#include "flare/base/logging.h"

namespace flare {

namespace detail {

struct HandleDeleter {
  void operator()(int fd) const noexcept {
    if (fd == 0 || fd == -1) {
      return;
    }
    FLARE_PCHECK(::close(fd) == 0);
  }
};

// Using inheritance rather than member method for EBO.
//
// @sa: https://en.cppreference.com/w/cpp/language/attributes/no_unique_address
//
// Not sure if we should move this class out for public use.
template <class T, class Deleter, T... kInvalidHandles>
class GenericHandle : private Deleter {
  // Anyone will do.
  static constexpr T kDefaultInvalid = (kInvalidHandles, ...);

 public:
  GenericHandle() = default;

  constexpr explicit GenericHandle(T handle) noexcept : handle_(handle) {}
  ~GenericHandle() { Reset(); }

  // Movable.
  constexpr GenericHandle(GenericHandle&& h) noexcept {
    handle_ = h.handle_;
    h.handle_ = kDefaultInvalid;
  }
  constexpr GenericHandle& operator=(GenericHandle&& h) noexcept {
    handle_ = h.handle_;
    h.handle_ = kDefaultInvalid;
    return *this;
  }

  // Non-copyable.
  GenericHandle(const GenericHandle&) = delete;
  GenericHandle& operator=(const GenericHandle&) = delete;

  // Useful if handle is returned by argument:
  //
  // GetHandle(..., h.Retrieve());
  T* Retrieve() noexcept { return &handle_; }

  // Return handle's value.
  constexpr T Get() const noexcept { return handle_; }

  // Return if we're holding a valid handle value.
  constexpr explicit operator bool() const noexcept {
    // The "extra" parentheses is grammatically required.
    return ((handle_ != kInvalidHandles) && ...);
  }

  // Return handle's value, and give up ownership.
  constexpr T Leak() noexcept {
    int rc = handle_;
    handle_ = kDefaultInvalid;
    return rc;
  }

  void Reset(T new_value = kDefaultInvalid) noexcept {
    if (operator bool()) {
      Deleter::operator()(handle_);
    }
    handle_ = new_value;
  }

 private:
  T handle_ = kDefaultInvalid;
};

}  // namespace detail

using Handle = detail::GenericHandle<int, detail::HandleDeleter, -1, 0>;

}  // namespace flare

#endif  // FLARE_BASE_HANDLE_H_
