#include "flare/io/util/socket.h"

#include <sys/types.h>
#include <unistd.h>

#include "gtest/gtest.h"

#include "flare/testing/endpoint.h"
#include "flare/testing/main.h"

using namespace std::literals;

namespace flare::io::util {

TEST(Socket, CreateListener) {
  auto addr = testing::PickAvailableEndpoint();
  auto fd1 = CreateListener(addr, 10);
  ASSERT_TRUE(fd1);

  if (getuid() != 0) {
    // Shouldn't success as non-root should not be able to listen on port number
    // less than 1024.
    auto addr2 = EndpointFromIpv4("127.0.0.1", 1);
    auto fd2 = CreateListener(addr2, 10);
    ASSERT_FALSE(fd2);
  }
}

}  // namespace flare::io::util

FLARE_TEST_MAIN
