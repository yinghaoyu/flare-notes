#include "flare/base/overloaded.h"

#include <string>
#include <variant>

#include "gtest/gtest.h"

using namespace std::literals;

namespace flare {

TEST(Overloaded, All) {
  std::variant<int, double, bool, std::string> v;
  int x = 0;
  double y = 0;
  bool z = false;
  std::string a;

  auto visitor =
      Overloaded{[&](int v) { x = v; }, [&](double v) { y = v; },
                 [&](bool v) { z = v; }, [&](const std::string& v) { a = v; }};

  v = "asdf"s;
  std::visit(visitor, v);
  ASSERT_EQ("asdf", a);

  v = 1;
  std::visit(visitor, v);
  ASSERT_EQ(1, x);

  v = 1.0;
  std::visit(visitor, v);
  ASSERT_EQ(1.0, y);

  v = true;
  std::visit(visitor, v);
  ASSERT_EQ(true, z);
}

}  // namespace flare
