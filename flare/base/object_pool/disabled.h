#ifndef FLARE_BASE_OBJECT_POOL_DISABLED_H_
#define FLARE_BASE_OBJECT_POOL_DISABLED_H_

#include "flare/base/object_pool/types.h"

// Extra requirement on `PoolTraits<T>`:
//
// - No additional parameters are required for pool type `Disabled`.

// Backend implementation for `PoolType::Disabled`.
namespace flare::object_pool::detail::disabled {

void* Get(const TypeDescriptor& desc);
void Put(const TypeDescriptor& desc, void* ptr);

}  // namespace flare::object_pool::detail::disabled

#endif  // FLARE_BASE_OBJECT_POOL_DISABLED_H_
