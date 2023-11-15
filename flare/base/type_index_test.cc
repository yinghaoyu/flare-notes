
#include "flare/base/type_index.h"

#include <string>

#include "gtest/gtest.h"

namespace flare {

TEST(TypeIndex, Compare) {
  constexpr TypeIndex empty1, empty2;

  ASSERT_EQ(empty1, empty2);

  // Statically initializable.
  constexpr auto str_type = GetTypeIndex<std::string>();
  constexpr auto int_type = GetTypeIndex<int>();

  // `operator !=` is not implemented, we can't use `ASSERT_NE` here.
  ASSERT_FALSE(empty1 == str_type);
  ASSERT_FALSE(empty1 == int_type);
  ASSERT_FALSE(str_type == int_type);

  if (str_type < int_type) {
    ASSERT_FALSE(int_type < str_type);
  } else {
    ASSERT_FALSE(str_type < int_type);
  }
}

TEST(TypeIndex, TypeIndexOfRuntime) {
  constexpr auto str_type = GetTypeIndex<std::string>();
  ASSERT_EQ(std::type_index(typeid(std::string)),
            str_type.GetRuntimeTypeIndex());
}

}  // namespace flare
