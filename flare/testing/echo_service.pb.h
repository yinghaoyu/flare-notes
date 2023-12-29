// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: echo_service.proto

#ifndef PROTOBUF_INCLUDED_echo_5fservice_2eproto
#define PROTOBUF_INCLUDED_echo_5fservice_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
#include "flare/rpc/rpc_options.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_echo_5fservice_2eproto 

namespace protobuf_echo_5fservice_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_echo_5fservice_2eproto
namespace flare {
namespace testing {
class EchoRequest;
class EchoRequestDefaultTypeInternal;
extern EchoRequestDefaultTypeInternal _EchoRequest_default_instance_;
class EchoResponse;
class EchoResponseDefaultTypeInternal;
extern EchoResponseDefaultTypeInternal _EchoResponse_default_instance_;
}  // namespace testing
}  // namespace flare
namespace google {
namespace protobuf {
template<> ::flare::testing::EchoRequest* Arena::CreateMaybeMessage<::flare::testing::EchoRequest>(Arena*);
template<> ::flare::testing::EchoResponse* Arena::CreateMaybeMessage<::flare::testing::EchoResponse>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace flare {
namespace testing {

// ===================================================================

class EchoRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:flare.testing.EchoRequest) */ {
 public:
  EchoRequest();
  virtual ~EchoRequest();

  EchoRequest(const EchoRequest& from);

  inline EchoRequest& operator=(const EchoRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  EchoRequest(EchoRequest&& from) noexcept
    : EchoRequest() {
    *this = ::std::move(from);
  }

  inline EchoRequest& operator=(EchoRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const EchoRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const EchoRequest* internal_default_instance() {
    return reinterpret_cast<const EchoRequest*>(
               &_EchoRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(EchoRequest* other);
  friend void swap(EchoRequest& a, EchoRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline EchoRequest* New() const final {
    return CreateMaybeMessage<EchoRequest>(NULL);
  }

  EchoRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<EchoRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const EchoRequest& from);
  void MergeFrom(const EchoRequest& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(EchoRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string body = 1;
  void clear_body();
  static const int kBodyFieldNumber = 1;
  const ::std::string& body() const;
  void set_body(const ::std::string& value);
  #if LANG_CXX11
  void set_body(::std::string&& value);
  #endif
  void set_body(const char* value);
  void set_body(const char* value, size_t size);
  ::std::string* mutable_body();
  ::std::string* release_body();
  void set_allocated_body(::std::string* body);

  // string never_used_body = 2;
  void clear_never_used_body();
  static const int kNeverUsedBodyFieldNumber = 2;
  const ::std::string& never_used_body() const;
  void set_never_used_body(const ::std::string& value);
  #if LANG_CXX11
  void set_never_used_body(::std::string&& value);
  #endif
  void set_never_used_body(const char* value);
  void set_never_used_body(const char* value, size_t size);
  ::std::string* mutable_never_used_body();
  ::std::string* release_never_used_body();
  void set_allocated_never_used_body(::std::string* never_used_body);

  // @@protoc_insertion_point(class_scope:flare.testing.EchoRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr body_;
  ::google::protobuf::internal::ArenaStringPtr never_used_body_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_echo_5fservice_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class EchoResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:flare.testing.EchoResponse) */ {
 public:
  EchoResponse();
  virtual ~EchoResponse();

  EchoResponse(const EchoResponse& from);

  inline EchoResponse& operator=(const EchoResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  EchoResponse(EchoResponse&& from) noexcept
    : EchoResponse() {
    *this = ::std::move(from);
  }

  inline EchoResponse& operator=(EchoResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const EchoResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const EchoResponse* internal_default_instance() {
    return reinterpret_cast<const EchoResponse*>(
               &_EchoResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(EchoResponse* other);
  friend void swap(EchoResponse& a, EchoResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline EchoResponse* New() const final {
    return CreateMaybeMessage<EchoResponse>(NULL);
  }

  EchoResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<EchoResponse>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const EchoResponse& from);
  void MergeFrom(const EchoResponse& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(EchoResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string body = 2;
  void clear_body();
  static const int kBodyFieldNumber = 2;
  const ::std::string& body() const;
  void set_body(const ::std::string& value);
  #if LANG_CXX11
  void set_body(::std::string&& value);
  #endif
  void set_body(const char* value);
  void set_body(const char* value, size_t size);
  ::std::string* mutable_body();
  ::std::string* release_body();
  void set_allocated_body(::std::string* body);

  // @@protoc_insertion_point(class_scope:flare.testing.EchoResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr body_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_echo_5fservice_2eproto::TableStruct;
};
// ===================================================================

class EchoService_Stub;

class EchoService : public ::google::protobuf::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline EchoService() {};
 public:
  virtual ~EchoService();

  typedef EchoService_Stub Stub;

  static const ::google::protobuf::ServiceDescriptor* descriptor();

  virtual void Echo(::google::protobuf::RpcController* controller,
                       const ::flare::testing::EchoRequest* request,
                       ::flare::testing::EchoResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void EchoWithMaxQueueingDelay(::google::protobuf::RpcController* controller,
                       const ::flare::testing::EchoRequest* request,
                       ::flare::testing::EchoResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void EchoWithMaxOngoingRequests(::google::protobuf::RpcController* controller,
                       const ::flare::testing::EchoRequest* request,
                       ::flare::testing::EchoResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void EchoStreamRequest(::google::protobuf::RpcController* controller,
                       const ::flare::testing::EchoRequest* request,
                       ::flare::testing::EchoResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void EchoStreamResponse(::google::protobuf::RpcController* controller,
                       const ::flare::testing::EchoRequest* request,
                       ::flare::testing::EchoResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void EchoStreamBoth(::google::protobuf::RpcController* controller,
                       const ::flare::testing::EchoRequest* request,
                       ::flare::testing::EchoResponse* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::google::protobuf::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::google::protobuf::MethodDescriptor* method,
                  ::google::protobuf::RpcController* controller,
                  const ::google::protobuf::Message* request,
                  ::google::protobuf::Message* response,
                  ::google::protobuf::Closure* done);
  const ::google::protobuf::Message& GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const;
  const ::google::protobuf::Message& GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(EchoService);
};

class EchoService_Stub : public EchoService {
 public:
  EchoService_Stub(::google::protobuf::RpcChannel* channel);
  EchoService_Stub(::google::protobuf::RpcChannel* channel,
                   ::google::protobuf::Service::ChannelOwnership ownership);
  ~EchoService_Stub();

  inline ::google::protobuf::RpcChannel* channel() { return channel_; }

  // implements EchoService ------------------------------------------

  void Echo(::google::protobuf::RpcController* controller,
                       const ::flare::testing::EchoRequest* request,
                       ::flare::testing::EchoResponse* response,
                       ::google::protobuf::Closure* done);
  void EchoWithMaxQueueingDelay(::google::protobuf::RpcController* controller,
                       const ::flare::testing::EchoRequest* request,
                       ::flare::testing::EchoResponse* response,
                       ::google::protobuf::Closure* done);
  void EchoWithMaxOngoingRequests(::google::protobuf::RpcController* controller,
                       const ::flare::testing::EchoRequest* request,
                       ::flare::testing::EchoResponse* response,
                       ::google::protobuf::Closure* done);
  void EchoStreamRequest(::google::protobuf::RpcController* controller,
                       const ::flare::testing::EchoRequest* request,
                       ::flare::testing::EchoResponse* response,
                       ::google::protobuf::Closure* done);
  void EchoStreamResponse(::google::protobuf::RpcController* controller,
                       const ::flare::testing::EchoRequest* request,
                       ::flare::testing::EchoResponse* response,
                       ::google::protobuf::Closure* done);
  void EchoStreamBoth(::google::protobuf::RpcController* controller,
                       const ::flare::testing::EchoRequest* request,
                       ::flare::testing::EchoResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::google::protobuf::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(EchoService_Stub);
};


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// EchoRequest

// string body = 1;
inline void EchoRequest::clear_body() {
  body_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& EchoRequest::body() const {
  // @@protoc_insertion_point(field_get:flare.testing.EchoRequest.body)
  return body_.GetNoArena();
}
inline void EchoRequest::set_body(const ::std::string& value) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:flare.testing.EchoRequest.body)
}
#if LANG_CXX11
inline void EchoRequest::set_body(::std::string&& value) {
  
  body_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:flare.testing.EchoRequest.body)
}
#endif
inline void EchoRequest::set_body(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:flare.testing.EchoRequest.body)
}
inline void EchoRequest::set_body(const char* value, size_t size) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:flare.testing.EchoRequest.body)
}
inline ::std::string* EchoRequest::mutable_body() {
  
  // @@protoc_insertion_point(field_mutable:flare.testing.EchoRequest.body)
  return body_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* EchoRequest::release_body() {
  // @@protoc_insertion_point(field_release:flare.testing.EchoRequest.body)
  
  return body_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void EchoRequest::set_allocated_body(::std::string* body) {
  if (body != NULL) {
    
  } else {
    
  }
  body_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), body);
  // @@protoc_insertion_point(field_set_allocated:flare.testing.EchoRequest.body)
}

// string never_used_body = 2;
inline void EchoRequest::clear_never_used_body() {
  never_used_body_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& EchoRequest::never_used_body() const {
  // @@protoc_insertion_point(field_get:flare.testing.EchoRequest.never_used_body)
  return never_used_body_.GetNoArena();
}
inline void EchoRequest::set_never_used_body(const ::std::string& value) {
  
  never_used_body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:flare.testing.EchoRequest.never_used_body)
}
#if LANG_CXX11
inline void EchoRequest::set_never_used_body(::std::string&& value) {
  
  never_used_body_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:flare.testing.EchoRequest.never_used_body)
}
#endif
inline void EchoRequest::set_never_used_body(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  never_used_body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:flare.testing.EchoRequest.never_used_body)
}
inline void EchoRequest::set_never_used_body(const char* value, size_t size) {
  
  never_used_body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:flare.testing.EchoRequest.never_used_body)
}
inline ::std::string* EchoRequest::mutable_never_used_body() {
  
  // @@protoc_insertion_point(field_mutable:flare.testing.EchoRequest.never_used_body)
  return never_used_body_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* EchoRequest::release_never_used_body() {
  // @@protoc_insertion_point(field_release:flare.testing.EchoRequest.never_used_body)
  
  return never_used_body_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void EchoRequest::set_allocated_never_used_body(::std::string* never_used_body) {
  if (never_used_body != NULL) {
    
  } else {
    
  }
  never_used_body_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), never_used_body);
  // @@protoc_insertion_point(field_set_allocated:flare.testing.EchoRequest.never_used_body)
}

// -------------------------------------------------------------------

// EchoResponse

// string body = 2;
inline void EchoResponse::clear_body() {
  body_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& EchoResponse::body() const {
  // @@protoc_insertion_point(field_get:flare.testing.EchoResponse.body)
  return body_.GetNoArena();
}
inline void EchoResponse::set_body(const ::std::string& value) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:flare.testing.EchoResponse.body)
}
#if LANG_CXX11
inline void EchoResponse::set_body(::std::string&& value) {
  
  body_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:flare.testing.EchoResponse.body)
}
#endif
inline void EchoResponse::set_body(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:flare.testing.EchoResponse.body)
}
inline void EchoResponse::set_body(const char* value, size_t size) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:flare.testing.EchoResponse.body)
}
inline ::std::string* EchoResponse::mutable_body() {
  
  // @@protoc_insertion_point(field_mutable:flare.testing.EchoResponse.body)
  return body_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* EchoResponse::release_body() {
  // @@protoc_insertion_point(field_release:flare.testing.EchoResponse.body)
  
  return body_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void EchoResponse::set_allocated_body(::std::string* body) {
  if (body != NULL) {
    
  } else {
    
  }
  body_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), body);
  // @@protoc_insertion_point(field_set_allocated:flare.testing.EchoResponse.body)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace testing
}  // namespace flare

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_echo_5fservice_2eproto
