#include "flare/base/buffer/packing.h"

#include "flare/base/buffer/packing.pb.h"
#include "flare/base/endian.h"
#include "flare/base/logging.h"

namespace flare {

namespace {

void WriteHeader(const detail::buffer::PackHeader& header,
                 NoncontiguousBufferBuilder* builder) {
  auto serialized = header.SerializeAsString();
  std::uint32_t size = serialized.size();
  ToLittleEndian(&size);
  builder->Append(&size, sizeof(size));
  builder->Append(serialized);
}

// `buffer` is left in a inconsistent state on failure.
std::optional<detail::buffer::PackHeader> VerifyAndParseHeader(
    NoncontiguousBuffer* buffer, bool name_expected) {
  std::uint32_t size;
  if (buffer->ByteSize() < sizeof(size)) {
    return std::nullopt;
  }
  FlattenToSlow(*buffer, &size, sizeof(size));
  FromLittleEndian(&size);
  buffer->Skip(sizeof(size));

  if (buffer->ByteSize() < size) {
    return std::nullopt;
  }
  auto flatten = FlattenSlow(*buffer, size);
  buffer->Skip(size);

  detail::buffer::PackHeader header;
  if (!header.ParseFromString(flatten)) {
    return std::nullopt;
  }
  if (!name_expected && !header.names().empty()) {
    return std::nullopt;
  }
  if (name_expected && header.names().size() != header.sizes().size()) {
    return std::nullopt;
  }
  std::size_t body_size = 0;
  for (auto&& e : header.sizes()) {
    body_size += e;
  }
  if (buffer->ByteSize() != body_size) {
    return std::nullopt;
  }
  return header;
}

}  // namespace

void WriteKeyedNoncontiguousBuffers(
    const std::vector<std::pair<std::string, NoncontiguousBuffer>>& kvs,
    NoncontiguousBufferBuilder* builder) {
  detail::buffer::PackHeader header;
  for (auto&& [k, v] : kvs) {
    header.add_names(std::string(k));
    header.add_sizes(v.ByteSize());
  }
  WriteHeader(header, builder);
  for (auto&& [_, v] : kvs) {
    builder->Append(v);
  }
}

NoncontiguousBuffer WriteKeyedNoncontiguousBuffers(
    const std::vector<std::pair<std::string, NoncontiguousBuffer>>& kvs) {
  NoncontiguousBufferBuilder builder;
  WriteKeyedNoncontiguousBuffers(kvs, &builder);
  return builder.DestructiveGet();
}

std::optional<std::vector<std::pair<std::string, NoncontiguousBuffer>>>
TryParseKeyedNoncontiguousBuffers(NoncontiguousBuffer buffer) {
  auto header = VerifyAndParseHeader(&buffer, true);
  if (!header) {
    return std::nullopt;
  }
  if (header->sizes().size() != header->names().size()) {
    return std::nullopt;
  }
  std::vector<std::pair<std::string, NoncontiguousBuffer>> result;
  for (int i = 0; i != header->sizes().size(); ++i) {
    FLARE_CHECK_LT(i, header->names().size());
    result.emplace_back(header->names(i), buffer.Cut(header->sizes(i)));
  }
  return result;
}

void WriteNoncontiguousBufferArray(
    const std::vector<NoncontiguousBuffer>& buffers,
    NoncontiguousBufferBuilder* builder) {
  detail::buffer::PackHeader header;
  for (auto&& v : buffers) {
    header.add_sizes(v.ByteSize());
  }
  WriteHeader(header, builder);
  for (auto&& v : buffers) {
    builder->Append(v);
  }
}

NoncontiguousBuffer WriteNoncontiguousBufferArray(
    const std::vector<NoncontiguousBuffer>& buffers) {
  NoncontiguousBufferBuilder builder;
  WriteNoncontiguousBufferArray(buffers, &builder);
  return builder.DestructiveGet();
}

std::optional<std::vector<NoncontiguousBuffer>>
TryParseNoncontiguousBufferArray(NoncontiguousBuffer buffer) {
  auto header = VerifyAndParseHeader(&buffer, false);
  if (!header) {
    return std::nullopt;
  }
  if (!header->names().empty()) {
    return std::nullopt;
  }
  std::vector<NoncontiguousBuffer> result;
  for (int i = 0; i != header->sizes().size(); ++i) {
    FLARE_CHECK_LT(i, header->sizes().size());
    result.emplace_back(buffer.Cut(header->sizes(i)));
  }
  return result;
}

}  // namespace flare
