#ifndef FLARE_FIBER_WORK_QUEUE_H_
#define FLARE_FIBER_WORK_QUEUE_H_

#include <queue>

#include "flare/base/function.h"
#include "flare/fiber/condition_variable.h"
#include "flare/fiber/fiber.h"
#include "flare/fiber/mutex.h"

namespace flare::fiber {

// Each work queue consists of a dedicated fiber for running jobs.
//
// Work posted to this queue is run in a FIFO fashion.
class WorkQueue {
 public:
  WorkQueue();

  // Scheduling `cb` for execution.
  void Push(Function<void()>&& cb);

  // Stop the queue.
  void Stop();

  // Wait until all pending works has run.
  void Join();

 private:
  void WorkerProc();

 private:
  Fiber worker_;
  fiber::Mutex lock_;
  fiber::ConditionVariable cv_;
  std::queue<Function<void()>> jobs_;
  bool stopped_ = false;
};

}  // namespace flare::fiber

#endif  // FLARE_FIBER_WORK_QUEUE_H_
