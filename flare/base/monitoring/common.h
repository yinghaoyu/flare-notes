#ifndef FLARE_BASE_MONITORING_COMMON_H_
#define FLARE_BASE_MONITORING_COMMON_H_

#include <string>

#include "json/json.h"

namespace flare::monitoring {

std::string GetNow();

std::string ToString(const Json::Value& jsv);

std::string GetIntranetIp();

}  // namespace flare::monitoring

#endif  // FLARE_BASE_MONITORING_COMMON_H_
