#include "flare/base/write_mostly/basic_ops.h"

#include "benchmark/benchmark.h"

// Run on (76 X 2494.14 MHz CPU s)
// CPU Caches:
//   L1 Data 32K (x76)
//   L1 Instruction 32K (x76)
//   L2 Unified 4096K (x76)
// Load Average: 2.33, 3.38, 7.40
// --------------------------------------------------------------------------
// Benchmark                                Time             CPU   Iterations
// --------------------------------------------------------------------------
// Benchmark_CounterAdd                  2.94 ns         2.94 ns    238091910
// Benchmark_CounterAdd/threads:12      0.248 ns         2.95 ns    237667920
// Benchmark_MaxerUpdate                 2.98 ns         2.94 ns    254692234

namespace flare {

void Benchmark_CounterAdd(benchmark::State& state) {
  static WriteMostlyCounter<int> adder;
  while (state.KeepRunning()) {
    adder.Add(1);
  }
}

BENCHMARK(Benchmark_CounterAdd);
BENCHMARK(Benchmark_CounterAdd)->Threads(12);

void Benchmark_MaxerUpdate(benchmark::State& state) {
  WriteMostlyMaxer<int> maxer;
  while (state.KeepRunning()) {
    maxer.Update(1);
  }
}

BENCHMARK(Benchmark_MaxerUpdate);

}  // namespace flare
