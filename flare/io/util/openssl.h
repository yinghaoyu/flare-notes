#ifndef FLARE_IO_UTIL_OPENSSL_H_
#define FLARE_IO_UTIL_OPENSSL_H_

namespace flare::io::util {

// Global initialization openssl and cleanup.
void InitializeOpenSSL();
void DestroyOpenSSL();

}  // namespace flare::io::util

#endif  // FLARE_IO_UTIL_OPENSSL_H_
