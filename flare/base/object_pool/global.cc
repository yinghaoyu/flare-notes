#include "flare/base/object_pool/global.h"

#include "flare/base/logging.h"

namespace flare::object_pool::detail::global {

void* Get(const TypeDescriptor& desc) { FLARE_NOT_IMPLEMENTED(); }

void Put(const TypeDescriptor& desc, void* ptr) { FLARE_NOT_IMPLEMENTED(); }

}  // namespace flare::object_pool::detail::global
