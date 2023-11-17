#ifndef FLARE_BASE_OBJECT_POOL_GLOBAL_H_
#define FLARE_BASE_OBJECT_POOL_GLOBAL_H_

#include "flare/base/object_pool/types.h"

// Extra requirement on `PoolTraits<T>`:
//
// - Not implemented yet.

// `PoolType::Global`
namespace flare::object_pool::detail::global {

void* Get(const TypeDescriptor& desc);
void Put(const TypeDescriptor& desc, void* ptr);

}  // namespace flare::object_pool::detail::global

#endif  // FLARE_BASE_OBJECT_POOL_GLOBAL_H_
