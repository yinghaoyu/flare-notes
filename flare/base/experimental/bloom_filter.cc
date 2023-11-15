#include "flare/base/experimental/bloom_filter.h"

#include "xxhash.h"

namespace flare::experimental::bloom_filter::detail {

std::size_t Hash::operator()(std::string_view s) const noexcept {
  return XXH64(s.data(), s.size(), 0);
}

}  // namespace flare::experimental::bloom_filter::detail
