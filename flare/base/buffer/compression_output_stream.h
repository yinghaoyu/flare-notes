#ifndef FLARE_BASE_BUFFER_COMPRESSION_OUTPUT_STREAM_H_
#define FLARE_BASE_BUFFER_COMPRESSION_OUTPUT_STREAM_H_

#include "flare/base/compression/compression.h"

namespace flare {

class NoncontiguousBufferCompressionOutputStream
    : public CompressionOutputStream {
 public:
  explicit NoncontiguousBufferCompressionOutputStream(
      NoncontiguousBufferBuilder* builder);
  ~NoncontiguousBufferCompressionOutputStream() override;

  // Flush internal state. Must be called before touching `builder`.
  //
  // On destruction, we automatically synchronizes with `builder`.
  void Flush();

  bool Next(void** data, std::size_t* size) noexcept override;
  void BackUp(std::size_t count) noexcept override;

 private:
  std::size_t using_bytes_{};
  NoncontiguousBufferBuilder* builder_;
};

}  // namespace flare

#endif  // FLARE_BASE_BUFFER_COMPRESSION_OUTPUT_STREAM_H_
