#ifndef FLARE_BASE_INTERNAL_DPC_H_
#define FLARE_BASE_INTERNAL_DPC_H_

#include "flare/base/function.h"

namespace flare::internal {

// Deferred procedure calls.
//
// For better responsiveness (in critical path), you can schedule jobs which
// needs not to be done immediately to be executed later by queuing a DPC.
//
// Insipred by DPC of Windows NT Kernel.
//
// Scheduling DPC is relative fast, but keep in mind that DPC's execution can be
// deferred arbitrarily.
//
// Internally DPC queues is flushed periodically, and then, run by
// `BackgroundTaskHost`, so be careful not to overload the background workers.
void QueueDpc(Function<void()>&& cb) noexcept;

// Flush all pending DPCs to background task host.
void FlushDpcs() noexcept;

}  // namespace flare::internal

#endif  // FLARE_BASE_INTERNAL_DPC_H_

