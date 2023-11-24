#ifndef FLARE_BASE_COMPRESSION_GZIP_H_
#define FLARE_BASE_COMPRESSION_GZIP_H_

#include <memory>

#include "zlib.h"

#include "flare/base/compression/compression.h"

namespace flare::compression {

class GzipCompressor : public Compressor {
 public:
  bool Compress(const void* src, std::size_t size,
                CompressionOutputStream* out) override;
  bool Compress(const NoncontiguousBuffer& bytes,
                CompressionOutputStream* out) override;

 private:
  bool Append(const void* buffer, std::size_t size);
  bool Flush();
  bool Init(CompressionOutputStream* out);
  bool Release();
  std::unique_ptr<z_stream> stream_;
  CompressionOutputStream* out_ = nullptr;
};

class GzipDecompressor : public Decompressor {
 public:
  bool Decompress(const void* src, std::size_t size,
                  CompressionOutputStream* out) override;
  bool Decompress(const NoncontiguousBuffer& compressed,
                  CompressionOutputStream* out) override;

 private:
  bool Append(const void* buffer, std::size_t size);
  bool Flush();
  bool Init(CompressionOutputStream* out);
  bool Release();
  std::unique_ptr<z_stream> stream_;
  CompressionOutputStream* out_ = nullptr;
};

}  // namespace flare::compression

#endif  // FLARE_BASE_COMPRESSION_GZIP_H_
