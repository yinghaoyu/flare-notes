#include <sys/resource.h>
#include <sys/time.h>

#include "gflags/gflags.h"

#include "flare/base/logging.h"
#include "flare/base/string.h"
#include "flare/init/on_init.h"

namespace flare {

namespace {

void OverrideResourceLimit(const std::string& name, int resource, rlim_t to,
                           bool must_succeed, bool only_if_less) {
  rlimit current;
  FLARE_PCHECK(getrlimit(resource, &current) == 0,
               "Failed to get current limit of [{}].", name);
  if (only_if_less && current.rlim_cur >= to) {
    FLARE_VLOG(1,
               "Current limit of [{}] is greater than the desired one ({} vs "
               "{}), not resetting it.",
               name, current.rlim_cur, to);
    return;
  }
  current.rlim_cur = to;
  if (setrlimit(resource, &current) != 0) {
    if (must_succeed) {
      FLARE_PCHECK(0, "Failed to reset [{}] to [{}].", name, to);
    } else {
      FLARE_LOG_WARNING("Failed to reset [{}] to [{}].", name, to);
    }
  } else {
    FLARE_LOG_INFO("Reset [{}] to [{}].", name, to);
  }
}

rlim_t ParseLimitString(const std::string& name, const std::string& str) {
  FLARE_CHECK(!str.empty());
  if (IEquals(str, "infinity")) {
    return RLIM_INFINITY;
  }
  auto parsed = TryParse<rlim_t>(str);
  FLARE_CHECK(parsed, "Invalid value [{}] specified to rlimit [{}].", str,
              name);
  return *parsed;
}

}  // namespace

}  // namespace flare

#define FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(FlagName, ResourceConstant)         \
  DEFINE_string(flare_override_rlimit_##FlagName, "",                         \
                "If non-empty, Flare reset " #ResourceConstant                \
                " to the given value on start. To set it to infinity, "       \
                "specify `infinity`.");                                       \
  DEFINE_bool(flare_override_rlimit_##FlagName##_must_succeed, true,          \
              "If set, failure in overriding default limit leads to crash. "  \
              "Otherwise on failure only a warning is printed to log file."); \
  DEFINE_bool(flare_override_rlimit_##FlagName##_only_if_less, true,          \
              "If set, only when the default limit of " #ResourceConstant     \
              " is less than the desired limit will Flare reset the current " \
              "one. Otherwise no action is taken.");                          \
                                                                              \
  FLARE_ON_INIT([] {                                                          \
    auto&& flag = FLAGS_flare_override_rlimit_##FlagName;                     \
    if (!flag.empty()) {                                                      \
      flare::OverrideResourceLimit(                                           \
          #ResourceConstant, ResourceConstant,                                \
          flare::ParseLimitString(#ResourceConstant, flag),                   \
          FLAGS_flare_override_rlimit_##FlagName##_must_succeed,              \
          FLAGS_flare_override_rlimit_##FlagName##_only_if_less);             \
    }                                                                         \
  })

FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(as, RLIMIT_AS);
FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(core, RLIMIT_CORE);
FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(cpu, RLIMIT_CPU);
FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(data, RLIMIT_DATA);
FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(fsize, RLIMIT_FSIZE);
FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(locks, RLIMIT_LOCKS);
FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(memlock, RLIMIT_MEMLOCK);
FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(msgqueue, RLIMIT_MSGQUEUE);
FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(nice, RLIMIT_NICE);
FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(nofile, RLIMIT_NOFILE);
FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(nproc, RLIMIT_NPROC);
FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(rss, RLIMIT_RSS);
FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(rtprio, RLIMIT_RTPRIO);
FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(rttime, RLIMIT_RTTIME);
FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(sigpending, RLIMIT_SIGPENDING);
FLARE_OVERRIDE_RLIMIT_DEFINE_FLAG(stack, RLIMIT_STACK);
