#include "flare/base/internal/logging.h"

#include <string>
#include <vector>

namespace flare::internal::logging {

namespace {

std::vector<PrefixAppender*>* GetProviders() {
  // Not using `NeverDestroyed` as we're "low-level" utility and therefore
  // should not bring in too many dependencies..
  static std::vector<PrefixAppender*> providers;
  return &providers;
}

}  // namespace

namespace details {

std::string DescribeFormatArguments(const std::vector<std::string>& args) {
  // We cannot use `Join` in `base/string.h` as doing so can easily leads to
  // circular dependency.
  return fmt::format("{}", fmt::join(args.begin(), args.end(), ", "));
}

}  // namespace details

void InstallPrefixProvider(PrefixAppender* cb) {
  GetProviders()->push_back(cb);
}

void WritePrefixTo(std::string* to) {
  for (auto&& e : *GetProviders()) {
    auto was = to->size();
    e(to);
    if (to->size() != was) {
      to->push_back(' ');
    }
  }
}

}  // namespace flare::internal::logging
