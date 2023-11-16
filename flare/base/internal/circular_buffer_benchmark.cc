#include "flare/base/internal/circular_buffer.h"

#include <vector>

#include "benchmark/benchmark.h"

// Run on (76 X 2494.14 MHz CPU s)
// CPU Caches:
//   L1 Data 32K (x76)
//   L1 Instruction 32K (x76)
//   L2 Unified 4096K (x76)
// Load Average: 0.81, 0.61, 0.57
// -----------------------------------------------------------------------
// Benchmark                             Time             CPU   Iterations
// -----------------------------------------------------------------------
// Benchmark_CircularBufferPush       2.72 ns         2.72 ns    258495369

namespace flare::internal {

CircularBuffer<int> buffer(131072);

void Benchmark_CircularBufferPush(benchmark::State& state) {
  while (state.KeepRunning()) {
    // <+47>: mov    0x10(%rbx),%rcx     # Load `head`
    // <+51>: mov    (%rbx),%rdx
    // <+54>: lea    0x1(%rcx),%rax      # `head + 1 % capacity`
    // <+58>: mov    %rax,%rsi           # This is really slow, if we can make
    // <+61>: sub    %rdx,%rsi           # sure `capacity_` is a power of two, a
    // <+64>: cmp    %rdx,%rax           # single `and` should be enought here.
    //                                   # (Reducing time per round to ~2.31ns.)
    //
    // <+67>: mov    0x18(%rbx),%rdx     # Load `tail`
    // <+71>: cmovae %rsi,%rax           # Still `head + 1 % capacity`.
    // <+75>: cmp    %rax,%rdx           # Full?
    // <+78>: je     0x40a430            # `FLARE_UNLIKELY(...) { ... }`
    // <+80>: mov    0x8(%rbx),%rdx
    // <+84>: movl   $0x1,(%rdx,%rcx,4)  # Store value pushed.
    // <+91>: mov    %rax,0x10(%rbx)     # ++head
    if (FLARE_UNLIKELY(!buffer.Emplace(1))) {
      state.PauseTiming();
      std::vector<int> drain;
      buffer.Pop(&drain);
      state.ResumeTiming();
    }
  }
}

BENCHMARK(Benchmark_CircularBufferPush);

}  // namespace flare::internal
