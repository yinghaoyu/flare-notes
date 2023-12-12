#ifndef FLARE_IO_UTIL_STREAM_IO_H_
#define FLARE_IO_UTIL_STREAM_IO_H_

#include <sys/uio.h>

#include <cstddef>

#include "flare/io/detail/eintr_safe.h"

namespace flare {

// An abstraction for Stream IO ...
class AbstractStreamIo {
 public:
  virtual ~AbstractStreamIo() = default;

  enum class HandshakingStatus { Success, WannaRead, WannaWrite, Error };

  // This method is called once the connection has been established. Once it
  // returns `kSuccess,` it won't be called again in this object's lifetime.
  // The implementation should be thread-safe.
  virtual HandshakingStatus Handshake() = 0;

  // Returns number of bytes read, -1 on error. `errno` (`EAGAIN`, for example)
  // should be kept / synthesized by the implementation if an error occurred.
  //
  // If `EAGAIN` is returned (via `errno`), the caller guarantees the next call
  // will be made with exactly the same arguments.
  //
  // The implementation is responsible for handling `EINTR`.
  virtual ssize_t ReadV(const iovec* iov, int iovcnt) = 0;

  // Returns number of bytes written, -1 on error. `errno` should be kept /
  // synthesized by the implementation.
  //
  // The caller guarantees that the same arguments will be used in next call if
  // `EAGAIN` is returned.
  //
  // The implementation is responsible for handling `EINTR`.
  //
  // Renegotiation is not supported.
  virtual ssize_t WriteV(const iovec* iov, int iovcnt) = 0;
};

class SystemStreamIo : public AbstractStreamIo {
 public:
  explicit SystemStreamIo(int fd) : fd_(fd) {}

  HandshakingStatus Handshake() override { return HandshakingStatus::Success; }

  ssize_t ReadV(const iovec* iov, int iovcnt) override {
    return io::detail::EIntrSafeReadV(fd_, iov, iovcnt);
  }

  ssize_t WriteV(const iovec* iov, int iovcnt) override {
    return io::detail::EIntrSafeWriteV(fd_, iov, iovcnt);
  }

  int GetFd() const noexcept { return fd_; }

 private:
  int fd_;
};

}  // namespace flare

#endif  // FLARE_IO_UTIL_STREAM_IO_H_
