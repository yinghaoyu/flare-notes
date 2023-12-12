#include "flare/io/util/openssl.h"

#include <pthread.h>
#include <stdint.h>

#include "openssl/crypto.h"
#include "openssl/engine.h"
#include "openssl/err.h"
#include "openssl/ssl.h"

namespace flare::io::util {

pthread_mutex_t* ssl_lock = nullptr;

void CallbackLockFunction(int32_t mode, int32_t type, const char* file,
                          int32_t line) {
  if (mode & CRYPTO_LOCK) {
    pthread_mutex_lock(&(ssl_lock[type]));
  } else {
    pthread_mutex_unlock(&(ssl_lock[type]));
  }
}

unsigned long CallbackIdFunction() {
  return static_cast<unsigned long>(pthread_self());
}

void InitializeOpenSSL() {
  ERR_load_ERR_strings();
  ERR_load_crypto_strings();
  SSL_load_error_strings();
  SSL_library_init();
  OpenSSL_add_all_algorithms();
  ENGINE_load_builtin_engines();

  // when openssl is used in multi-thread environment.
  ssl_lock = reinterpret_cast<pthread_mutex_t*>(
      OPENSSL_malloc(CRYPTO_num_locks() * sizeof(pthread_mutex_t)));

  uint32_t ssl_lock_num = CRYPTO_num_locks();
  for (int i = 0; i < ssl_lock_num; ++i) {
    pthread_mutex_init(&(ssl_lock[i]), nullptr);
  }

  CRYPTO_set_id_callback(CallbackIdFunction);
  CRYPTO_set_locking_callback(CallbackLockFunction);
}

void DestroyOpenSSL() {
  if (!ssl_lock) return;

#ifndef FLARE_WITH_BORINGSSL
  ENGINE_cleanup();
#endif
  CRYPTO_set_locking_callback(nullptr);
  uint32_t ssl_lock_num = CRYPTO_num_locks();
  for (int i = 0; i < ssl_lock_num; ++i) {
    pthread_mutex_destroy(&(ssl_lock[i]));
  }
  OPENSSL_free(ssl_lock);
  ssl_lock = nullptr;
}

}  // namespace flare::io::util
