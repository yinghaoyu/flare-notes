#include "flare/base/crypto/blake3.h"

#include <string>
#include <string_view>

#include <blake3.h>

#include "flare/base/buffer.h"

namespace flare {

namespace {

template <class F>
std::string Blake3Impl(F&& cb) {
  blake3_hasher state;
  blake3_hasher_init(&state);
  std::forward<F>(cb)(&state);
  std::uint8_t output[BLAKE3_OUT_LEN];
  blake3_hasher_finalize(&state, output, BLAKE3_OUT_LEN);
  return std::string(reinterpret_cast<char*>(output), BLAKE3_OUT_LEN);
}

}  // namespace

std::string Blake3(std::string_view data) {
  return Blake3Impl([&](auto* state) {
    blake3_hasher_update(state, data.data(), data.size());
  });
}

std::string Blake3(const NoncontiguousBuffer& data) {
  return Blake3Impl([&](auto* state) {
    for (auto&& e : data) {
      blake3_hasher_update(state, e.data(), e.size());
    }
  });
}

std::string Blake3(std::initializer_list<std::string_view> data) {
  return Blake3Impl([&](auto* state) {
    for (auto&& e : data) {
      blake3_hasher_update(state, e.data(), e.size());
    }
  });
}

Blake3Digest::Blake3Digest() { blake3_hasher_init(&state_); }

void Blake3Digest::Append(std::string_view data) noexcept {
  Append(data.data(), data.size());
}

void Blake3Digest::Append(const void* data, std::size_t length) noexcept {
  blake3_hasher_update(&state_, data, length);
}

void Blake3Digest::Append(
    std::initializer_list<std::string_view> data) noexcept {
  for (auto&& e : data) {
    Append(e);
  }
}

std::string Blake3Digest::DestructiveGet() noexcept {
  std::uint8_t output[BLAKE3_OUT_LEN];
  blake3_hasher_finalize(&state_, output, BLAKE3_OUT_LEN);
  return std::string(reinterpret_cast<char*>(output), BLAKE3_OUT_LEN);
}

}  // namespace flare
