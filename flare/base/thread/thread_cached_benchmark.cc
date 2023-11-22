#include "flare/base/thread/thread_cached.h"

#include "benchmark/benchmark.h"

// Run on (76 X 2494.14 MHz CPU s)
// CPU Caches:
//   L1 Data 32K (x76)
//   L1 Instruction 32K (x76)
//   L2 Unified 4096K (x76)
// Load Average: 12.25, 13.39, 25.46
// --------------------------------------------------------------------
// Benchmark                          Time             CPU   Iterations
// --------------------------------------------------------------------
// Benchmark_ThreadCachedGet       1.80 ns         1.80 ns    388318382

namespace flare {

void Benchmark_ThreadCachedGet(benchmark::State& state) {
  ThreadCached<std::string> str("abcdefg");
  while (state.KeepRunning()) {
    // <+112>: mov  $0xffffffffffffffd0,%rsi
    // <+123>: mov  -0x90(%rbp),%rdi
    // <+133>: cmp  %rdi,%fs:(%rsi)
    // <+137>: jbe  0x40fd88                  # Initialize TLS.
    // <+139>: mov  %fs:0x8(%rsi),%rax        # Load TLS.
    // <+144>: add  %rdi,%rax                 # &tls_cache.version
    // <+147>: mov  -0xa0(%rbp),%rdx          # Global version.
    // <+154>: cmp  %rdx,(%rax)
    // <+157>: jne  0x40fd78                  # Reload cache.
    // <+159>: mov  0x8(%rax),%rax            # We're done.
    benchmark::DoNotOptimize(str.NonIdempotentGet());
  }
}

BENCHMARK(Benchmark_ThreadCachedGet);

}  // namespace flare
