// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: flare/testing/relay_service.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "flare/testing/relay_service.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace flare {
namespace testing {
class RelayRequestDefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<RelayRequest>
     _instance;
} _RelayRequest_default_instance_;
class RelayResponseDefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<RelayResponse>
     _instance;
} _RelayResponse_default_instance_;

namespace protobuf_flare_2ftesting_2frelay_5fservice_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[2];
const ::google::protobuf::ServiceDescriptor* file_level_service_descriptors[1];

}  // namespace

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTableField
    const TableStruct::entries[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  {0, 0, 0, ::google::protobuf::internal::kInvalidMask, 0, 0},
};

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::AuxillaryParseTableField
    const TableStruct::aux[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ::google::protobuf::internal::AuxillaryParseTableField(),
};
PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTable const
    TableStruct::schema[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { NULL, NULL, 0, -1, -1, -1, -1, NULL, false },
  { NULL, NULL, 0, -1, -1, -1, -1, NULL, false },
};

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RelayRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RelayRequest, body_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RelayResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RelayResponse, body_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(RelayRequest)},
  { 6, -1, sizeof(RelayResponse)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_RelayRequest_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&_RelayResponse_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "flare/testing/relay_service.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, file_level_service_descriptors);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

}  // namespace
void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  ::flare::protobuf_flare_2frpc_2frpc_5foptions_2eproto::InitDefaults();
  _RelayRequest_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_RelayRequest_default_instance_);_RelayResponse_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_RelayResponse_default_instance_);}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
namespace {
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n!flare/testing/relay_service.proto\022\rfla"
      "re.testing\032\033flare/rpc/rpc_options.proto\""
      "\034\n\014RelayRequest\022\014\n\004body\030\001 \001(\t\"\035\n\rRelayRe"
      "sponse\022\014\n\004body\030\002 \001(\t2R\n\014RelayService\022B\n\005"
      "Relay\022\033.flare.testing.RelayRequest\032\034.fla"
      "re.testing.RelayResponseB\003\200\001\001b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 237);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "flare/testing/relay_service.proto", &protobuf_RegisterTypes);
  ::flare::protobuf_flare_2frpc_2frpc_5foptions_2eproto::AddDescriptors();
}
} // anonymous namespace

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_flare_2ftesting_2frelay_5fservice_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int RelayRequest::kBodyFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

RelayRequest::RelayRequest()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_flare_2ftesting_2frelay_5fservice_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:flare.testing.RelayRequest)
}
RelayRequest::RelayRequest(const RelayRequest& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  body_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.body().size() > 0) {
    body_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.body_);
  }
  // @@protoc_insertion_point(copy_constructor:flare.testing.RelayRequest)
}

void RelayRequest::SharedCtor() {
  body_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _cached_size_ = 0;
}

RelayRequest::~RelayRequest() {
  // @@protoc_insertion_point(destructor:flare.testing.RelayRequest)
  SharedDtor();
}

void RelayRequest::SharedDtor() {
  body_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void RelayRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RelayRequest::descriptor() {
  protobuf_flare_2ftesting_2frelay_5fservice_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_flare_2ftesting_2frelay_5fservice_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const RelayRequest& RelayRequest::default_instance() {
  protobuf_flare_2ftesting_2frelay_5fservice_2eproto::InitDefaults();
  return *internal_default_instance();
}

RelayRequest* RelayRequest::New(::google::protobuf::Arena* arena) const {
  RelayRequest* n = new RelayRequest;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void RelayRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:flare.testing.RelayRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  body_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

bool RelayRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:flare.testing.RelayRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string body = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_body()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->body().data(), static_cast<int>(this->body().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "flare.testing.RelayRequest.body"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:flare.testing.RelayRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:flare.testing.RelayRequest)
  return false;
#undef DO_
}

void RelayRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:flare.testing.RelayRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string body = 1;
  if (this->body().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->body().data(), static_cast<int>(this->body().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "flare.testing.RelayRequest.body");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->body(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:flare.testing.RelayRequest)
}

::google::protobuf::uint8* RelayRequest::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:flare.testing.RelayRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string body = 1;
  if (this->body().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->body().data(), static_cast<int>(this->body().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "flare.testing.RelayRequest.body");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->body(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:flare.testing.RelayRequest)
  return target;
}

size_t RelayRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:flare.testing.RelayRequest)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string body = 1;
  if (this->body().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->body());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void RelayRequest::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:flare.testing.RelayRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const RelayRequest* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const RelayRequest>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:flare.testing.RelayRequest)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:flare.testing.RelayRequest)
    MergeFrom(*source);
  }
}

