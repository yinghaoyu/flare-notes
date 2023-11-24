#include "flare/base/compression.h"

#include <memory>
#include <optional>
#include <string_view>

#include "flare/base/buffer/compression_output_stream.h"

namespace flare {

std::unique_ptr<Compressor> MakeCompressor(std::string_view name) {
  return compressor_registry.TryNew(name);
}

std::unique_ptr<Decompressor> MakeDecompressor(std::string_view name) {
  return decompressor_registry.TryNew(name);
}

std::optional<NoncontiguousBuffer> Decompress(Decompressor* decompressor,
                                              const NoncontiguousBuffer& nb) {
  NoncontiguousBufferBuilder builder;
  if (!Decompress(decompressor, nb, &builder)) {
    return std::nullopt;
  }
  return builder.DestructiveGet();
}

std::optional<NoncontiguousBuffer> Decompress(Decompressor* decompressor,
                                              std::string_view body) {
  NoncontiguousBufferBuilder builder;
  if (!Decompress(decompressor, body, &builder)) {
    return std::nullopt;
  }
  return builder.DestructiveGet();
}

bool Decompress(Decompressor* decompressor, const NoncontiguousBuffer& nb,
                NoncontiguousBufferBuilder* builder) {
  if (!decompressor) {
    FLARE_LOG_WARNING_EVERY_SECOND("Compressor nullptr");
    return false;
  }
  NoncontiguousBufferCompressionOutputStream out(builder);
  return decompressor->Decompress(nb, &out);
}

bool Decompress(Decompressor* decompressor, std::string_view body,
                NoncontiguousBufferBuilder* builder) {
  if (!decompressor) {
    FLARE_LOG_WARNING_EVERY_SECOND("Compressor nullptr");
    return false;
  }
  NoncontiguousBufferCompressionOutputStream out(builder);
  return decompressor->Decompress(body.data(), body.size(), &out);
}

std::optional<NoncontiguousBuffer> Compress(Compressor* compressor,
                                            const NoncontiguousBuffer& nb) {
  NoncontiguousBufferBuilder builder;
  if (!Compress(compressor, nb, &builder)) {
    return std::nullopt;
  }
  return builder.DestructiveGet();
}

bool Compress(Compressor* compressor, const NoncontiguousBuffer& nb,
              NoncontiguousBufferBuilder* builder) {
  if (!compressor) {
    FLARE_LOG_WARNING_EVERY_SECOND("Compressor nullptr");
    return false;
  }
  NoncontiguousBufferCompressionOutputStream out(builder);
  return compressor->Compress(nb, &out);
}

std::optional<NoncontiguousBuffer> Compress(Compressor* compressor,
                                            std::string_view body) {
  NoncontiguousBufferBuilder builder;
  if (!Compress(compressor, body, &builder)) {
    return std::nullopt;
  }
  return builder.DestructiveGet();
}

bool Compress(Compressor* compressor, std::string_view body,
              NoncontiguousBufferBuilder* builder) {
  if (!compressor) {
    FLARE_LOG_WARNING_EVERY_SECOND("Compressor nullptr");
    return false;
  }
  NoncontiguousBufferCompressionOutputStream out(builder);
  return compressor->Compress(body.data(), body.size(), &out);
}

}  // namespace flare
