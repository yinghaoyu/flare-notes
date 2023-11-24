#ifndef FLARE_BASE_COMPRESSION_UTIL_H_
#define FLARE_BASE_COMPRESSION_UTIL_H_

#include "flare/base/compression/compression.h"

namespace flare::compression {

// This is used when we need a contiguous buffer to do compression with `size`
// but `out` cannot offer directly. So we create a temporary buffer with `size`
// and finally copy this buffer to out.
bool CopyDataToCompressionOutputStream(CompressionOutputStream* out,
                                       const void* data, std::size_t size);

}  // namespace flare::compression

#endif  // FLARE_BASE_COMPRESSION_UTIL_H_
