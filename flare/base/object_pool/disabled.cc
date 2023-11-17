#include "flare/base/object_pool/disabled.h"

namespace flare::object_pool::detail::disabled {

void* Get(const TypeDescriptor& desc) {
  auto rc = desc.create();
  return rc;
}

void Put(const TypeDescriptor& desc, void* ptr) { desc.destroy(ptr); }

}  // namespace flare::object_pool::detail::disabled
