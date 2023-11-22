#ifndef FLARE_BASE_MONITORING_INIT_H_
#define FLARE_BASE_MONITORING_INIT_H_

#include <string>

#include "flare/base/function.h"

namespace flare::monitoring {

// Initialize monitoring system. This is called by `flare::Start()` (as the
// initialization cannot be done before finishing parsing GFlags) and may not be
// called by users.
void InitializeMonitoringSystem();

// Terminate monitoring system. Called by `flare::Start()`, you shouldn't call
// it manually.
void TerminateMonitoringSystem();

// Used by builtin monitoring utilities. This method registers a callback once
// monitoring systems are initialized. The callback is called with an empty
// string if the registered key is not enabled by user, or the remapped key if
// it's set.
//
// If the monitoring system has already been initialized by the time this method
// is called, `cb` is called immediately.
void RegisterBuiltinMonitoringKeyCallback(
    const std::string& key, Function<void(const std::string&)> cb);

}  // namespace flare::monitoring

#endif  // FLARE_BASE_MONITORING_INIT_H_
