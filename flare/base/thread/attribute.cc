#include "flare/base/thread/attribute.h"

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <pthread.h>
#include <sched.h>

#include <string>

#include "flare/base/logging.h"

namespace flare {

int TrySetCurrentThreadAffinity(const std::vector<int>& affinity) {
  FLARE_CHECK(!affinity.empty());
  cpu_set_t cpuset;

  CPU_ZERO(&cpuset);
  for (auto&& e : affinity) {
    CPU_SET(e, &cpuset);
  }
  return pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
}

void SetCurrentThreadAffinity(const std::vector<int>& affinity) {
  auto rc = TrySetCurrentThreadAffinity(affinity);
  FLARE_CHECK(rc == 0, "Cannot set thread affinity for thread [{}]: [{}] {}.",
              reinterpret_cast<const void*>(pthread_self()), rc, strerror(rc));
}

std::vector<int> GetCurrentThreadAffinity() {
  cpu_set_t cpuset;
  CPU_ZERO(&cpuset);
  auto rc = pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
  FLARE_CHECK(rc == 0, "Cannot get thread affinity of thread [{}]: [{}] {}.",
              reinterpret_cast<const void*>(pthread_self()), rc, strerror(rc));

  std::vector<int> result;
  for (int i = 0; i != __CPU_SETSIZE; ++i) {
    if (CPU_ISSET(i, &cpuset)) {
      result.push_back(i);
    }
  }
  return result;
}

void SetCurrentThreadName(const std::string& name) {
  auto rc = pthread_setname_np(pthread_self(), name.c_str());
  if (rc != 0) {
    FLARE_LOG_WARNING("Cannot set name for thread [{}]: [{}] {}",
                      reinterpret_cast<const void*>(pthread_self()), rc,
                      strerror(rc));
    // Silently ignored.
  }
}

}  // namespace flare
