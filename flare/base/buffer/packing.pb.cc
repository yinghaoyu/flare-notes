// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: packing.proto

#include "packing.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace flare {
namespace detail {
namespace buffer {
class PackHeaderDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<PackHeader>
      _instance;
} _PackHeader_default_instance_;
}  // namespace buffer
}  // namespace detail
}  // namespace flare
namespace protobuf_packing_2eproto {
static void InitDefaultsPackHeader() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::flare::detail::buffer::_PackHeader_default_instance_;
    new (ptr) ::flare::detail::buffer::PackHeader();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::flare::detail::buffer::PackHeader::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_PackHeader =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsPackHeader}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_PackHeader.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::flare::detail::buffer::PackHeader, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::flare::detail::buffer::PackHeader, names_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::flare::detail::buffer::PackHeader, sizes_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::flare::detail::buffer::PackHeader)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::flare::detail::buffer::_PackHeader_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "packing.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\rpacking.proto\022\023flare.detail.buffer\".\n\n"
      "PackHeader\022\r\n\005names\030\001 \003(\014\022\021\n\005sizes\030\002 \003(\004"
      "B\002\020\001b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 92);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "packing.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_packing_2eproto
namespace flare {
namespace detail {
namespace buffer {

// ===================================================================

void PackHeader::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int PackHeader::kNamesFieldNumber;
const int PackHeader::kSizesFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

PackHeader::PackHeader()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_packing_2eproto::scc_info_PackHeader.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:flare.detail.buffer.PackHeader)
}
PackHeader::PackHeader(const PackHeader& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      names_(from.names_),
      sizes_(from.sizes_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:flare.detail.buffer.PackHeader)
}

void PackHeader::SharedCtor() {
}

PackHeader::~PackHeader() {
  // @@protoc_insertion_point(destructor:flare.detail.buffer.PackHeader)
  SharedDtor();
}

void PackHeader::SharedDtor() {
}

void PackHeader::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* PackHeader::descriptor() {
  ::protobuf_packing_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_packing_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const PackHeader& PackHeader::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_packing_2eproto::scc_info_PackHeader.base);
  return *internal_default_instance();
}


void PackHeader::Clear() {
// @@protoc_insertion_point(message_clear_start:flare.detail.buffer.PackHeader)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  names_.Clear();
  sizes_.Clear();
  _internal_metadata_.Clear();
}

bool PackHeader::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:flare.detail.buffer.PackHeader)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated bytes names = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->add_names()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated uint64 sizes = 2 [packed = true];
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, this->mutable_sizes())));
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 1, 18u, input, this->mutable_sizes())));
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
  // @@protoc_insertion_point(parse_success:flare.detail.buffer.PackHeader)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:flare.detail.buffer.PackHeader)
  return false;
#undef DO_
}

void PackHeader::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:flare.detail.buffer.PackHeader)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated bytes names = 1;
  for (int i = 0, n = this->names_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      1, this->names(i), output);
  }

  // repeated uint64 sizes = 2 [packed = true];
  if (this->sizes_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(2, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(static_cast< ::google::protobuf::uint32>(
        _sizes_cached_byte_size_));
  }
  for (int i = 0, n = this->sizes_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64NoTag(
      this->sizes(i), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:flare.detail.buffer.PackHeader)
}

::google::protobuf::uint8* PackHeader::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:flare.detail.buffer.PackHeader)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated bytes names = 1;
  for (int i = 0, n = this->names_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteBytesToArray(1, this->names(i), target);
  }

  // repeated uint64 sizes = 2 [packed = true];
  if (this->sizes_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      2,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
        static_cast< ::google::protobuf::int32>(
            _sizes_cached_byte_size_), target);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt64NoTagToArray(this->sizes_, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:flare.detail.buffer.PackHeader)
  return target;
}

size_t PackHeader::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:flare.detail.buffer.PackHeader)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated bytes names = 1;
  total_size += 1 *
      ::google::protobuf::internal::FromIntSize(this->names_size());
  for (int i = 0, n = this->names_size(); i < n; i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::BytesSize(
      this->names(i));
  }

  // repeated uint64 sizes = 2 [packed = true];
  {
    size_t data_size = ::google::protobuf::internal::WireFormatLite::
      UInt64Size(this->sizes_);
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
            static_cast< ::google::protobuf::int32>(data_size));
    }
    int cached_size = ::google::protobuf::internal::ToCachedSize(data_size);
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _sizes_cached_byte_size_ = cached_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void PackHeader::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:flare.detail.buffer.PackHeader)
  GOOGLE_DCHECK_NE(&from, this);
  const PackHeader* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const PackHeader>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:flare.detail.buffer.PackHeader)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:flare.detail.buffer.PackHeader)
    MergeFrom(*source);
  }
}

void PackHeader::MergeFrom(const PackHeader& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:flare.detail.buffer.PackHeader)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  names_.MergeFrom(from.names_);
  sizes_.MergeFrom(from.sizes_);
}

void PackHeader::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:flare.detail.buffer.PackHeader)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PackHeader::CopyFrom(const PackHeader& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:flare.detail.buffer.PackHeader)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PackHeader::IsInitialized() const {
  return true;
}

void PackHeader::Swap(PackHeader* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PackHeader::InternalSwap(PackHeader* other) {
  using std::swap;
  names_.InternalSwap(CastToBase(&other->names_));
  sizes_.InternalSwap(&other->sizes_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata PackHeader::GetMetadata() const {
  protobuf_packing_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_packing_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace buffer
}  // namespace detail
}  // namespace flare
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::flare::detail::buffer::PackHeader* Arena::CreateMaybeMessage< ::flare::detail::buffer::PackHeader >(Arena* arena) {
  return Arena::CreateInternal< ::flare::detail::buffer::PackHeader >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
