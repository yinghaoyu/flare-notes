#include "flare/base/internal/biased_mutex.h"

#include "benchmark/benchmark.h"

// Run on (76 X 2494.14 MHz CPU s)
// CPU Caches:
//   L1 Data 32K (x76)
//   L1 Instruction 32K (x76)
//   L2 Unified 4096K (x76)
// Load Average: 2.07, 1.07, 0.64
// ---------------------------------------------------------------------------
// Benchmark                                 Time             CPU   Iterations
// ---------------------------------------------------------------------------
// Benchmark_BiasedMutexBlessedLock       1.80 ns         1.80 ns    388539779

namespace flare::internal {

BiasedMutex biased_mutex;

void Benchmark_BiasedMutexBlessedLock(benchmark::State& state) {
  while (state.KeepRunning()) {
    // <+23>: lea    0x105292(%rip),%rax      # `biased_mutex`
    // <+30>: movb   $0x1,(%rax)
    // <+33>: movzbl 0x1(%rax),%edx
    // <+37>: test   %dl,%dl
    // <+39>: jne    0x40a380                 # `LockSlow()`
    // <+41>: movb   $0x1,0x2(%rax)           # `unlock()`
    // <+45>: movb   $0x0,(%rax)

    std::scoped_lock _(*biased_mutex.blessed_side());
  }
}

BENCHMARK(Benchmark_BiasedMutexBlessedLock);

}  // namespace flare::internal
