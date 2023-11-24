#ifndef FLARE_BASE_COMPRESSION_SNAPPY_H_
#define FLARE_BASE_COMPRESSION_SNAPPY_H_

#include <snappy.h>

#include "flare/base/compression/compression.h"

namespace flare::compression {

class SnappyCompressor : public Compressor {
 public:
  bool Compress(const void* src, std::size_t size,
                CompressionOutputStream* out) override;
  bool Compress(const NoncontiguousBuffer& src,
                CompressionOutputStream* out) override;
};

class SnappyDecompressor : public Decompressor {
 public:
  bool Decompress(const void* src, std::size_t size,
                  CompressionOutputStream* out) override;
  bool Decompress(const NoncontiguousBuffer& src,
                  CompressionOutputStream* out) override;
};

}  // namespace flare::compression

#endif  // FLARE_BASE_COMPRESSION_SNAPPY_H_
