#ifndef FLARE_BASE_CRYPTO_BLAKE3_H_
#define FLARE_BASE_CRYPTO_BLAKE3_H_

#include <initializer_list>
#include <string>
#include <string_view>

#include <blake3.h>

#include "flare/base/buffer.h"

namespace flare {

// Hash `data` using BLAKE3 algorithm.
//
// The resulting value is NOT hex-encoded.
std::string Blake3(std::string_view data);
std::string Blake3(std::initializer_list<std::string_view> data);
std::string Blake3(const NoncontiguousBuffer& data);

// This class allows you to generated BLAKE3 hash of a stream of data.
class Blake3Digest {
 public:
  Blake3Digest();

  void Append(std::string_view data) noexcept;
  void Append(const void* data, std::size_t length) noexcept;
  void Append(std::initializer_list<std::string_view> data) noexcept;

  template <
      template <class> class C, class T,
      std::enable_if_t<std::is_convertible_v<T, std::string_view>>* = nullptr>
  void Append(const C<T>& data) noexcept {
    for (auto&& e : data) {
      Append(e);
    }
  }

  std::string DestructiveGet() noexcept;

 private:
  blake3_hasher state_;
};

}  // namespace flare

#endif  // FLARE_BASE_CRYPTO_BLAKE3_H_
