#include "flare/base/net/endpoint.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <utility>

#include "gtest/gtest.h"

#include "flare/base/string.h"

using namespace std::literals;

namespace flare {

TEST(EndpointBuilder, Retrieve) {
  EndpointRetriever er;
  auto ep2 = EndpointFromIpv4("192.0.2.1", 5678);
  memcpy(er.RetrieveAddr(), ep2.Get(), ep2.Length());
  *er.RetrieveLength() = ep2.Length();
  ASSERT_EQ("192.0.2.1:5678", er.Build().ToString());
}

TEST(Endpoint, ToString) {
  ASSERT_EQ("192.0.2.1:5678", EndpointFromIpv4("192.0.2.1", 5678).ToString());
}

TEST(Endpoint, ToString2) {
  Endpoint ep;
  auto ep2 = EndpointFromIpv4("192.0.2.1", 5678);
  ep = ep2;
  ASSERT_EQ("192.0.2.1:5678", ep.ToString());
}

TEST(Endpoint, ToString3) {
  ASSERT_EQ("192.0.2.1:5678",
            Format("{}", EndpointFromIpv4("192.0.2.1", 5678)));
}

TEST(Endpoint, ToString4) {
  auto ep = EndpointFromUnix("/tmp/test.sock");
  ASSERT_EQ("/tmp/test.sock", ep.ToString());

  auto ep2 = EndpointFromUnix("@/tmp/test2.sock");
  ASSERT_EQ("@/tmp/test2.sock", ep2.ToString());
}

TEST(Endpoint, MoveToEmpty) {
  Endpoint ep;
  auto ep2 = EndpointFromIpv4("192.0.2.1", 5678);
  ep = ep2;
  ASSERT_EQ("192.0.2.1:5678", ep.ToString());
}

TEST(Endpoint, MoveFromEmpty) {
  Endpoint ep;
  auto ep2 = EndpointFromIpv4("192.0.2.1", 5678);
  ep2 = std::move(ep);
  ASSERT_TRUE(ep2.Empty());
}

TEST(Endpoint, EndpointFromString) {
  auto ep = EndpointFromString("192.0.2.1:5678");
  ASSERT_EQ("192.0.2.1:5678", ep.ToString());

  ep = EndpointFromString("[2001:db8:8714:3a90::12]:1234");
  ASSERT_EQ("[2001:db8:8714:3a90::12]:1234", ep.ToString());
}

TEST(Endpoint, EndpointCompare) {
  auto ep1 = EndpointFromString("192.0.2.1:5678");
  auto ep2 = EndpointFromString("192.0.2.1:5678");
  auto ep3 = EndpointFromString("192.0.2.1:9999");
  ASSERT_EQ(ep1, ep2);
  ASSERT_FALSE(ep1 == ep3);
}

TEST(Endpoint, EndpointCopy) {
  auto ep1 = EndpointFromString("192.0.2.1:5678");
  auto ep2 = ep1;
  Endpoint ep3;

  ep3 = ep1;
  ASSERT_EQ(ep1, ep2);
  ASSERT_EQ(ep1, ep3);
  ASSERT_EQ(ep2, ep3);
}

TEST(Endpoint, TryParse) {
  auto ep = TryParse<Endpoint>("192.0.2.1:5678");
  ASSERT_TRUE(ep);
  ASSERT_EQ("192.0.2.1:5678", ep->ToString());

  ep = TryParse<Endpoint>("[2001:db8:8714:3a90::12]:1234");
  ASSERT_TRUE(ep);
  ASSERT_EQ("[2001:db8:8714:3a90::12]:1234", ep->ToString());
}

TEST(Endpoint, TryParse2) {
  auto ep = TryParse<Endpoint>("192.0.2.1:5678", from_ipv4);
  ASSERT_TRUE(ep);
  ASSERT_EQ("192.0.2.1:5678", ep->ToString());

  ep = TryParse<Endpoint>("[2001:db8:8714:3a90::12]:1234", from_ipv6);
  ASSERT_TRUE(ep);
  ASSERT_EQ("[2001:db8:8714:3a90::12]:1234", ep->ToString());
}

TEST(Endpoint, TryParse3) {
  auto ep = TryParse<Endpoint>("192.0.2.1:5678", from_ipv6);
  ASSERT_FALSE(ep);
  ep = TryParse<Endpoint>("[2001:db8:8714:3a90::12]:1234", from_ipv4);
  ASSERT_FALSE(ep);
}

TEST(Endpoint, GetIpPortV4) {
  auto ep = TryParse<Endpoint>("192.0.2.1:5678");
  ASSERT_TRUE(ep);
  ASSERT_EQ("192.0.2.1", EndpointGetIp(*ep));
  ASSERT_EQ(5678, EndpointGetPort(*ep));
}

TEST(Endpoint, GetIpPortV6) {
  auto ep = TryParse<Endpoint>("[2001:db8:8714:3a90::12]:1234");
  ASSERT_TRUE(ep);
  ASSERT_EQ("2001:db8:8714:3a90::12", EndpointGetIp(*ep));
  ASSERT_EQ(1234, EndpointGetPort(*ep));
}

TEST(Endpoint, GetUnixDomain) {
  auto ep = TryParse<Endpoint>("/tmp/test10086.sock", from_unix);
  ASSERT_TRUE(ep);
  ASSERT_EQ("/tmp/test10086.sock", ep->ToString());
}

TEST(Endpoint, ResolveDomainName) {
  auto eps = ResolveDomain("www.qq.com", 80);
  ASSERT_TRUE(eps);
  for (auto& ep : *eps) {
    std::cout << "Get IP from qq.com: " << ep.ToString() << std::endl;
    ASSERT_EQ(EndpointGetPort(ep), 80);
  }
  ASSERT_GT(eps->size(), 0);
}

TEST(Endpoint, GetInterfaceAddresses) {
  auto ifaddrs = GetInterfaceAddresses();
  for (auto&& e : ifaddrs) {
    std::cout << fmt::format("Get address: {}", e.ToString()) << std::endl;
  }
  ASSERT_GT(ifaddrs.size(), 0);  // At least 127.0.0.1 should be there.
}

TEST(Endpoint, IsPrivateIpv4Address) {
  EXPECT_FALSE(IsPrivateIpv4AddressRfc(
      EndpointFromIpv6("2001:db8:8714:3a90::12", 5678)));
  EXPECT_FALSE(IsPrivateIpv4AddressCorp(
      EndpointFromIpv6("2001:db8:8714:3a90::12", 5678)));

  EXPECT_FALSE(IsPrivateIpv4AddressRfc(EndpointFromIpv4("192.0.2.1", 5678)));
  EXPECT_FALSE(IsPrivateIpv4AddressCorp(EndpointFromIpv4("192.0.2.1", 5678)));

  EXPECT_TRUE(IsPrivateIpv4AddressRfc(EndpointFromIpv4("10.0.0.1", 5678)));
  EXPECT_TRUE(IsPrivateIpv4AddressCorp(EndpointFromIpv4("10.0.0.1", 5678)));

  EXPECT_FALSE(IsPrivateIpv4AddressRfc(EndpointFromIpv4("9.0.0.1", 5678)));
  EXPECT_TRUE(IsPrivateIpv4AddressCorp(EndpointFromIpv4("9.0.0.1", 5678)));
  EXPECT_FALSE(IsPrivateIpv4AddressRfc(EndpointFromIpv4("11.0.0.1", 5678)));
  EXPECT_TRUE(IsPrivateIpv4AddressCorp(EndpointFromIpv4("11.0.0.1", 5678)));
  EXPECT_FALSE(IsPrivateIpv4AddressRfc(EndpointFromIpv4("30.0.0.1", 5678)));
  EXPECT_TRUE(IsPrivateIpv4AddressCorp(EndpointFromIpv4("30.0.0.1", 5678)));
}

TEST(Endpoint, IsGuaIpv6Address) {
  EXPECT_FALSE(IsGuaIpv6Address(EndpointFromIpv4("192.0.2.1", 5678)));
  EXPECT_FALSE(IsGuaIpv6Address(EndpointFromIpv6("::", 5678)));
  EXPECT_TRUE(
      IsGuaIpv6Address(EndpointFromIpv6("2001:db8:8714:3a90::12", 5678)));
}

// TODO(luobogao): UT for AF_UNIX. AF_UNIX takes different code path than
// AF_INET(6), and should be tested in its own.

}  // namespace flare
