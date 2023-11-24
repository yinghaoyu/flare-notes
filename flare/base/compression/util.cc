#include "flare/base/compression/util.h"

namespace flare::compression {

bool CopyDataToCompressionOutputStream(CompressionOutputStream* out,
                                       const void* data, std::size_t size) {
  if (size == 0) {
    return true;
  }
  std::size_t current_pos = 0;
  std::size_t left_to_copy = size;
  while (true) {
    void* next_data;
    std::size_t next_size;
    if (FLARE_UNLIKELY(!out->Next(&next_data, &next_size))) {
      return false;
    }

    if (left_to_copy <= next_size) {
      // Get more space than we need to copy, finish copying.
      memcpy(next_data, reinterpret_cast<const char*>(data) + current_pos,
             left_to_copy);
      out->BackUp(next_size - left_to_copy);
      return true;
    } else {
      // Next data is not big enough, we copy as much as possible,
      // and continue next turn.
      memcpy(next_data, reinterpret_cast<const char*>(data) + current_pos,
             next_size);
      current_pos += next_size;
      left_to_copy -= next_size;
    }
  }
  FLARE_UNREACHABLE();
}

}  // namespace flare::compression
