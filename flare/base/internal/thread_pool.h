#ifndef FLARE_BASE_INTERNAL_THREAD_POOL_H_
#define FLARE_BASE_INTERNAL_THREAD_POOL_H_

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

#include "flare/base/function.h"

namespace flare::internal {

// FOR INTERNAL USE ONLY.
//
// If you want to run something concurrently, start a fiber by `Async` instead.
// This task pool is NOT OPTIMIZED AT ALL, and almost always fails to perform
// comparatively to fiber runtime.
class ThreadPool {
 public:
  explicit ThreadPool(std::size_t workers, const std::vector<int>& affinity,
                      int nice_value);
  void QueueJob(Function<void()>&& job);
  void Stop();
  void Join();

 private:
  void WorkerProc();

 private:
  std::atomic<bool> exiting_{false};
  std::vector<std::thread> workers_;

  std::mutex lock_;
  std::condition_variable cv_;
  std::queue<Function<void()>> jobs_;
};

}  // namespace flare::internal

#endif  // FLARE_BASE_INTERNAL_THREAD_POOL_H_
