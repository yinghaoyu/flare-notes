#include "flare/testing/echo_service.flare.pb.h"

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
        ->FindFileByName("flare/testing/echo_service.proto");
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
SyncEchoService::GetDescriptor() {
  return flare_rpc::GetServiceDescriptor(0);
}

void SyncEchoService::CallMethod(
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
      Echo(
          *::google::protobuf::down_cast<const ::flare::testing::EchoRequest*>(
              request),
          ::google::protobuf::down_cast<::flare::testing::EchoResponse*>(response),
          ctlr);
      done->Run();
      break;
    }
    case 1: {
      EchoWithMaxQueueingDelay(
          *::google::protobuf::down_cast<const ::flare::testing::EchoRequest*>(
              request),
          ::google::protobuf::down_cast<::flare::testing::EchoResponse*>(response),
          ctlr);
      done->Run();
      break;
    }
    case 2: {
      EchoWithMaxOngoingRequests(
          *::google::protobuf::down_cast<const ::flare::testing::EchoRequest*>(
              request),
          ::google::protobuf::down_cast<::flare::testing::EchoResponse*>(response),
          ctlr);
      done->Run();
      break;
    }
    case 3: {
      EchoStreamRequest(
          ctlr->GetStreamReader<::flare::testing::EchoRequest>(),
          ::google::protobuf::down_cast<::flare::testing::EchoResponse*>(response),
          ctlr);
      done->Run();
      break;
    }
    case 4: {
      EchoStreamResponse(
          *::google::protobuf::down_cast<const ::flare::testing::EchoRequest*>(
              request),
          ctlr->GetStreamWriter<::flare::testing::EchoResponse>(),
          ctlr);
      done->Run();
      break;
    }
    case 5: {
      EchoStreamBoth(
          ctlr->GetStreamReader<::flare::testing::EchoRequest>(),
          ctlr->GetStreamWriter<::flare::testing::EchoResponse>(),
          ctlr);
      done->Run();
      break;
    }
  default:
    GOOGLE_LOG(FATAL) <<
        "Bad method index; this should never happen.";
  }
}

const ::google::protobuf::Message& SyncEchoService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(),
                   flare_rpc::GetServiceDescriptor(0));
  switch (method->index()) {
    case 0:
      return ::flare::testing::EchoRequest::default_instance();
    case 1:
      return ::flare::testing::EchoRequest::default_instance();
    case 2:
      return ::flare::testing::EchoRequest::default_instance();
    case 3:
      return ::flare::testing::EchoRequest::default_instance();
    case 4:
      return ::flare::testing::EchoRequest::default_instance();
    case 5:
      return ::flare::testing::EchoRequest::default_instance();
  default:
    GOOGLE_LOG(FATAL) <<
        "Bad method index; this should never happen.";
    return *::google::protobuf::MessageFactory::generated_factory()
        ->GetPrototype(method->input_type());
  }
}

const ::google::protobuf::Message& SyncEchoService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(),
                   flare_rpc::GetServiceDescriptor(0));
  switch (method->index()) {
    case 0:
      return ::flare::testing::EchoResponse::default_instance();
    case 1:
      return ::flare::testing::EchoResponse::default_instance();
    case 2:
      return ::flare::testing::EchoResponse::default_instance();
    case 3:
      return ::flare::testing::EchoResponse::default_instance();
    case 4:
      return ::flare::testing::EchoResponse::default_instance();
    case 5:
      return ::flare::testing::EchoResponse::default_instance();
  default:
    GOOGLE_LOG(FATAL) <<
        "Bad method index; this should never happen.";
    return *::google::protobuf::MessageFactory::generated_factory()
        ->GetPrototype(method->output_type());
  }
}

void SyncEchoService::Echo(
    const ::flare::testing::EchoRequest& request,
    ::flare::testing::EchoResponse* response,
    ::flare::RpcServerController* controller) {
  controller->SetFailed(
    ::flare::rpc::STATUS_FAILED,
    "Method Echo() not implemented.");
}

void SyncEchoService::EchoWithMaxQueueingDelay(
    const ::flare::testing::EchoRequest& request,
    ::flare::testing::EchoResponse* response,
    ::flare::RpcServerController* controller) {
  controller->SetFailed(
    ::flare::rpc::STATUS_FAILED,
    "Method EchoWithMaxQueueingDelay() not implemented.");
}

