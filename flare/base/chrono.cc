#include "flare/base/chrono.h"

#include <time.h>

#include <chrono>
#include <thread>

using namespace std::literals;

namespace flare {

namespace {

template <class T>
inline T ReadClock(int type) {
  timespec ts;
  clock_gettime(type, &ts);
  return T((ts.tv_sec * 1'000'000'000LL + ts.tv_nsec) * 1ns);
}

}  // namespace

namespace detail::chrono {

void UpdateCoarseTimestamps() {
  async_updated_timestamps.steady_clock_time_since_epoch.store(
      std::chrono::steady_clock::now().time_since_epoch(),
      std::memory_order_relaxed);
  async_updated_timestamps.system_clock_time_since_epoch.store(
      std::chrono::system_clock::now().time_since_epoch(),
      std::memory_order_relaxed);
}

CoarseClockInitializer::CoarseClockInitializer() {
  UpdateCoarseTimestamps();  // Initialize timestamp immediately.

  // Indeed we _can_ use `TimeKeeper` here to register a timer. However, that
  // simply carries too many dependencies to the rest of the framework. To keep
  // things simple, we use a dedicated thread here.
  worker_ = std::thread([this] {
    while (!exiting_.load(std::memory_order_relaxed)) {
      std::this_thread::sleep_for(4ms);
      UpdateCoarseTimestamps();
    }
  });
}

CoarseClockInitializer::~CoarseClockInitializer() {
  exiting_.store(true, std::memory_order_relaxed);
  worker_.join();
}

}  // namespace detail::chrono

std::chrono::steady_clock::time_point ReadSteadyClock() {
  return ReadClock<std::chrono::steady_clock::time_point>(CLOCK_MONOTONIC);
}

std::chrono::system_clock::time_point ReadSystemClock() {
  return ReadClock<std::chrono::system_clock::time_point>(CLOCK_REALTIME);
}

}  // namespace flare
