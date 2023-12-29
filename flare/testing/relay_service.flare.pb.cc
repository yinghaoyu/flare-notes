#include "flare/testing/relay_service.flare.pb.h"

#include <mutex>

#include "flare/rpc/rpc_channel.h"
#include "flare/rpc/rpc_client_controller.h"
#include "flare/rpc/rpc_server_controller.h"

namespace flare::testing {

namespace {
namespace flare_rpc {

const ::google::protobuf::ServiceDescriptor*
  file_level_service_descriptors[1];
void InitServiceDescriptorsOnce() {
  static std::once_flag f;
  std::call_once(f, [] {
    auto file = ::google::protobuf::DescriptorPool::generated_pool()
        ->FindFileByName("flare/testing/relay_service.proto");
    for (int i = 0; i != file->service_count(); ++i) {
      file_level_service_descriptors[i] = file->service(i);
    }
  });
}

const ::google::protobuf::ServiceDescriptor*
GetServiceDescriptor(int index) {
  InitServiceDescriptorsOnce();
  return file_level_service_descriptors[index];
}

}  // namespace flare_rpc
}  // namespace

const ::google::protobuf::ServiceDescriptor*
SyncRelayService::GetDescriptor() {
  return flare_rpc::GetServiceDescriptor(0);
}

void SyncRelayService::CallMethod(
    const ::google::protobuf::MethodDescriptor* method,
    ::google::protobuf::RpcController* controller,
    const ::google::protobuf::Message* request,
    ::google::protobuf::Message* response,
    ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(),
                   flare_rpc::GetServiceDescriptor(0));
  auto ctlr = ::flare::down_cast<flare::RpcServerController>(
      controller);
  switch (method->index()) {
    case 0: {
      Relay(
          *::google::protobuf::down_cast<const ::flare::testing::RelayRequest*>(
              request),
          ::google::protobuf::down_cast<::flare::testing::RelayResponse*>(response),
          ctlr);
      done->Run();
      break;
    }
  default:
    GOOGLE_LOG(FATAL) <<
        "Bad method index; this should never happen.";
  }
}

const ::google::protobuf::Message& SyncRelayService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(),
                   flare_rpc::GetServiceDescriptor(0));
  switch (method->index()) {
    case 0:
      return ::flare::testing::RelayRequest::default_instance();
  default:
    GOOGLE_LOG(FATAL) <<
        "Bad method index; this should never happen.";
    return *::google::protobuf::MessageFactory::generated_factory()
        ->GetPrototype(method->input_type());
  }
}

const ::google::protobuf::Message& SyncRelayService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(),
                   flare_rpc::GetServiceDescriptor(0));
  switch (method->index()) {
    case 0:
      return ::flare::testing::RelayResponse::default_instance();
  default:
    GOOGLE_LOG(FATAL) <<
        "Bad method index; this should never happen.";
    return *::google::protobuf::MessageFactory::generated_factory()
        ->GetPrototype(method->output_type());
  }
}

void SyncRelayService::Relay(
    const ::flare::testing::RelayRequest& request,
    ::flare::testing::RelayResponse* response,
    ::flare::RpcServerController* controller) {
  controller->SetFailed(
    ::flare::rpc::STATUS_FAILED,
    "Method Relay() not implemented.");
}

RelayService_SyncStub::RelayService_SyncStub(const std::string& uri) {
  channel_ = std::make_unique<flare::RpcChannel>(uri);
}
::flare::Expected<::flare::testing::RelayResponse, ::flare::Status>
RelayService_SyncStub::Relay(
    const ::flare::testing::RelayRequest& request,
    ::flare::RpcClientController* ctlr) {
  ::flare::testing::RelayResponse rc;
  channel_->CallMethod(
      flare_rpc::GetServiceDescriptor(0)->method(0),
      ctlr, &request, &rc, nullptr);
  if (!ctlr->Failed()) {
    return rc;
  }
  return flare::Status(ctlr->ErrorCode(), ctlr->ErrorText());
}

RelayService_AsyncStub::RelayService_AsyncStub(const std::string& uri) {
  channel_ = std::make_unique<flare::RpcChannel>(uri);
}
::flare::Future<
    ::flare::Expected<::flare::testing::RelayResponse, ::flare::Status>>
RelayService_AsyncStub::Relay(
    const ::flare::testing::RelayRequest& request,
    ::flare::RpcClientController* ctlr) {
  ::flare::Promise<::flare::Expected<::flare::testing::RelayResponse,
                   ::flare::Status>> p;
  auto rf = p.GetFuture();
  auto rc = std::make_unique<::flare::testing::RelayResponse>();
  auto rcp = rc.get();
  auto cb = [rc = std::move(rc),
             p = std::move(p), ctlr] () mutable {
    if (ctlr->Failed()) {
      p.SetValue(::flare::Status(
          ctlr->ErrorCode(), ctlr->ErrorText()));
    } else {
      p.SetValue(std::move(*rc));
    }
  };
  channel_->CallMethod(
      flare_rpc::GetServiceDescriptor(0)->method(0),
      ctlr, &request, rcp, flare::NewCallback(std::move(cb)));
  return rf;
}


}


