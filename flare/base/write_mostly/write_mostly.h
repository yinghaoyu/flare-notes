#ifndef FLARE_BASE_WRITE_MOSTLY_WRITE_MOSTLY_H_
#define FLARE_BASE_WRITE_MOSTLY_WRITE_MOSTLY_H_

#include <chrono>
#include <memory>
#include <mutex>

#include "flare/base/align.h"
#include "flare/base/thread/thread_local.h"

namespace flare {

// Use Thread local WriteBuffer.
// Value may be read at the same time as the update.
// Users need to ensure their own security (such as locking or atomic
// variables). Built-in (non-atomic) integer types usually satisfy this
// constraint
template <class Traits>
class WriteMostly {
  using T = typename Traits::Type;

 public:
  WriteMostly()
      : tls_buffer_(
            [this]() { return std::make_unique<WriteBufferWrapper>(this); }) {
    Traits::Copy(Traits::kWriteBufferInitializer, &exited_thread_combined_);
  }

  void Update(const T& value) noexcept {
    Traits::Update(&tls_buffer_.Get()->buffer_, value);
  }

  // Full Read and reset atomically.
  // Only if Traits implements Purge method, you can call this method.
  T Purge() noexcept { return PurgeHelper<Traits>(nullptr); }

  // Not atomically
  void Reset() noexcept {
    {
      std::unique_lock<std::mutex> lock(mutex);
      exited_thread_combined_ = Traits::kWriteBufferInitializer;
    }
    tls_buffer_.ForEach([&](auto&& wrapper) {
      wrapper->buffer_ = Traits::kWriteBufferInitializer;
    });
  }

  T Read() const noexcept {
    WriteBuffer wb;
    Traits::Copy(exited_thread_combined_, &wb);
    tls_buffer_.ForEach(
        [&](auto&& wrapper) { Traits::Merge(&wb, wrapper->buffer_); });
    return Traits::Read(wb);
  }

 private:
  using WriteBuffer = typename Traits::WriteBuffer;

  template <typename C>
  T PurgeHelper(decltype(&C::Purge)) {
    WriteBuffer wb = Traits::Purge(&exited_thread_combined_);
    tls_buffer_.ForEach([&](auto&& wrapper) {
      Traits::Merge(&wb, Traits::Purge(&wrapper->buffer_));
    });
    return Traits::Read(wb);
  }

  // Merge to exited_thread_combined_ when thread exits.
  struct alignas(hardware_destructive_interference_size) WriteBufferWrapper {
    explicit WriteBufferWrapper(WriteMostly* parent) : parent_(parent) {
      Traits::Copy(Traits::kWriteBufferInitializer, &buffer_);
    }

    ~WriteBufferWrapper() {
      std::unique_lock<std::mutex> lock(parent_->mutex);
      Traits::Merge(&parent_->exited_thread_combined_, buffer_);
    }

    WriteMostly* parent_;
    WriteBuffer buffer_;
  };

  mutable WriteBuffer exited_thread_combined_;
  ThreadLocal<WriteBufferWrapper> tls_buffer_;
  mutable std::mutex mutex;
};

}  // namespace flare

#endif  // FLARE_BASE_WRITE_MOSTLY_WRITE_MOSTLY_H_
