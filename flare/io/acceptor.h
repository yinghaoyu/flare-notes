
#ifndef FLARE_IO_ACCEPTOR_H_
#define FLARE_IO_ACCEPTOR_H_

namespace flare {

// `Acceptor` listens for incoming connections.
class Acceptor {
 public:
  virtual ~Acceptor() = default;

  // Kill the acceptor and wait for its full stop.
  virtual void Stop() = 0;
  virtual void Join() = 0;
};

}  // namespace flare

#endif  // FLARE_IO_ACCEPTOR_H_
