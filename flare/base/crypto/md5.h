#ifndef FLARE_BASE_CRYPTO_MD5_H_
#define FLARE_BASE_CRYPTO_MD5_H_

#include <cstddef>
#include <initializer_list>
#include <string>
#include <string_view>

#include "flare/base/buffer.h"

namespace flare {

// Hash `data` using MD5.
//
// The resulting value is NOT hex-encoded.
std::string Md5(std::string_view data);
std::string Md5(std::initializer_list<std::string_view> data);
std::string Md5(const NoncontiguousBuffer& data);

// HMAC-MD5
std::string HmacMd5(std::string_view key, std::string_view data);
std::string HmacMd5(std::string_view key,
                    std::initializer_list<std::string_view> data);
std::string HmacMd5(std::string_view key, const NoncontiguousBuffer& data);

}  // namespace flare

#endif  // FLARE_BASE_CRYPTO_MD5_H_
