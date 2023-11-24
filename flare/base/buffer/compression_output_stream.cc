#include "flare/base/buffer/compression_output_stream.h"

namespace flare {

NoncontiguousBufferCompressionOutputStream::
    NoncontiguousBufferCompressionOutputStream(
        NoncontiguousBufferBuilder* builder)
    : builder_(builder) {}

NoncontiguousBufferCompressionOutputStream::
    ~NoncontiguousBufferCompressionOutputStream() {
  Flush();
}

void NoncontiguousBufferCompressionOutputStream::Flush() {
  if (using_bytes_) {
    builder_->MarkWritten(using_bytes_);
    using_bytes_ = 0;  // Not necessary, strictly speaking.
  }
}

bool NoncontiguousBufferCompressionOutputStream::Next(
    void** data, std::size_t* size) noexcept {
  if (!builder_) {
    return false;
  }
  if (using_bytes_) {
    builder_->MarkWritten(using_bytes_);
  }
  *data = builder_->data();
  *size = builder_->SizeAvailable();
  using_bytes_ = *size;
  FLARE_CHECK(*size);
  return true;
}

void NoncontiguousBufferCompressionOutputStream::BackUp(
    std::size_t count) noexcept {
  using_bytes_ -= count;
}

}  // namespace flare
