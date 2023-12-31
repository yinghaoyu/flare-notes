#include "flare/base/monitoring/common.h"

#include "flare/base/net/endpoint.h"
#include "flare/base/string.h"

namespace flare::monitoring {

// Shamelessly copied from https://stackoverflow.com/a/10467633
std::string GetNow() {
  time_t now = time(nullptr);
  struct tm tms;
  char buf[80] = {};
  auto tm = *localtime_r(&now, &tms);
  strftime(buf, sizeof(buf), "%Y%m%d%H%M%S", &tm);
  return buf;
}

std::string ToString(const Json::Value& jsv) {
  Json::FastWriter writer;
  std::string str = writer.write(jsv);
  if (EndsWith(str, "\n")) {
    return str.substr(0, str.size() - 1);
  }
  return str;
}

std::string GetIntranetIp() {
  // FIXME: We've done the same in `rpc/tracing/tjb_tracing_ops_provider.cc`.
  static std::string result = []() -> std::string {
    auto endpoints = GetInterfaceAddresses();
    for (auto&& e : endpoints) {
      // TODO(luobogao): Prefer IPv6 if GUA / ULA is present.
      if (IsPrivateIpv4AddressCorp(e)) {
        auto str = e.ToString();
        str.erase(str.end() - 2, str.end());  // Remove suffix ":0"
        return str;
      }
    }
    FLARE_LOG_ERROR_ONCE(
        "Cannot get intranet IP, [0.0.0.0] will be reported as local IP "
        "instead.");
    return "0.0.0.0";  // Unknown.
  }();
  return result;
}

}  // namespace flare::monitoring
