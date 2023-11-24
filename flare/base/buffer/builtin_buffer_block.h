#ifndef FLARE_BASE_BUFFER_BUILTIN_BUFFER_BLOCK_H_
#define FLARE_BASE_BUFFER_BUILTIN_BUFFER_BLOCK_H_

#include <array>
#include <chrono>
#include <limits>

#include "flare/base/align.h"
#include "flare/base/buffer/polymorphic_buffer.h"
#include "flare/base/object_pool.h"

namespace flare {

// "Native" buffer.
//
// Use `MakeNativeBufferBlock` to instantiate this class.
class alignas(hardware_destructive_interference_size) NativeBufferBlock
    : public PolymorphicBufferBlock {
 public:
  virtual char* mutable_data() noexcept = 0;
};

// Allocate a buffer block.
//
// Size of the buffer block is determined by GFlags on startup, see
// implementation for detail.
RefPtr<NativeBufferBlock> MakeNativeBufferBlock();

// This buffer references a non-owning memory region.
//
// The buffer creator is responsible for making sure the memory region
// referenced by this object is not mutated during the whole lifetime of this
// object.
//
// This class calls user's callback on destruction. This provides a way for the
// user to know when the buffer being referenced is safe to release.
template <class F>
class ReferencingBufferBlock : public PolymorphicBufferBlock,
                               private F /* EBO */ {
 public:
  explicit ReferencingBufferBlock(const void* ptr, std::size_t size,
                                  F&& completion_cb)
      : F(std::move(completion_cb)), ptr_(ptr), size_(size) {}
  ~ReferencingBufferBlock() { (*this)(); }

  const char* data() const noexcept override {
    return reinterpret_cast<const char*>(ptr_);
  }
  std::size_t size() const noexcept override { return size_; }

 private:
  const void* ptr_;
  std::size_t size_;
};

}  // namespace flare

#endif  // FLARE_BASE_BUFFER_BUILTIN_BUFFER_BLOCK_H_
