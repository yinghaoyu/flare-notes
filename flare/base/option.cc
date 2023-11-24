#include "flare/base/option.h"

#include <utility>

#include "flare/base/option/option_service.h"

namespace flare {

namespace option {

void InitializeOptions() { option::OptionService::Instance()->ResolveAll(); }

void ShutdownOptions() { option::OptionService::Instance()->Shutdown(); }

void SynchronizeOptions() {
  option::OptionService::Instance()->UpdateOptions();
}

Json::Value DumpOptions() { return option::OptionService::Instance()->Dump(); }

}  // namespace option

}  // namespace flare
