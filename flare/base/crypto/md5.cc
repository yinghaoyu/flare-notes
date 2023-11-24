#include "flare/base/crypto/md5.h"

#include "openssl/md5.h"

#include "flare/base/crypto/detail/openssl_impl.h"

namespace flare {

FLARE_DETAIL_CRYPTO_DEFINE_HASH_AND_HMAC_IMPL_FOR(Md5, MD5, MD5, MD5, md5)

}  // namespace flare
