#ifndef FLARE_FIBER_DETAIL_RUNNABLE_ENTITY_H_
#define FLARE_FIBER_DETAIL_RUNNABLE_ENTITY_H_

#include "flare/base/casting.h"

namespace flare::fiber::detail {

// Base class for all runnable entities (those recognized by `RunQueue`).
//
// Use `isa<T>` or `dyn_cast<T>` to test its type and convert it to its
// subclass.
//
// `SchedulingGroup` is responsible for converting this object to `FiberEntity`,
// regardless of its current type.
//
// Indeed we can make things more flexible by introducing `virtual void Run()`
// to this base class. That way we can even accept callbacks and behaves like a
// thread pool if necessary. However, I don't see the need for that flexibility
// to warrant its cost.
struct RunnableEntity : ExactMatchCastable {};

}  // namespace flare::fiber::detail

#endif  // FLARE_FIBER_DETAIL_RUNNABLE_ENTITY_H_

