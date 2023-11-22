#ifndef FLARE_FIBER_ALTERNATIVES_H_
#define FLARE_FIBER_ALTERNATIVES_H_

#include <thread>

// This file provides you alternatives for accessing special variables safely
// (e.g., `errno`). By default it's unsafe to access some of them more than once
// if fiber rescheduling happens in between.

namespace flare::fiber {

// Fiber-safe alternative for reading `errno`.
//
// You don't need this method if no fiber-rescheduling happens in your method.
int GetLastError();

// Fiber-safe alternative for setting `errno`.
void SetLastError(int error);

// Reads current thread's ID.
std::thread::id GetCurrentThreadId();

}  // namespace flare::fiber

#endif  // FLARE_FIBER_ALTERNATIVES_H_
