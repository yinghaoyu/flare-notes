#include "flare/base/internal/case_insensitive_hash_map.h"

#include <string>

#include "gtest/gtest.h"

namespace flare::internal {

TEST(CaseInsensitiveHashMap, Easy) {
  CaseInsensitiveHashMap<std::string, std::string> m;

  m["a"] = "1";
  m["b"] = "10";
  m["C"] = "-5";
  m["c"] = "3";  // Overwrites "C"

  ASSERT_EQ("1", *m.TryGet("a"));
  ASSERT_EQ("1", *m.TryGet("A"));
  ASSERT_EQ("3", m["C"]);
  ASSERT_FALSE(m.TryGet("d"));
  ASSERT_EQ(3, m.size());
}

}  // namespace flare::internal
