#include "flare/fiber/detail/assembly.h"

#include "benchmark/benchmark.h"

// Run on (76 X 2494.14 MHz CPU s)
// CPU Caches:
//   L1 Data 32K (x76)
//   L1 Instruction 32K (x76)
//   L2 Unified 4096K (x76)
// Load Average: 33.41, 15.61, 12.01
// --------------------------------------------------------------------
// Benchmark                          Time             CPU   Iterations
// --------------------------------------------------------------------
// Benchmark_Pause                 69.8 ns         69.8 ns     10017652
// Benchmark_CountNonZeros         1.08 ns         1.08 ns    648266187
// Benchmark_BuiltinPopcount       3.24 ns         3.24 ns    216115326

namespace flare::fiber::detail {

volatile int x;
volatile int y = 0x7fff'ffff;

void Benchmark_Pause(benchmark::State& state) {
  while (state.KeepRunning()) {
    Pause<16>();
  }
}

BENCHMARK(Benchmark_Pause);

void Benchmark_CountNonZeros(benchmark::State& state) {
  while (state.KeepRunning()) {
    x = CountNonZeros(y);
  }
}

BENCHMARK(Benchmark_CountNonZeros);

void Benchmark_BuiltinPopcount(benchmark::State& state) {
  while (state.KeepRunning()) {
    x = __builtin_popcountll(y);
  }
}

BENCHMARK(Benchmark_BuiltinPopcount);

}  // namespace flare::fiber::detail
