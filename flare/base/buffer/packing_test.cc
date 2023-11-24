#include "flare/base/buffer/packing.h"

#include "gtest/gtest.h"

namespace flare {

TEST(Packing, Empty) {
  auto buffer = WriteKeyedNoncontiguousBuffers({});
  EXPECT_FALSE(buffer.Empty());
  auto parsed = TryParseKeyedNoncontiguousBuffers(buffer);
  ASSERT_TRUE(parsed);
  ASSERT_EQ(0, parsed->size());
}

TEST(Packing, KeyedBuffer) {
  auto buffer =
      WriteKeyedNoncontiguousBuffers({{"key1", CreateBufferSlow("value1")},
                                      {"key2", CreateBufferSlow("value2")}});
  EXPECT_FALSE(buffer.Empty());
  auto parsed = TryParseKeyedNoncontiguousBuffers(buffer);
  ASSERT_TRUE(parsed);
  ASSERT_EQ(2, parsed->size());
  EXPECT_EQ("key1", (*parsed)[0].first);
  EXPECT_EQ("value1", FlattenSlow((*parsed)[0].second));
  EXPECT_EQ("key2", (*parsed)[1].first);
  EXPECT_EQ("value2", FlattenSlow((*parsed)[1].second));
}

TEST(Packing, BufferArray) {
  auto buffer = WriteNoncontiguousBufferArray(
      {CreateBufferSlow("value1"), CreateBufferSlow("value2")});
  EXPECT_FALSE(buffer.Empty());
  auto parsed = TryParseNoncontiguousBufferArray(buffer);
  ASSERT_TRUE(parsed);
  ASSERT_EQ(2, parsed->size());
  EXPECT_EQ("value1", FlattenSlow((*parsed)[0]));
  EXPECT_EQ("value2", FlattenSlow((*parsed)[1]));
}

}  // namespace flare
