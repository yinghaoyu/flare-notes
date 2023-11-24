#ifndef FLARE_BASE_COMPRESSION_H_
#define FLARE_BASE_COMPRESSION_H_

#include <memory>
#include <optional>
#include <string_view>

#include "flare/base/compression/compression.h"

namespace flare {

// Name is the compression_algorithm and should already registered by
// FLARE_COMPRESSION_REGISTER_COMPRESSOR/FLARE_COMPRESSION_REGISTER_DECOMPRESSOR.
std::unique_ptr<Decompressor> MakeDecompressor(std::string_view name);

std::unique_ptr<Compressor> MakeCompressor(std::string_view name);

std::optional<NoncontiguousBuffer> Compress(Compressor* compressor,
                                            const NoncontiguousBuffer& nb);
std::optional<NoncontiguousBuffer> Compress(Compressor* compressor,
                                            std::string_view body);
bool Compress(Compressor* compressor, const NoncontiguousBuffer& nb,
              NoncontiguousBufferBuilder* builder);
bool Compress(Compressor* compressor, std::string_view body,
              NoncontiguousBufferBuilder* builder);

std::optional<NoncontiguousBuffer> Decompress(Decompressor* decompressor,
                                              const NoncontiguousBuffer& nb);
std::optional<NoncontiguousBuffer> Decompress(Decompressor* decompressor,
                                              std::string_view body);
bool Decompress(Decompressor* decompressor, const NoncontiguousBuffer& nb,
                NoncontiguousBufferBuilder* builder);
bool Decompress(Decompressor* decompressor, std::string_view body,
                NoncontiguousBufferBuilder* builder);

}  // namespace flare

#endif  // FLARE_BASE_COMPRESSION_H_