void RelayRequest::MergeFrom(const RelayRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:flare.testing.RelayRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.body().size() > 0) {

    body_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.body_);
  }
}

void RelayRequest::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:flare.testing.RelayRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RelayRequest::CopyFrom(const RelayRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:flare.testing.RelayRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RelayRequest::IsInitialized() const {
  return true;
}

void RelayRequest::Swap(RelayRequest* other) {
  if (other == this) return;
  InternalSwap(other);
}
void RelayRequest::InternalSwap(RelayRequest* other) {
  using std::swap;
  body_.Swap(&other->body_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata RelayRequest::GetMetadata() const {
  protobuf_flare_2ftesting_2frelay_5fservice_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_flare_2ftesting_2frelay_5fservice_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// RelayRequest

// string body = 1;
void RelayRequest::clear_body() {
  body_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& RelayRequest::body() const {
  // @@protoc_insertion_point(field_get:flare.testing.RelayRequest.body)
  return body_.GetNoArena();
}
void RelayRequest::set_body(const ::std::string& value) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:flare.testing.RelayRequest.body)
}
#if LANG_CXX11
void RelayRequest::set_body(::std::string&& value) {
  
  body_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:flare.testing.RelayRequest.body)
}
#endif
void RelayRequest::set_body(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:flare.testing.RelayRequest.body)
}
void RelayRequest::set_body(const char* value, size_t size) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:flare.testing.RelayRequest.body)
}
::std::string* RelayRequest::mutable_body() {
  
  // @@protoc_insertion_point(field_mutable:flare.testing.RelayRequest.body)
  return body_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* RelayRequest::release_body() {
  // @@protoc_insertion_point(field_release:flare.testing.RelayRequest.body)
  
  return body_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void RelayRequest::set_allocated_body(::std::string* body) {
  if (body != NULL) {
    
  } else {
    
  }
  body_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), body);
  // @@protoc_insertion_point(field_set_allocated:flare.testing.RelayRequest.body)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int RelayResponse::kBodyFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

RelayResponse::RelayResponse()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_flare_2ftesting_2frelay_5fservice_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:flare.testing.RelayResponse)
}
RelayResponse::RelayResponse(const RelayResponse& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  body_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.body().size() > 0) {
    body_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.body_);
  }
  // @@protoc_insertion_point(copy_constructor:flare.testing.RelayResponse)
}

void RelayResponse::SharedCtor() {
  body_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _cached_size_ = 0;
}

RelayResponse::~RelayResponse() {
  // @@protoc_insertion_point(destructor:flare.testing.RelayResponse)
  SharedDtor();
}

void RelayResponse::SharedDtor() {
  body_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void RelayResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RelayResponse::descriptor() {
  protobuf_flare_2ftesting_2frelay_5fservice_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_flare_2ftesting_2frelay_5fservice_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const RelayResponse& RelayResponse::default_instance() {
  protobuf_flare_2ftesting_2frelay_5fservice_2eproto::InitDefaults();
  return *internal_default_instance();
}

RelayResponse* RelayResponse::New(::google::protobuf::Arena* arena) const {
  RelayResponse* n = new RelayResponse;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void RelayResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:flare.testing.RelayResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  body_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

bool RelayResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:flare.testing.RelayResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string body = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_body()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->body().data(), static_cast<int>(this->body().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "flare.testing.RelayResponse.body"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:flare.testing.RelayResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:flare.testing.RelayResponse)
  return false;
#undef DO_
}

void RelayResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:flare.testing.RelayResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string body = 2;
  if (this->body().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->body().data(), static_cast<int>(this->body().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "flare.testing.RelayResponse.body");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->body(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:flare.testing.RelayResponse)
}

::google::protobuf::uint8* RelayResponse::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:flare.testing.RelayResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string body = 2;
  if (this->body().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->body().data(), static_cast<int>(this->body().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "flare.testing.RelayResponse.body");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->body(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:flare.testing.RelayResponse)
  return target;
}

size_t RelayResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:flare.testing.RelayResponse)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string body = 2;
  if (this->body().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->body());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void RelayResponse::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:flare.testing.RelayResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const RelayResponse* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const RelayResponse>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:flare.testing.RelayResponse)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:flare.testing.RelayResponse)
    MergeFrom(*source);
  }
}

