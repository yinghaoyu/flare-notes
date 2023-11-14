#include "flare/base/id_alloc.h"

#include "benchmark/benchmark.h"

namespace flare {

struct DummyTraits {
  using Type = std::uint32_t;
  static constexpr auto kMin = 1, kMax = 10000;
  static constexpr auto kBatchSize = 128;
};

void Benchmark_Next(benchmark::State& state) {
  while (state.KeepRunning()) {
    id_alloc::Next<DummyTraits>();
  }
}

BENCHMARK(Benchmark_Next);

}  // namespace flare
