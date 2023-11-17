#include "flare/base/thread/thread_local/ref_counted.h"

#include "benchmark/benchmark.h"

// Run on (76 X 2494.14 MHz CPU s)
// CPU Caches:
//   L1 Data 32K (x76)
//   L1 Instruction 32K (x76)
//   L2 Unified 4096K (x76)
// Load Average: 7.52, 10.18, 8.81
// ------------------------------------------------------------------
// Benchmark                        Time             CPU   Iterations
// ------------------------------------------------------------------
// Benchmark_RefCountedGet       1.94 ns         1.94 ns    360696033

namespace flare {

struct C : public RefCounted<C> {
  int v = 123;
};

void Benchmark_RefCountedGet(benchmark::State& state) {
  static internal::ThreadLocalRefCounted<C> tls;

  tls->v = 12345;
  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(tls->v);
  }
}

BENCHMARK(Benchmark_RefCountedGet);

}  // namespace flare
