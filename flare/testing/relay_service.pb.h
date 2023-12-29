// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: flare/testing/relay_service.proto

#ifndef PROTOBUF_flare_2ftesting_2frelay_5fservice_2eproto__INCLUDED
#define PROTOBUF_flare_2ftesting_2frelay_5fservice_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
#include "flare/rpc/rpc_options.pb.h"
// @@protoc_insertion_point(includes)
namespace flare {
namespace testing {
class RelayRequest;
class RelayRequestDefaultTypeInternal;
extern RelayRequestDefaultTypeInternal _RelayRequest_default_instance_;
class RelayResponse;
class RelayResponseDefaultTypeInternal;
extern RelayResponseDefaultTypeInternal _RelayResponse_default_instance_;
}  // namespace testing
}  // namespace flare

namespace flare {
namespace testing {

namespace protobuf_flare_2ftesting_2frelay_5fservice_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_flare_2ftesting_2frelay_5fservice_2eproto

// ===================================================================

class RelayRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:flare.testing.RelayRequest) */ {
 public:
  RelayRequest();
  virtual ~RelayRequest();

  RelayRequest(const RelayRequest& from);

  inline RelayRequest& operator=(const RelayRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RelayRequest(RelayRequest&& from) noexcept
    : RelayRequest() {
    *this = ::std::move(from);
  }

  inline RelayRequest& operator=(RelayRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const RelayRequest& default_instance();

  static inline const RelayRequest* internal_default_instance() {
    return reinterpret_cast<const RelayRequest*>(
               &_RelayRequest_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(RelayRequest* other);
  friend void swap(RelayRequest& a, RelayRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RelayRequest* New() const PROTOBUF_FINAL { return New(NULL); }

  RelayRequest* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const RelayRequest& from);
  void MergeFrom(const RelayRequest& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(RelayRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

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

  // @@protoc_insertion_point(class_scope:flare.testing.RelayRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr body_;
  mutable int _cached_size_;
  friend struct protobuf_flare_2ftesting_2frelay_5fservice_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class RelayResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:flare.testing.RelayResponse) */ {
 public:
  RelayResponse();
  virtual ~RelayResponse();

  RelayResponse(const RelayResponse& from);

  inline RelayResponse& operator=(const RelayResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RelayResponse(RelayResponse&& from) noexcept
    : RelayResponse() {
    *this = ::std::move(from);
  }

  inline RelayResponse& operator=(RelayResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const RelayResponse& default_instance();

  static inline const RelayResponse* internal_default_instance() {
    return reinterpret_cast<const RelayResponse*>(
               &_RelayResponse_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(RelayResponse* other);
  friend void swap(RelayResponse& a, RelayResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RelayResponse* New() const PROTOBUF_FINAL { return New(NULL); }

  RelayResponse* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const RelayResponse& from);
  void MergeFrom(const RelayResponse& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(RelayResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

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

  // @@protoc_insertion_point(class_scope:flare.testing.RelayResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr body_;
  mutable int _cached_size_;
  friend struct protobuf_flare_2ftesting_2frelay_5fservice_2eproto::TableStruct;
};
// ===================================================================

class RelayService_Stub;

class RelayService : public ::google::protobuf::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline RelayService() {};
 public:
  virtual ~RelayService();

  typedef RelayService_Stub Stub;

  static const ::google::protobuf::ServiceDescriptor* descriptor();

  virtual void Relay(::google::protobuf::RpcController* controller,
                       const ::flare::testing::RelayRequest* request,
                       ::flare::testing::RelayResponse* response,
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
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(RelayService);
};

class RelayService_Stub : public RelayService {
 public:
  RelayService_Stub(::google::protobuf::RpcChannel* channel);
  RelayService_Stub(::google::protobuf::RpcChannel* channel,
                   ::google::protobuf::Service::ChannelOwnership ownership);
  ~RelayService_Stub();

  inline ::google::protobuf::RpcChannel* channel() { return channel_; }

  // implements RelayService ------------------------------------------

  void Relay(::google::protobuf::RpcController* controller,
                       const ::flare::testing::RelayRequest* request,
                       ::flare::testing::RelayResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::google::protobuf::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(RelayService_Stub);
};


// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RelayRequest

// string body = 1;
inline void RelayRequest::clear_body() {
  body_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& RelayRequest::body() const {
  // @@protoc_insertion_point(field_get:flare.testing.RelayRequest.body)
  return body_.GetNoArena();
}
inline void RelayRequest::set_body(const ::std::string& value) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:flare.testing.RelayRequest.body)
}
#if LANG_CXX11
inline void RelayRequest::set_body(::std::string&& value) {
  
  body_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:flare.testing.RelayRequest.body)
}
#endif
inline void RelayRequest::set_body(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:flare.testing.RelayRequest.body)
}
inline void RelayRequest::set_body(const char* value, size_t size) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:flare.testing.RelayRequest.body)
}
inline ::std::string* RelayRequest::mutable_body() {
  
  // @@protoc_insertion_point(field_mutable:flare.testing.RelayRequest.body)
  return body_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RelayRequest::release_body() {
  // @@protoc_insertion_point(field_release:flare.testing.RelayRequest.body)
  
  return body_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RelayRequest::set_allocated_body(::std::string* body) {
  if (body != NULL) {
    
  } else {
    
  }
  body_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), body);
  // @@protoc_insertion_point(field_set_allocated:flare.testing.RelayRequest.body)
}

// -------------------------------------------------------------------

// RelayResponse

// string body = 2;
inline void RelayResponse::clear_body() {
  body_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& RelayResponse::body() const {
  // @@protoc_insertion_point(field_get:flare.testing.RelayResponse.body)
  return body_.GetNoArena();
}
inline void RelayResponse::set_body(const ::std::string& value) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:flare.testing.RelayResponse.body)
}
#if LANG_CXX11
inline void RelayResponse::set_body(::std::string&& value) {
  
  body_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:flare.testing.RelayResponse.body)
}
#endif
inline void RelayResponse::set_body(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:flare.testing.RelayResponse.body)
}
inline void RelayResponse::set_body(const char* value, size_t size) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:flare.testing.RelayResponse.body)
}
inline ::std::string* RelayResponse::mutable_body() {
  
  // @@protoc_insertion_point(field_mutable:flare.testing.RelayResponse.body)
  return body_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RelayResponse::release_body() {
  // @@protoc_insertion_point(field_release:flare.testing.RelayResponse.body)
  
  return body_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RelayResponse::set_allocated_body(::std::string* body) {
  if (body != NULL) {
    
  } else {
    
  }
  body_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), body);
  // @@protoc_insertion_point(field_set_allocated:flare.testing.RelayResponse.body)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace testing
}  // namespace flare

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_flare_2ftesting_2frelay_5fservice_2eproto__INCLUDED
