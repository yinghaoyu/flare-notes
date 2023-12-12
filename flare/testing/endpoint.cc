#include "flare/testing/endpoint.h"

#include "flare/base/handle.h"
#include "flare/base/net/endpoint.h"
#include "flare/base/random.h"

namespace flare::testing {

namespace detail {

bool IsPortAvaliable(uint16_t port, int type) {
  Handle sock{socket(PF_INET, type, 0)};
  if (sock.Get() < 0) {
    return false;
  }
  int reuse_flag = 1;
  FLARE_PCHECK(setsockopt(sock.Get(), SOL_SOCKET, SO_REUSEADDR, &reuse_flag,
                          sizeof(reuse_flag)) == 0);
  auto ep = EndpointFromIpv4("0.0.0.0", port);
  return bind(sock.Get(), ep.Get(), ep.Length()) == 0;
}

uint16_t PickAvailablePort(int type) {
  while (true) {
    auto port = Random(1024, 65535);
    if (IsPortAvaliable(port, type)) {
      return port;
    }
  }
}

}  // namespace detail

std::uint16_t PickAvailablePort(int type) {
  return detail::PickAvailablePort(type);
}

Endpoint PickAvailableEndpoint(int type) {
  return EndpointFromIpv4("127.0.0.1", PickAvailablePort(type));
}

}  // namespace flare::testing