void SyncEchoService::EchoWithMaxOngoingRequests(
    const ::flare::testing::EchoRequest& request,
    ::flare::testing::EchoResponse* response,
    ::flare::RpcServerController* controller) {
  controller->SetFailed(
    ::flare::rpc::STATUS_FAILED,
    "Method EchoWithMaxOngoingRequests() not implemented.");
}

void SyncEchoService::EchoStreamRequest(
    ::flare::StreamReader<::flare::testing::EchoRequest> reader,
    ::flare::testing::EchoResponse* response,
    ::flare::RpcServerController* controller) {
  controller->SetFailed(
    ::flare::rpc::STATUS_FAILED,
    "Method EchoStreamRequest() not implemented.");
  reader.Close();
}

void SyncEchoService::EchoStreamResponse(
    const ::flare::testing::EchoRequest& request,
    ::flare::StreamWriter<::flare::testing::EchoResponse> writer,
    ::flare::RpcServerController* controller) {
  controller->SetFailed(
    ::flare::rpc::STATUS_FAILED,
    "Method EchoStreamResponse() not implemented.");
  writer.Close();
}

void SyncEchoService::EchoStreamBoth(
    ::flare::StreamReader<::flare::testing::EchoRequest> reader,
    ::flare::StreamWriter<::flare::testing::EchoResponse> writer,
    ::flare::RpcServerController* controller) {
  controller->SetFailed(
    ::flare::rpc::STATUS_FAILED,
    "Method EchoStreamBoth() not implemented.");
  reader.Close();
  writer.Close();
}

EchoService_SyncStub::EchoService_SyncStub(const std::string& uri) {
  channel_ = std::make_unique<flare::RpcChannel>(uri);
}
::flare::Expected<::flare::testing::EchoResponse, ::flare::Status>
EchoService_SyncStub::Echo(
    const ::flare::testing::EchoRequest& request,
    ::flare::RpcClientController* ctlr) {
  ::flare::testing::EchoResponse rc;
  channel_->CallMethod(
      flare_rpc::GetServiceDescriptor(0)->method(0),
      ctlr, &request, &rc, nullptr);
  if (!ctlr->Failed()) {
    return rc;
  }
  return flare::Status(ctlr->ErrorCode(), ctlr->ErrorText());
}

::flare::Expected<::flare::testing::EchoResponse, ::flare::Status>
EchoService_SyncStub::EchoWithMaxQueueingDelay(
    const ::flare::testing::EchoRequest& request,
    ::flare::RpcClientController* ctlr) {
  ::flare::testing::EchoResponse rc;
  channel_->CallMethod(
      flare_rpc::GetServiceDescriptor(0)->method(1),
      ctlr, &request, &rc, nullptr);
  if (!ctlr->Failed()) {
    return rc;
  }
  return flare::Status(ctlr->ErrorCode(), ctlr->ErrorText());
}

::flare::Expected<::flare::testing::EchoResponse, ::flare::Status>
EchoService_SyncStub::EchoWithMaxOngoingRequests(
    const ::flare::testing::EchoRequest& request,
    ::flare::RpcClientController* ctlr) {
  ::flare::testing::EchoResponse rc;
  channel_->CallMethod(
      flare_rpc::GetServiceDescriptor(0)->method(2),
      ctlr, &request, &rc, nullptr);
  if (!ctlr->Failed()) {
    return rc;
  }
  return flare::Status(ctlr->ErrorCode(), ctlr->ErrorText());
}

std::pair<
    ::flare::StreamReader<::flare::testing::EchoResponse>,
    ::flare::StreamWriter<::flare::testing::EchoRequest>>
EchoService_SyncStub::EchoStreamRequest(
    ::flare::RpcClientController* ctlr) {
  channel_->CallMethod(
      flare_rpc::GetServiceDescriptor(0)->method(3),
      ctlr, nullptr, nullptr, nullptr);
  return std::pair(ctlr->GetStreamReader<::flare::testing::EchoResponse>(),
                   ctlr->GetStreamWriter<::flare::testing::EchoRequest>());
}

::flare::StreamReader<::flare::testing::EchoResponse>
EchoService_SyncStub::EchoStreamResponse(
    const ::flare::testing::EchoRequest& request,
    ::flare::RpcClientController* ctlr) {
  channel_->CallMethod(
      flare_rpc::GetServiceDescriptor(0)->method(4),
      ctlr, &request, nullptr, nullptr);
  return ctlr->GetStreamReader<::flare::testing::EchoResponse>();
}

