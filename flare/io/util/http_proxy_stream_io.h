#ifndef FLARE_IO_UTIL_HTTP_PROXY_STREAM_IO_H_
#define FLARE_IO_UTIL_HTTP_PROXY_STREAM_IO_H_

#include <memory>
#include <string>

#include "flare/io/util/stream_io.h"

namespace flare {

class HttpProxyStreamIo : public AbstractStreamIo {
 public:
  HttpProxyStreamIo(std::unique_ptr<AbstractStreamIo> base,
                    const std::string& addr);
  ~HttpProxyStreamIo();

  HandshakingStatus Handshake() override;

  ssize_t ReadV(const iovec* iov, int iovcnt) override;
  ssize_t WriteV(const iovec* iov, int iovcnt) override;

  int GetFd();

 private:
  HandshakingStatus DoHandshakeWrite();
  HandshakingStatus DoHandshakeRead();

  int written_ = 0;
  bool base_handshake_done_ = false;

  std::string read_;
  std::string handshake_message_;
  std::string addr_;
  std::unique_ptr<AbstractStreamIo> base_;
};

}  // namespace flare

#endif  // FLARE_IO_UTIL_HTTP_PROXY_STREAM_IO_H_
