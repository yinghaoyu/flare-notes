#include "flare/base/status.h"

#include "flare/base/internal/early_init.h"
#include "flare/base/internal/logging.h"

namespace flare {

Status::Status(int status, const std::string& desc) {
  if (status == 0) {
    FLARE_LOG_ERROR_IF_ONCE(
        !desc.empty(),
        "Status `SUCCESS` may not carry description, but [{}] is given.", desc);
    // NOTHING else.
  } else {
    state_ = MakeRefCounted<State>();
    state_->status = status;
    state_->desc = desc;
  }
}

const std::string& Status::message() const noexcept {
  return !state_ ? internal::EarlyInitConstant<std::string>() : state_->desc;
}

std::string Status::ToString() const {
  return fmt::format(
      "[{}] {}", code(),
      !ok() ? message() : "The operation completed successfully.");
}

}  // namespace flare
