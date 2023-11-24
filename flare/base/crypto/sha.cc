#include "flare/base/crypto/sha.h"

#include "openssl/sha.h"

#include "flare/base/crypto/detail/openssl_impl.h"

namespace flare {

FLARE_DETAIL_CRYPTO_DEFINE_HASH_AND_HMAC_IMPL_FOR(Sha1, SHA1, SHA, SHA, sha1)
FLARE_DETAIL_CRYPTO_DEFINE_HASH_AND_HMAC_IMPL_FOR(Sha224, SHA224, SHA256,
                                                  SHA224, sha224)
FLARE_DETAIL_CRYPTO_DEFINE_HASH_AND_HMAC_IMPL_FOR(Sha256, SHA256, SHA256,
                                                  SHA256, sha256)
FLARE_DETAIL_CRYPTO_DEFINE_HASH_AND_HMAC_IMPL_FOR(Sha384, SHA384, SHA512,
                                                  SHA384, sha384)
FLARE_DETAIL_CRYPTO_DEFINE_HASH_AND_HMAC_IMPL_FOR(Sha512, SHA512, SHA512,
                                                  SHA512, sha512)

}  // namespace flare
