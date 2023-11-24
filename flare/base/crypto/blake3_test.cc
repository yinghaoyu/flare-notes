#include "flare/base/crypto/blake3.h"

#include "gtest/gtest.h"

#include "flare/base/buffer.h"
#include "flare/base/encoding.h"

using namespace std::literals;

namespace flare {

TEST(Blake3, All) {
  EXPECT_EQ("a6f2f4910b1c9d582d32cdc76a0fe844d9d98082099d13b65f69b20d66fd517b",
            EncodeHex(Blake3(CreateBufferSlow("hello."))));
  EXPECT_EQ("a6f2f4910b1c9d582d32cdc76a0fe844d9d98082099d13b65f69b20d66fd517b",
            EncodeHex(Blake3("hello.")));
  EXPECT_EQ("a6f2f4910b1c9d582d32cdc76a0fe844d9d98082099d13b65f69b20d66fd517b",
            EncodeHex(Blake3({"hel", "lo."})));
}

TEST(Blake3Digest, All) {
  Blake3Digest digest;
  digest.Append("h", 1);
  digest.Append("e");
  digest.Append({"ll", "o", "."});
  EXPECT_EQ("a6f2f4910b1c9d582d32cdc76a0fe844d9d98082099d13b65f69b20d66fd517b",
            EncodeHex(digest.DestructiveGet()));
}

}  // namespace flare
