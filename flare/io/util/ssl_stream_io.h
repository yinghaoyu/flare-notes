#ifndef FLARE_IO_UTIL_SSL_STREAM_IO_H_
#define FLARE_IO_UTIL_SSL_STREAM_IO_H_

#include <memory>

#include "openssl/ssl.h"

#include "flare/io/util/stream_io.h"

namespace flare {

class SslStreamIo : public AbstractStreamIo {
 public:
  SslStreamIo(std::unique_ptr<AbstractStreamIo> io,
              std::unique_ptr<SSL, decltype(&SSL_free)> ssl);
  ~SslStreamIo();

  HandshakingStatus Handshake() override;

  // Renegotiation is not supported. If the security protocol asked this, the
  // implementation generates an error.
  ssize_t ReadV(const iovec* iov, int iovcnt) override;

  ssize_t WriteV(const iovec* iov, int iovcnt) override;

 private:
  ssize_t DoReadV(const iovec* iov, int iovcnt);
  ssize_t DoWriteV(const iovec* iov, int iovcnt);

  int HandleSslError(const char* operation, int ret);

 private:
  std::unique_ptr<SSL, decltype(&SSL_free)> ssl_;
  std::unique_ptr<AbstractStreamIo> base_;
  bool base_handshake_done_{false};
};

}  // namespace flare

#endif  // FLARE_IO_UTIL_SSL_STREAM_IO_H_