std::pair<
    ::flare::StreamReader<::flare::testing::EchoResponse>,
    ::flare::StreamWriter<::flare::testing::EchoRequest>>
EchoService_SyncStub::EchoStreamBoth(
    ::flare::RpcClientController* ctlr) {
  channel_->CallMethod(
      flare_rpc::GetServiceDescriptor(0)->method(5),
      ctlr, nullptr, nullptr, nullptr);
  return std::pair(ctlr->GetStreamReader<::flare::testing::EchoResponse>(),
                   ctlr->GetStreamWriter<::flare::testing::EchoRequest>());
}

EchoService_AsyncStub::EchoService_AsyncStub(const std::string& uri) {
  channel_ = std::make_unique<flare::RpcChannel>(uri);
}
::flare::Future<
    ::flare::Expected<::flare::testing::EchoResponse, ::flare::Status>>
EchoService_AsyncStub::Echo(
    const ::flare::testing::EchoRequest& request,
    ::flare::RpcClientController* ctlr) {
  ::flare::Promise<::flare::Expected<::flare::testing::EchoResponse,
                   ::flare::Status>> p;
  auto rf = p.GetFuture();
  auto rc = std::make_unique<::flare::testing::EchoResponse>();
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

::flare::Future<
    ::flare::Expected<::flare::testing::EchoResponse, ::flare::Status>>
EchoService_AsyncStub::EchoWithMaxQueueingDelay(
    const ::flare::testing::EchoRequest& request,
    ::flare::RpcClientController* ctlr) {
  ::flare::Promise<::flare::Expected<::flare::testing::EchoResponse,
                   ::flare::Status>> p;
  auto rf = p.GetFuture();
  auto rc = std::make_unique<::flare::testing::EchoResponse>();
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
      flare_rpc::GetServiceDescriptor(0)->method(1),
      ctlr, &request, rcp, flare::NewCallback(std::move(cb)));
  return rf;
}

::flare::Future<
    ::flare::Expected<::flare::testing::EchoResponse, ::flare::Status>>
EchoService_AsyncStub::EchoWithMaxOngoingRequests(
    const ::flare::testing::EchoRequest& request,
    ::flare::RpcClientController* ctlr) {
  ::flare::Promise<::flare::Expected<::flare::testing::EchoResponse,
                   ::flare::Status>> p;
  auto rf = p.GetFuture();
  auto rc = std::make_unique<::flare::testing::EchoResponse>();
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
      flare_rpc::GetServiceDescriptor(0)->method(2),
      ctlr, &request, rcp, flare::NewCallback(std::move(cb)));
  return rf;
}

std::pair<
    ::flare::AsyncStreamReader<::flare::testing::EchoResponse>,
    ::flare::AsyncStreamWriter<::flare::testing::EchoRequest>>
EchoService_AsyncStub::EchoStreamRequest(
    ::flare::RpcClientController* ctlr) {
  channel_->CallMethod(
      flare_rpc::GetServiceDescriptor(0)->method(3),
      ctlr, nullptr, nullptr, nullptr);
  return std::pair(ctlr->GetAsyncStreamReader<::flare::testing::EchoResponse>(),
                   ctlr->GetAsyncStreamWriter<::flare::testing::EchoRequest>());
}

::flare::AsyncStreamReader<::flare::testing::EchoResponse>
EchoService_AsyncStub::EchoStreamResponse(
    const ::flare::testing::EchoRequest& request,
    ::flare::RpcClientController* ctlr) {
  channel_->CallMethod(
      flare_rpc::GetServiceDescriptor(0)->method(4),
      ctlr, &request, nullptr, nullptr);
  return ctlr->GetAsyncStreamReader<::flare::testing::EchoResponse>();
}

std::pair<
  ::flare::AsyncStreamReader<::flare::testing::EchoResponse>,
  ::flare::AsyncStreamWriter<::flare::testing::EchoRequest>
> EchoService_AsyncStub::EchoStreamBoth(
    ::flare::RpcClientController* ctlr) {
  channel_->CallMethod(
      flare_rpc::GetServiceDescriptor(0)->method(5),
      ctlr, nullptr, nullptr, nullptr);
  return std::pair(ctlr->GetAsyncStreamReader<::flare::testing::EchoResponse>(),
                   ctlr->GetAsyncStreamWriter<::flare::testing::EchoRequest>());
}


}


