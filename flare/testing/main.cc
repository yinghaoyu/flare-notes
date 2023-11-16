#include "flare/testing/main.h"

#include "gflags/gflags.h"
#include "glog/logging.h"
#include "gtest/gtest.h"

#include "flare/init.h"

DECLARE_int32(flare_concurrency_hint);

namespace flare::testing {

int InitAndRunAllTests(int* argc, char** argv) {
  ::testing::InitGoogleTest(argc, argv);

  // I wasted a whole day in debugging a "bug" (it was not a bug actually),
  // just to realize that what was happening was stated clearly in the log.
  //
  // So I enable `logtostderr` by default for UTs.
  if (google::GetCommandLineFlagInfoOrDie("logtostderr").is_default) {
    FLAGS_logtostderr = true;
  }

  // Well we don't want too many threads in UT.
  if (google::GetCommandLineFlagInfoOrDie("flare_concurrency_hint")
          .is_default) {
    FLAGS_flare_concurrency_hint = 8;
  }

  // We don't want Flare to warn about using ephemeral port for serving RPCs in
  // UTs.
  google::CommandLineFlagInfo flag_info;
  if (google::GetCommandLineFlagInfo(
          "flare_rpc_server_suppress_ephemeral_port_warning", &flag_info) &&
      flag_info.is_default) {
    google::SetCommandLineOption(
        "flare_rpc_server_suppress_ephemeral_port_warning", "true");
  }
  return Start(*argc, argv, [](auto, auto) { return ::RUN_ALL_TESTS(); });
}

}  // namespace flare::testing
