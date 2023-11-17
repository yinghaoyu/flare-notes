#ifndef FLARE_BASE_WRITE_MOSTLY_H_
#define FLARE_BASE_WRITE_MOSTLY_H_

// For perf. sensitive scenarios, we provides some optimized-for-writer classes
// to do basic statistics.
//
// See headers below for more details.
#include "flare/base/write_mostly/basic_ops.h"
#include "flare/base/write_mostly/metrics.h"

// In case you want to specialize for your own type, we also provide this basic
// template.
#include "flare/base/write_mostly/write_mostly.h"

#endif  // FLARE_BASE_WRITE_MOSTLY_H_
