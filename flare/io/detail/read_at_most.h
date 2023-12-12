#ifndef FLARE_IO_DETAIL_READ_AT_MOST_H_
#define FLARE_IO_DETAIL_READ_AT_MOST_H_

#include "flare/base/buffer.h"
#include "flare/io/util/stream_io.h"

namespace flare::io::detail {

enum class ReadStatus {
  // All bytes are read, the socket is left in `EAGAIN` state.
  Drained,

  // `max_bytes` are read.
  MaxBytesRead,

  // All (remaining) bytes are read, the socket is being closed by the remote
  // side.
  PeerClosing,

  // You're out of luck.
  Error
};

// Reads at most `max_bytes` into `to`.
//
// This method is more performant than issuing a call to `io->Read` for each
// buffer block.
//
// Returns whatever returned by `io->Read`.
ReadStatus ReadAtMost(std::size_t max_bytes, AbstractStreamIo* io,
                      NoncontiguousBuffer* to, std::size_t* bytes_read);

}  // namespace flare::io::detail

#endif  // FLARE_IO_DETAIL_READ_AT_MOST_H_
