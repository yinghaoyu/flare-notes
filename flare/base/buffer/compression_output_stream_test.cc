#include "flare/base/buffer/compression_output_stream.h"

#include <string>

#include "gtest/gtest.h"

namespace flare {

TEST(NoncontiguousBufferCompressionOutputStream, All) {
  NoncontiguousBufferBuilder nbb;
  NoncontiguousBufferCompressionOutputStream nbcos(&nbb);
  std::string src = "short str";
  void* data;
  std::size_t size;
  nbcos.Next(&data, &size);
  memcpy(data, src.data(), src.size());
  nbcos.BackUp(size - src.size());
  nbcos.Flush();
  EXPECT_EQ(src, FlattenSlow(nbb.DestructiveGet()));
}

}  // namespace flare
