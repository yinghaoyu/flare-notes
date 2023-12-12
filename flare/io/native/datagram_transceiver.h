#ifndef FLARE_IO_NATIVE_DATAGRAM_TRANSCEIVER_H_
#define FLARE_IO_NATIVE_DATAGRAM_TRANSCEIVER_H_

#include "flare/base/buffer.h"
#include "flare/base/maybe_owning.h"
#include "flare/base/net/endpoint.h"
#include "flare/io/datagram_transceiver.h"
#include "flare/io/descriptor.h"
#include "flare/io/detail/writing_datagram_list.h"

namespace flare {

// This class represents a UDP transceiver.
class NativeDatagramTransceiver final : public Descriptor,
                                        public DatagramTransceiver {
 public:
  struct Options {
    MaybeOwning<DatagramTransceiverHandler> handler;

    // Data needed for handing DTLS connections. (I don't think we're gonna
    // support this in near future.)
    // DtlsContext dtls_context.

    std::size_t maximum_packet_size = 65536;

    // There's no `write_buffer_size`. So long as we're not allowed to block,
    // there's nothing we can do about too many pending writes.

    // TODO(luobogao): Rate limitation.
  };

  explicit NativeDatagramTransceiver(Handle fd, Options options);
  ~NativeDatagramTransceiver();

  // Each `buffer` is sent as a whole datagram.
  bool Write(Endpoint to, NoncontiguousBuffer buffer,
             std::uintptr_t ctx) override;

  // Restart reading data.
  void RestartRead() override;

  // Detach the transceiver from the event loop.
  void Stop() override;
  void Join() override;

 private:
  // Note: We only read *one* datagram on each call, and return `true` if
  // there's more to read.
  EventAction OnReadable() override;

  // We only write a single datagram on each call, and return `true` unless
  // there's nothing to write.
  EventAction OnWritable() override;

  // An error occurred.
  void OnError(int err) override;

  void OnCleanup(CleanupReason reason) override;

  enum class FlushStatus {
    QuotaExceeded,
    Flushed,
    SystemBufferSaturated,
    PartialWrite,
    NothingWritten,
    Error
  };

  FlushStatus FlushWritingBuffer(std::size_t max_writes);

 private:
  Options options_;
  io::detail::WritingDatagramList write_buffer_;
};

}  // namespace flare

#endif  // FLARE_IO_NATIVE_DATAGRAM_TRANSCEIVER_H_
