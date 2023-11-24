#ifndef FLARE_BASE_CRYPTO_SHA_H_
#define FLARE_BASE_CRYPTO_SHA_H_

#include <cstddef>
#include <initializer_list>
#include <string>
#include <string_view>

#include "flare/base/buffer.h"

namespace flare {

// Hash `data` using Secure Hash Algorithms.
//
// The resulting value is NOT hex-encoded.
std::string Sha1(std::string_view data);
std::string Sha1(std::initializer_list<std::string_view> data);
std::string Sha1(const NoncontiguousBuffer& data);
std::string Sha224(std::string_view data);
std::string Sha224(std::initializer_list<std::string_view> data);
std::string Sha224(const NoncontiguousBuffer& data);
std::string Sha256(std::string_view data);
std::string Sha256(std::initializer_list<std::string_view> data);
std::string Sha256(const NoncontiguousBuffer& data);
std::string Sha384(std::string_view data);
std::string Sha384(std::initializer_list<std::string_view> data);
std::string Sha384(const NoncontiguousBuffer& data);
std::string Sha512(std::string_view data);
std::string Sha512(std::initializer_list<std::string_view> data);
std::string Sha512(const NoncontiguousBuffer& data);

// HMAC-SHA
std::string HmacSha1(std::string_view key, std::string_view data);
std::string HmacSha1(std::string_view key,
                     std::initializer_list<std::string_view> data);
std::string HmacSha1(std::string_view key, const NoncontiguousBuffer& data);
std::string HmacSha224(std::string_view key, std::string_view data);
std::string HmacSha224(std::string_view key,
                       std::initializer_list<std::string_view> data);
std::string HmacSha224(std::string_view key, const NoncontiguousBuffer& data);
std::string HmacSha256(std::string_view key, std::string_view data);
std::string HmacSha256(std::string_view key,
                       std::initializer_list<std::string_view> data);
std::string HmacSha256(std::string_view key, const NoncontiguousBuffer& data);
std::string HmacSha384(std::string_view key, std::string_view data);
std::string HmacSha384(std::string_view key,
                       std::initializer_list<std::string_view> data);
std::string HmacSha384(std::string_view key, const NoncontiguousBuffer& data);
std::string HmacSha512(std::string_view key, std::string_view data);
std::string HmacSha512(std::string_view key,
                       std::initializer_list<std::string_view> data);
std::string HmacSha512(std::string_view key, const NoncontiguousBuffer& data);

}  // namespace flare

#endif  // FLARE_BASE_CRYPTO_SHA_H_
