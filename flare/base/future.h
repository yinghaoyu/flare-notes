#ifndef FLARE_BASE_FUTURE_H_
#define FLARE_BASE_FUTURE_H_

#include "flare/base/future/future-impl.h"
#include "flare/base/future/future.h"
#include "flare/base/future/promise-impl.h"
#include "flare/base/future/promise.h"
#include "flare/base/future/utils.h"

namespace flare {

using future::Future;
using future::futurize_tuple;
using future::futurize_values;
using future::MakeReadyFuture;
using future::Promise;
using future::Split;
using future::WhenAll;
using future::WhenAny;

// `flare::future::BlockingGet` is NOT imported into `flare::`.
//
// If you need to wait for asynchronous operation in _pthread environment_,
// qualify your call to `BlockingGet` with `flare::future::`.

}  // namespace flare

#endif  // FLARE_BASE_FUTURE_H_