void RelayResponse::MergeFrom(const RelayResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:flare.testing.RelayResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.body().size() > 0) {

    body_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.body_);
  }
}

void RelayResponse::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:flare.testing.RelayResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RelayResponse::CopyFrom(const RelayResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:flare.testing.RelayResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RelayResponse::IsInitialized() const {
  return true;
}

void RelayResponse::Swap(RelayResponse* other) {
  if (other == this) return;
  InternalSwap(other);
}
void RelayResponse::InternalSwap(RelayResponse* other) {
  using std::swap;
  body_.Swap(&other->body_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata RelayResponse::GetMetadata() const {
  protobuf_flare_2ftesting_2frelay_5fservice_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_flare_2ftesting_2frelay_5fservice_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// RelayResponse

// string body = 2;
void RelayResponse::clear_body() {
  body_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& RelayResponse::body() const {
  // @@protoc_insertion_point(field_get:flare.testing.RelayResponse.body)
  return body_.GetNoArena();
}
void RelayResponse::set_body(const ::std::string& value) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:flare.testing.RelayResponse.body)
}
#if LANG_CXX11
void RelayResponse::set_body(::std::string&& value) {
  
  body_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:flare.testing.RelayResponse.body)
}
#endif
void RelayResponse::set_body(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:flare.testing.RelayResponse.body)
}
void RelayResponse::set_body(const char* value, size_t size) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:flare.testing.RelayResponse.body)
}
::std::string* RelayResponse::mutable_body() {
  
  // @@protoc_insertion_point(field_mutable:flare.testing.RelayResponse.body)
  return body_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* RelayResponse::release_body() {
  // @@protoc_insertion_point(field_release:flare.testing.RelayResponse.body)
  
  return body_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void RelayResponse::set_allocated_body(::std::string* body) {
  if (body != NULL) {
    
  } else {
    
  }
  body_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), body);
  // @@protoc_insertion_point(field_set_allocated:flare.testing.RelayResponse.body)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

RelayService::~RelayService() {}

const ::google::protobuf::ServiceDescriptor* RelayService::descriptor() {
  protobuf_flare_2ftesting_2frelay_5fservice_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_flare_2ftesting_2frelay_5fservice_2eproto::file_level_service_descriptors[0];
}

const ::google::protobuf::ServiceDescriptor* RelayService::GetDescriptor() {
  return descriptor();
}

void RelayService::Relay(::google::protobuf::RpcController* controller,
                         const ::flare::testing::RelayRequest*,
                         ::flare::testing::RelayResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Relay() not implemented.");
  done->Run();
}

void RelayService::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                             ::google::protobuf::RpcController* controller,
                             const ::google::protobuf::Message* request,
                             ::google::protobuf::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), protobuf_flare_2ftesting_2frelay_5fservice_2eproto::file_level_service_descriptors[0]);
  switch(method->index()) {
    case 0:
      Relay(controller,
             ::google::protobuf::down_cast<const ::flare::testing::RelayRequest*>(request),
             ::google::protobuf::down_cast< ::flare::testing::RelayResponse*>(response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& RelayService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::flare::testing::RelayRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::google::protobuf::MessageFactory::generated_factory()
          ->GetPrototype(method->input_type());
  }
}

const ::google::protobuf::Message& RelayService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::flare::testing::RelayResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::google::protobuf::MessageFactory::generated_factory()
          ->GetPrototype(method->output_type());
  }
}

RelayService_Stub::RelayService_Stub(::google::protobuf::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
RelayService_Stub::RelayService_Stub(
    ::google::protobuf::RpcChannel* channel,
    ::google::protobuf::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::google::protobuf::Service::STUB_OWNS_CHANNEL) {}
RelayService_Stub::~RelayService_Stub() {
  if (owns_channel_) delete channel_;
}

void RelayService_Stub::Relay(::google::protobuf::RpcController* controller,
                              const ::flare::testing::RelayRequest* request,
                              ::flare::testing::RelayResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)

}  // namespace testing
}  // namespace flare

// @@protoc_insertion_point(global_scope)