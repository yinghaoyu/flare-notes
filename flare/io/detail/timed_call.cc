#include "flare/io/detail/timed_call.h"

#include "gflags/gflags.h"

DEFINE_bool(flare_io_dump_slow_calls, true,
            "If enabled, Flare prints a warning message (at most one per "
            "second) when certain operation takes too long. This might help "
            "when debugging latency issues.");

namespace flare::io::detail {}  // namespace flare::io::detail
