#include "flare/base/compression/zstd.h"

#include <algorithm>

namespace flare::compression {

FLARE_COMPRESSION_REGISTER_COMPRESSOR("zstd", ZstdCompressor);
FLARE_COMPRESSION_REGISTER_DECOMPRESSOR("zstd", ZstdDecompressor);

bool ZstdCompressor::Compress(const void* src, std::size_t size,
                              CompressionOutputStream* out) {
  bool ok = Init(out);
  ok &= Append(src, size);
  ok &= Flush();
  out_ = nullptr;
  return ok;
}

bool ZstdCompressor::Compress(const NoncontiguousBuffer& bytes,
                              CompressionOutputStream* out) {
  bool zstd_ok = Init(out);
  std::size_t left = bytes.ByteSize();
  for (auto iter = bytes.begin(); zstd_ok && iter != bytes.end() && left;
       ++iter) {
    auto len = std::min(left, iter->size());
    zstd_ok &= Append(iter->data(), len);
    left -= len;
  }
  zstd_ok &= Flush();
  out_ = nullptr;
  return zstd_ok;
}

bool ZstdCompressor::Init(CompressionOutputStream* out) {
  FLARE_CHECK(!out_);
  ZSTD_CCtx_reset(ctx_.get(), ZSTD_reset_session_and_parameters);
  out_ = out;
  return true;
}

bool ZstdCompressor::Append(const void* buffer, std::size_t size) {
  FLARE_CHECK(ctx_);
  FLARE_CHECK(out_);

  ZSTD_inBuffer in_ref = {.src = buffer, .size = size, .pos = 0};

  while (in_ref.pos != in_ref.size) {
    void* next_buffer;
    std::size_t buffer_size;
    if (!out_->Next(&next_buffer, &buffer_size)) {
      return false;
    }

    ZSTD_outBuffer out_ref = {
        .dst = next_buffer, .size = buffer_size, .pos = 0};

    auto result =
        ZSTD_compressStream2(ctx_.get(), &out_ref, &in_ref, ZSTD_e_continue);
    if (ZSTD_isError(result)) {
      return false;
    }
    out_->BackUp(buffer_size - out_ref.pos);
  }

  return true;
}

bool ZstdCompressor::Flush() {
  FLARE_CHECK(ctx_);
  FLARE_CHECK(out_);

  while (true) {
    void* next_buffer;
    std::size_t buffer_size;
    if (!out_->Next(&next_buffer, &buffer_size)) {
      return false;
    }

    // Nothing to compress, we're here only to flush its internal buffer.
    ZSTD_inBuffer in_ref = {};
    ZSTD_outBuffer out_ref = {
        .dst = next_buffer, .size = buffer_size, .pos = 0};
    auto result =
        ZSTD_compressStream2(ctx_.get(), &out_ref, &in_ref, ZSTD_e_end);
    if (ZSTD_isError(result)) {
      return false;
    }
    out_->BackUp(buffer_size - out_ref.pos);
    if (result == 0) {  // Fully flushed then.
      break;
    }
  }
  return true;
}

// ZstdDecompressor

bool ZstdDecompressor::Decompress(const void* src, std::size_t size,
                                  CompressionOutputStream* out) {
  bool ok = Init(out);
  ok &= Append(src, size);
  ok &= Flush();
  out_ = nullptr;
  return ok;
}

bool ZstdDecompressor::Decompress(const NoncontiguousBuffer& nb,
                                  CompressionOutputStream* out) {
  bool zstd_ok = Init(out);
  std::size_t left = nb.ByteSize();
  for (auto iter = nb.begin(); zstd_ok && iter != nb.end() && left; ++iter) {
    auto len = std::min(left, iter->size());
    zstd_ok &= Append(iter->data(), len);
    left -= len;
  }
  zstd_ok &= Flush();
  out_ = nullptr;
  return zstd_ok;
}

bool ZstdDecompressor::Init(CompressionOutputStream* out) {
  FLARE_CHECK(!out_);
  ZSTD_DCtx_reset(ctx_.get(), ZSTD_reset_session_and_parameters);
  out_ = out;
  need_flush_ = false;
  return true;
}

bool ZstdDecompressor::Append(const void* buffer, std::size_t size) {
  FLARE_CHECK(ctx_);
  FLARE_CHECK(out_);

  ZSTD_inBuffer in_ref{.src = buffer, .size = size, .pos = 0};

  while (in_ref.pos != in_ref.size) {
    void* next_buffer;
    std::size_t buffer_size;
    if (!out_->Next(&next_buffer, &buffer_size)) {
      return false;
    }

    ZSTD_outBuffer out_ref = {
        .dst = next_buffer, .size = buffer_size, .pos = 0};
    auto result = ZSTD_decompressStream(ctx_.get(), &out_ref, &in_ref);
    if (ZSTD_isError(result)) {
      return false;
    }
    out_->BackUp(buffer_size - out_ref.pos);
    need_flush_ = result != 0;
  }

  return true;
}

bool ZstdDecompressor::Flush() {
  if (!need_flush_) {
    return true;
  }

  FLARE_CHECK(ctx_);
  FLARE_CHECK(out_);

  while (true) {
    void* next_buffer;
    std::size_t buffer_size;
    if (!out_->Next(&next_buffer, &buffer_size)) {
      return false;
    }

    ZSTD_inBuffer in_ref = {};  // Nothing in input.
    ZSTD_outBuffer out_ref{.dst = next_buffer, .size = buffer_size, .pos = 0};

    auto result = ZSTD_decompressStream(ctx_.get(), &out_ref, &in_ref);
    if (ZSTD_isError(result)) {
      return false;
    }
    out_->BackUp(buffer_size - out_ref.pos);
    if (result == 0) {
      break;
    }
    // Nothing is flushed? It's likely a bug in zstd then. (I do see this occur
    // in practice.)
    if (out_ref.pos == 0) {
      FLARE_LOG_ERROR_EVERY_SECOND(
          "Unexpected: Nothing is flushed from zstd's internal buffer yet a "
          "non-zero value is returned.");
      return false;
    }
  }
  return true;
}

}  // namespace flare::compression
