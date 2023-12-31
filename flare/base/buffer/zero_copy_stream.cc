#include "flare/base/buffer/zero_copy_stream.h"

namespace flare {

// NoncontiguousBufferInputStream

NoncontiguousBufferInputStream::NoncontiguousBufferInputStream(
    NoncontiguousBuffer* ref)
    : buffer_(ref) {}

NoncontiguousBufferInputStream::~NoncontiguousBufferInputStream() { Flush(); }

void NoncontiguousBufferInputStream::Flush() { PerformPendingSkips(); }

bool NoncontiguousBufferInputStream::Next(const void** data, int* size) {
  PerformPendingSkips();
  if (buffer_->Empty()) {
    return false;
  }

  auto&& fc = buffer_->FirstContiguous();
  *data = fc.data();
  *size = fc.size();

  // Do not skip this bytes now, as `BackUp` may override this.
  skip_before_read_ = fc.size();
  read_ += fc.size();
  return true;
}

void NoncontiguousBufferInputStream::BackUp(int count) {
  FLARE_CHECK_GE(skip_before_read_, count);
  skip_before_read_ -= count;
  read_ -= count;
}

bool NoncontiguousBufferInputStream::Skip(int count) {
  PerformPendingSkips();

  if (buffer_->ByteSize() < count) {
    return false;
  }
  read_ += count;
  buffer_->Skip(count);
  return true;
}

google::protobuf::int64 NoncontiguousBufferInputStream::ByteCount() const {
  return read_;
}

void NoncontiguousBufferInputStream::PerformPendingSkips() {
  if (skip_before_read_) {
    buffer_->Skip(skip_before_read_);
    skip_before_read_ = 0;
  }
}

// NoncontiguousBufferOutputStream

NoncontiguousBufferOutputStream::NoncontiguousBufferOutputStream(
    NoncontiguousBufferBuilder* builder)
    : builder_(builder) {}

NoncontiguousBufferOutputStream::~NoncontiguousBufferOutputStream() { Flush(); }

void NoncontiguousBufferOutputStream::Flush() {
  if (using_bytes_) {
    builder_->MarkWritten(using_bytes_);
    using_bytes_ = 0;  // Not necessary, strictly speaking.
  }
}

bool NoncontiguousBufferOutputStream::Next(void** data, int* size) {
  if (using_bytes_) {
    builder_->MarkWritten(using_bytes_);
  }
  *data = builder_->data();
  *size = builder_->SizeAvailable();
  using_bytes_ = *size;
  FLARE_CHECK(*size);
  return true;
}

void NoncontiguousBufferOutputStream::BackUp(int count) {
  using_bytes_ -= count;
}

google::protobuf::int64 NoncontiguousBufferOutputStream::ByteCount() const {
  return builder_->ByteSize();
}

}  // namespace flare
