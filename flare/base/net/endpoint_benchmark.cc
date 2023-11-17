#include "flare/base/net/endpoint.h"

#include "benchmark/benchmark.h"

// Run on (76 X 2494.14 MHz CPU s)
// CPU Caches:
//   L1 Data 32K (x76)
//   L1 Instruction 32K (x76)
//   L2 Unified 4096K (x76)
// Load Average: 0.41, 2.21, 3.39
// ---------------------------------------------------------------------
// Benchmark                           Time             CPU   Iterations
// ---------------------------------------------------------------------
// Benchmark_EndpointCopyIPv4       1.79 ns         1.78 ns    393462614

namespace flare {

Endpoint v;

void Benchmark_EndpointCopyIPv4(benchmark::State& state) {
  auto ep = EndpointFromIpv4("127.0.0.1", 1234);
  while (state.KeepRunning()) {
    // Doesn't look too good, TBH.

    // ... <+143>: cmpl   $0x1c,0x1c(%rdi)
    // ... <+147>: ja     0x40f6f0
    // ... <+149>: cmpl   $0x1c,-0x24(%rbp)
    // ... <+153>: ja     0x40f6f0
    // ... <+155>: movdqa (%r12),%xmm0
    // ... <+161>: movdqa 0x10(%r12),%xmm1
    // ... <+168>: movups %xmm0,(%rdi)
    // ... <+171>: movups %xmm1,0x10(%rdi)
    v = ep;
  }
}

BENCHMARK(Benchmark_EndpointCopyIPv4);

}  // namespace flare
