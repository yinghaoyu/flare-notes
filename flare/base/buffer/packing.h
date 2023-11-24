#ifndef FLARE_BASE_BUFFER_PACKING_H_
#define FLARE_BASE_BUFFER_PACKING_H_

#include <optional>
#include <string>
#include <utility>
#include <vector>

#include "flare/base/buffer.h"

namespace flare {

// Serializes [Key, Buffer]. Order in `kvs` is kept in the resulting buffer.
void WriteKeyedNoncontiguousBuffers(
    const std::vector<std::pair<std::string, NoncontiguousBuffer>>& kvs,
    NoncontiguousBufferBuilder* builder);
NoncontiguousBuffer WriteKeyedNoncontiguousBuffers(
    const std::vector<std::pair<std::string, NoncontiguousBuffer>>& kvs);

// Parses bytes produced by `WriteKeyedNoncontiguousBuffers`.
std::optional<std::vector<std::pair<std::string, NoncontiguousBuffer>>>
TryParseKeyedNoncontiguousBuffers(NoncontiguousBuffer buffer);

// Serializes a series of buffers. Order is kept (as obvious).
void WriteNoncontiguousBufferArray(
    const std::vector<NoncontiguousBuffer>& buffers,
    NoncontiguousBufferBuilder* builder);
NoncontiguousBuffer WriteNoncontiguousBufferArray(
    const std::vector<NoncontiguousBuffer>& buffers);

// Parses bytes produced by `WriteNoncontiguousBufferArray`.
std::optional<std::vector<NoncontiguousBuffer>>
TryParseNoncontiguousBufferArray(NoncontiguousBuffer buffer);

}  // namespace flare

#endif  // FLARE_BASE_BUFFER_PACKING_H_
