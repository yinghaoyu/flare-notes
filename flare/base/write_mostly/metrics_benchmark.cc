#include "flare/base/write_mostly/metrics.h"

#include "benchmark/benchmark.h"

// Run on (76 X 2494.14 MHz CPU s)
// CPU Caches:
//   L1 Data 32K (x76)
//   L1 Instruction 32K (x76)
//   L2 Unified 4096K (x76)
// Load Average: 1.11, 33.57, 64.22
// ------------------------------------------------------------------
// Benchmark                        Time             CPU   Iterations
// ------------------------------------------------------------------
// Benchmark_MetricsUpdate       10.1 ns         10.1 ns     69393819

namespace flare::write_mostly {

void Benchmark_MetricsReport(benchmark::State& state) {
  WriteMostlyMetrics<int> metrics;
  while (state.KeepRunning()) {
    metrics.Report(1);
  }
}

BENCHMARK(Benchmark_MetricsReport);

}  // namespace flare::write_mostly
