#include "flare/base/internal/index_alloc.h"

#include "gtest/gtest.h"

namespace flare::internal {

struct Tag1;
struct Tag2;

TEST(IndexAlloc, All) {
  auto&& ia1 = IndexAlloc::For<Tag1>();
  auto&& ia2 = IndexAlloc::For<Tag2>();
  ASSERT_EQ(0, ia1->Next());
  ASSERT_EQ(1, ia1->Next());
  ASSERT_EQ(0, ia2->Next());
  ASSERT_EQ(2, ia1->Next());
  ia1->Free(1);
  ASSERT_EQ(1, ia2->Next());
  ASSERT_EQ(1, ia1->Next());
  ASSERT_EQ(2, ia2->Next());
}

}  // namespace flare::internal
