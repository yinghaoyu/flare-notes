#ifndef FLARE_BASE_COMPRESSION_ZSTD_H_
#define FLARE_BASE_COMPRESSION_ZSTD_H_

#include <memory>

#include <zstd.h>

#include "flare/base/compression/compression.h"

namespace flare::compression {

// Implements compression using Zstd algorithm.
class ZstdCompressor : public Compressor {
 public:
  bool Compress(const void* src, std::size_t size,
                CompressionOutputStream* out) override;
  bool Compress(const NoncontiguousBuffer& src,
                CompressionOutputStream* out) override;

 private:
  bool Init(CompressionOutputStream* out);
  bool Append(const void* buffer, std::size_t size);
  bool Flush();

  std::unique_ptr<ZSTD_CCtx, decltype(&ZSTD_freeCCtx)> ctx_{ZSTD_createCCtx(),
                                                            &ZSTD_freeCCtx};
  CompressionOutputStream* out_;
};

// Decompresses byte stream produced by Zstd compressor.
class ZstdDecompressor : public Decompressor {
 public:
  bool Decompress(const void* src, std::size_t size,
                  CompressionOutputStream* out) override;
  bool Decompress(const NoncontiguousBuffer& src,
                  CompressionOutputStream* out) override;

 private:
  bool Init(CompressionOutputStream* out);
  bool Append(const void* buffer, std::size_t size);
  bool Flush();

 private:
  std::unique_ptr<ZSTD_DStream, decltype(&ZSTD_freeDStream)> ctx_{
      ZSTD_createDStream(), &ZSTD_freeDStream};
  CompressionOutputStream* out_ = nullptr;
  bool need_flush_;
};

}  // namespace flare::compression

#endif  // FLARE_BASE_COMPRESSION_ZSTD_H_
