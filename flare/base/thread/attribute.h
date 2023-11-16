#ifndef FLARE_BASE_THREAD_ATTRIBUTE_H_
#define FLARE_BASE_THREAD_ATTRIBUTE_H_

#include <cstdint>
#include <string>
#include <thread>
#include <vector>

namespace flare {

// Some helper methods for manipulating threads.

// Set affinity of the calling thread.
//
// Returns error number, or 0 on success.
int TrySetCurrentThreadAffinity(const std::vector<int>& affinity);

// Set affinity of the calling thread.
//
// Abort on failure.
void SetCurrentThreadAffinity(const std::vector<int>& affinity);

// Get affinity of the calling thread.
std::vector<int> GetCurrentThreadAffinity();

// Set name of the calling thread.
//
// Error, if any, is ignored.
void SetCurrentThreadName(const std::string& name);

}  // namespace flare

#endif  // FLARE_BASE_THREAD_ATTRIBUTE_H_
