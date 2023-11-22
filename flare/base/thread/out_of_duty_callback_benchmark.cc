#include "flare/base/thread/out_of_duty_callback.h"

#include <chrono>

#include "benchmark/benchmark.h"

using namespace std::literals;

// Not optimized yet. TODO(luobogao): Optimize it.

// Run on (76 X 2494.14 MHz CPU s)
// CPU Caches:
//   L1 Data 32K (x76)
//   L1 Instruction 32K (x76)
//   L2 Unified 4096K (x76)
// Load Average: 4.32, 7.69, 14.99
// ----------------------------------------------------------------
// Benchmark                      Time             CPU   Iterations
// ----------------------------------------------------------------
// Benchmark_Empty             6.19 ns         6.19 ns    112959275
// Benchmark_One               6.81 ns         6.81 ns    102790403
// Benchmark_OneThousand       8.67 ns         8.64 ns     82970175

namespace flare {

void Benchmark_Empty(benchmark::State& state) {
  while (state.KeepRunning()) {
    NotifyThreadOutOfDutyCallbacks();
  }
}

BENCHMARK(Benchmark_Empty);

void Benchmark_One(benchmark::State& state) {
  SetThreadOutOfDutyCallback([] {}, 1ms);
  while (state.KeepRunning()) {
    NotifyThreadOutOfDutyCallbacks();
  }
}

BENCHMARK(Benchmark_One);

void Benchmark_OneThousand(benchmark::State& state) {
  for (int i = 0; i != 1000; ++i) {
    SetThreadOutOfDutyCallback([] {}, 1ms);
  }
  while (state.KeepRunning()) {
    NotifyThreadOutOfDutyCallbacks();
  }
}

BENCHMARK(Benchmark_OneThousand);

}  // namespace flare
