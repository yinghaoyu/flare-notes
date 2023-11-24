// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#ifndef PROTOBUF_INCLUDED_message_2eproto
#define PROTOBUF_INCLUDED_message_2eproto

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_message_2eproto 

namespace protobuf_message_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[3];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_message_2eproto
namespace flare {
namespace testing {
class ComplexMessage;
class ComplexMessageDefaultTypeInternal;
extern ComplexMessageDefaultTypeInternal _ComplexMessage_default_instance_;
class One;
class OneDefaultTypeInternal;
extern OneDefaultTypeInternal _One_default_instance_;
class Two;
class TwoDefaultTypeInternal;
extern TwoDefaultTypeInternal _Two_default_instance_;
}  // namespace testing
}  // namespace flare
namespace google {
namespace protobuf {
template<> ::flare::testing::ComplexMessage* Arena::CreateMaybeMessage<::flare::testing::ComplexMessage>(Arena*);
template<> ::flare::testing::One* Arena::CreateMaybeMessage<::flare::testing::One>(Arena*);
template<> ::flare::testing::Two* Arena::CreateMaybeMessage<::flare::testing::Two>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace flare {
namespace testing {

enum Enum {
  ENUM_0 = 0,
  ENUM_1 = 1,
  ENUM_2 = 2,
  Enum_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  Enum_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool Enum_IsValid(int value);
const Enum Enum_MIN = ENUM_0;
const Enum Enum_MAX = ENUM_2;
const int Enum_ARRAYSIZE = Enum_MAX + 1;

const ::google::protobuf::EnumDescriptor* Enum_descriptor();
inline const ::std::string& Enum_Name(Enum value) {
  return ::google::protobuf::internal::NameOfEnum(
    Enum_descriptor(), value);
}
inline bool Enum_Parse(
    const ::std::string& name, Enum* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Enum>(
    Enum_descriptor(), name, value);
}
// ===================================================================

class One : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:flare.testing.One) */ {
 public:
  One();
  virtual ~One();

  One(const One& from);

  inline One& operator=(const One& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  One(One&& from) noexcept
    : One() {
    *this = ::std::move(from);
  }

  inline One& operator=(One&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const One& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const One* internal_default_instance() {
    return reinterpret_cast<const One*>(
               &_One_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(One* other);
  friend void swap(One& a, One& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline One* New() const final {
    return CreateMaybeMessage<One>(NULL);
  }

  One* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<One>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const One& from);
  void MergeFrom(const One& from);
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
  void InternalSwap(One* other);
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

  // string str = 1;
  void clear_str();
  static const int kStrFieldNumber = 1;
  const ::std::string& str() const;
  void set_str(const ::std::string& value);
  #if LANG_CXX11
  void set_str(::std::string&& value);
  #endif
  void set_str(const char* value);
  void set_str(const char* value, size_t size);
  ::std::string* mutable_str();
  ::std::string* release_str();
  void set_allocated_str(::std::string* str);

  // int32 integer = 2;
  void clear_integer();
  static const int kIntegerFieldNumber = 2;
  ::google::protobuf::int32 integer() const;
  void set_integer(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:flare.testing.One)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr str_;
  ::google::protobuf::int32 integer_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_message_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Two : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:flare.testing.Two) */ {
 public:
  Two();
  virtual ~Two();

  Two(const Two& from);

  inline Two& operator=(const Two& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Two(Two&& from) noexcept
    : Two() {
    *this = ::std::move(from);
  }

  inline Two& operator=(Two&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Two& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Two* internal_default_instance() {
    return reinterpret_cast<const Two*>(
               &_Two_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Two* other);
  friend void swap(Two& a, Two& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Two* New() const final {
    return CreateMaybeMessage<Two>(NULL);
  }

  Two* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Two>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Two& from);
  void MergeFrom(const Two& from);
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
  void InternalSwap(Two* other);
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

  // string str = 1;
  void clear_str();
  static const int kStrFieldNumber = 1;
  const ::std::string& str() const;
  void set_str(const ::std::string& value);
  #if LANG_CXX11
  void set_str(::std::string&& value);
  #endif
  void set_str(const char* value);
  void set_str(const char* value, size_t size);
  ::std::string* mutable_str();
  ::std::string* release_str();
  void set_allocated_str(::std::string* str);

  // int32 integer = 2;
  void clear_integer();
  static const int kIntegerFieldNumber = 2;
  ::google::protobuf::int32 integer() const;
  void set_integer(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:flare.testing.Two)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr str_;
  ::google::protobuf::int32 integer_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_message_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class ComplexMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:flare.testing.ComplexMessage) */ {
 public:
  ComplexMessage();
  virtual ~ComplexMessage();

  ComplexMessage(const ComplexMessage& from);

  inline ComplexMessage& operator=(const ComplexMessage& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ComplexMessage(ComplexMessage&& from) noexcept
    : ComplexMessage() {
    *this = ::std::move(from);
  }

  inline ComplexMessage& operator=(ComplexMessage&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ComplexMessage& default_instance();

  enum NumberCase {
    kOne = 5,
    kTwo = 6,
    NUMBER_NOT_SET = 0,
  };

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ComplexMessage* internal_default_instance() {
    return reinterpret_cast<const ComplexMessage*>(
               &_ComplexMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(ComplexMessage* other);
  friend void swap(ComplexMessage& a, ComplexMessage& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ComplexMessage* New() const final {
    return CreateMaybeMessage<ComplexMessage>(NULL);
  }

  ComplexMessage* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ComplexMessage>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ComplexMessage& from);
  void MergeFrom(const ComplexMessage& from);
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
  void InternalSwap(ComplexMessage* other);
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

  // repeated int32 numbers = 7;
  int numbers_size() const;
  void clear_numbers();
  static const int kNumbersFieldNumber = 7;
  ::google::protobuf::int32 numbers(int index) const;
  void set_numbers(int index, ::google::protobuf::int32 value);
  void add_numbers(::google::protobuf::int32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      numbers() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_numbers();

  // repeated string strs = 8;
  int strs_size() const;
  void clear_strs();
  static const int kStrsFieldNumber = 8;
  const ::std::string& strs(int index) const;
  ::std::string* mutable_strs(int index);
  void set_strs(int index, const ::std::string& value);
  #if LANG_CXX11
  void set_strs(int index, ::std::string&& value);
  #endif
  void set_strs(int index, const char* value);
  void set_strs(int index, const char* value, size_t size);
  ::std::string* add_strs();
  void add_strs(const ::std::string& value);
  #if LANG_CXX11
  void add_strs(::std::string&& value);
  #endif
  void add_strs(const char* value);
  void add_strs(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& strs() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_strs();

  // string str = 2;
  void clear_str();
  static const int kStrFieldNumber = 2;
  const ::std::string& str() const;
  void set_str(const ::std::string& value);
  #if LANG_CXX11
  void set_str(::std::string&& value);
  #endif
  void set_str(const char* value);
  void set_str(const char* value, size_t size);
  ::std::string* mutable_str();
  ::std::string* release_str();
  void set_allocated_str(::std::string* str);

  // int32 integer = 1;
  void clear_integer();
  static const int kIntegerFieldNumber = 1;
  ::google::protobuf::int32 integer() const;
  void set_integer(::google::protobuf::int32 value);

  // bool boolean = 3;
  void clear_boolean();
  static const int kBooleanFieldNumber = 3;
  bool boolean() const;
  void set_boolean(bool value);

  // .flare.testing.Enum enumeration = 4;
  void clear_enumeration();
  static const int kEnumerationFieldNumber = 4;
  ::flare::testing::Enum enumeration() const;
  void set_enumeration(::flare::testing::Enum value);

  // .flare.testing.One one = 5;
  bool has_one() const;
  void clear_one();
  static const int kOneFieldNumber = 5;
  private:
  const ::flare::testing::One& _internal_one() const;
  public:
  const ::flare::testing::One& one() const;
  ::flare::testing::One* release_one();
  ::flare::testing::One* mutable_one();
  void set_allocated_one(::flare::testing::One* one);

  // .flare.testing.Two two = 6;
  bool has_two() const;
  void clear_two();
  static const int kTwoFieldNumber = 6;
  private:
  const ::flare::testing::Two& _internal_two() const;
  public:
  const ::flare::testing::Two& two() const;
  ::flare::testing::Two* release_two();
  ::flare::testing::Two* mutable_two();
  void set_allocated_two(::flare::testing::Two* two);

  void clear_number();
  NumberCase number_case() const;
  // @@protoc_insertion_point(class_scope:flare.testing.ComplexMessage)
 private:
  void set_has_one();
  void set_has_two();

  inline bool has_number() const;
  inline void clear_has_number();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > numbers_;
  mutable int _numbers_cached_byte_size_;
  ::google::protobuf::RepeatedPtrField< ::std::string> strs_;
  ::google::protobuf::internal::ArenaStringPtr str_;
  ::google::protobuf::int32 integer_;
  bool boolean_;
  int enumeration_;
  union NumberUnion {
    NumberUnion() {}
    ::flare::testing::One* one_;
    ::flare::testing::Two* two_;
  } number_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::uint32 _oneof_case_[1];

  friend struct ::protobuf_message_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// One

// string str = 1;
inline void One::clear_str() {
  str_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& One::str() const {
  // @@protoc_insertion_point(field_get:flare.testing.One.str)
  return str_.GetNoArena();
}
inline void One::set_str(const ::std::string& value) {
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:flare.testing.One.str)
}
#if LANG_CXX11
inline void One::set_str(::std::string&& value) {
  
  str_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:flare.testing.One.str)
}
#endif
inline void One::set_str(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:flare.testing.One.str)
}
inline void One::set_str(const char* value, size_t size) {
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:flare.testing.One.str)
}
inline ::std::string* One::mutable_str() {
  
  // @@protoc_insertion_point(field_mutable:flare.testing.One.str)
  return str_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* One::release_str() {
  // @@protoc_insertion_point(field_release:flare.testing.One.str)
  
  return str_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void One::set_allocated_str(::std::string* str) {
  if (str != NULL) {
    
  } else {
    
  }
  str_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), str);
  // @@protoc_insertion_point(field_set_allocated:flare.testing.One.str)
}

// int32 integer = 2;
inline void One::clear_integer() {
  integer_ = 0;
}
inline ::google::protobuf::int32 One::integer() const {
  // @@protoc_insertion_point(field_get:flare.testing.One.integer)
  return integer_;
}
inline void One::set_integer(::google::protobuf::int32 value) {
  
  integer_ = value;
  // @@protoc_insertion_point(field_set:flare.testing.One.integer)
}

// -------------------------------------------------------------------

// Two

// string str = 1;
inline void Two::clear_str() {
  str_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Two::str() const {
  // @@protoc_insertion_point(field_get:flare.testing.Two.str)
  return str_.GetNoArena();
}
inline void Two::set_str(const ::std::string& value) {
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:flare.testing.Two.str)
}
#if LANG_CXX11
inline void Two::set_str(::std::string&& value) {
  
  str_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:flare.testing.Two.str)
}
#endif
inline void Two::set_str(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:flare.testing.Two.str)
}
inline void Two::set_str(const char* value, size_t size) {
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:flare.testing.Two.str)
}
inline ::std::string* Two::mutable_str() {
  
  // @@protoc_insertion_point(field_mutable:flare.testing.Two.str)
  return str_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Two::release_str() {
  // @@protoc_insertion_point(field_release:flare.testing.Two.str)
  
  return str_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Two::set_allocated_str(::std::string* str) {
  if (str != NULL) {
    
  } else {
    
  }
  str_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), str);
  // @@protoc_insertion_point(field_set_allocated:flare.testing.Two.str)
}

// int32 integer = 2;
inline void Two::clear_integer() {
  integer_ = 0;
}
inline ::google::protobuf::int32 Two::integer() const {
  // @@protoc_insertion_point(field_get:flare.testing.Two.integer)
  return integer_;
}
inline void Two::set_integer(::google::protobuf::int32 value) {
  
  integer_ = value;
  // @@protoc_insertion_point(field_set:flare.testing.Two.integer)
}

// -------------------------------------------------------------------

// ComplexMessage

// int32 integer = 1;
inline void ComplexMessage::clear_integer() {
  integer_ = 0;
}
inline ::google::protobuf::int32 ComplexMessage::integer() const {
  // @@protoc_insertion_point(field_get:flare.testing.ComplexMessage.integer)
  return integer_;
}
inline void ComplexMessage::set_integer(::google::protobuf::int32 value) {
  
  integer_ = value;
  // @@protoc_insertion_point(field_set:flare.testing.ComplexMessage.integer)
}

// string str = 2;
inline void ComplexMessage::clear_str() {
  str_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ComplexMessage::str() const {
  // @@protoc_insertion_point(field_get:flare.testing.ComplexMessage.str)
  return str_.GetNoArena();
}
inline void ComplexMessage::set_str(const ::std::string& value) {
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:flare.testing.ComplexMessage.str)
}
#if LANG_CXX11
inline void ComplexMessage::set_str(::std::string&& value) {
  
  str_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:flare.testing.ComplexMessage.str)
}
#endif
inline void ComplexMessage::set_str(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:flare.testing.ComplexMessage.str)
}
inline void ComplexMessage::set_str(const char* value, size_t size) {
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:flare.testing.ComplexMessage.str)
}
inline ::std::string* ComplexMessage::mutable_str() {
  
  // @@protoc_insertion_point(field_mutable:flare.testing.ComplexMessage.str)
  return str_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ComplexMessage::release_str() {
  // @@protoc_insertion_point(field_release:flare.testing.ComplexMessage.str)
  
  return str_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ComplexMessage::set_allocated_str(::std::string* str) {
  if (str != NULL) {
    
  } else {
    
  }
  str_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), str);
  // @@protoc_insertion_point(field_set_allocated:flare.testing.ComplexMessage.str)
}

// bool boolean = 3;
inline void ComplexMessage::clear_boolean() {
  boolean_ = false;
}
inline bool ComplexMessage::boolean() const {
  // @@protoc_insertion_point(field_get:flare.testing.ComplexMessage.boolean)
  return boolean_;
}
inline void ComplexMessage::set_boolean(bool value) {
  
  boolean_ = value;
  // @@protoc_insertion_point(field_set:flare.testing.ComplexMessage.boolean)
}

// .flare.testing.Enum enumeration = 4;
inline void ComplexMessage::clear_enumeration() {
  enumeration_ = 0;
}
inline ::flare::testing::Enum ComplexMessage::enumeration() const {
  // @@protoc_insertion_point(field_get:flare.testing.ComplexMessage.enumeration)
  return static_cast< ::flare::testing::Enum >(enumeration_);
}
inline void ComplexMessage::set_enumeration(::flare::testing::Enum value) {
  
  enumeration_ = value;
  // @@protoc_insertion_point(field_set:flare.testing.ComplexMessage.enumeration)
}

// .flare.testing.One one = 5;
inline bool ComplexMessage::has_one() const {
  return number_case() == kOne;
}
inline void ComplexMessage::set_has_one() {
  _oneof_case_[0] = kOne;
}
inline void ComplexMessage::clear_one() {
  if (has_one()) {
    delete number_.one_;
    clear_has_number();
  }
}
inline const ::flare::testing::One& ComplexMessage::_internal_one() const {
  return *number_.one_;
}
inline ::flare::testing::One* ComplexMessage::release_one() {
  // @@protoc_insertion_point(field_release:flare.testing.ComplexMessage.one)
  if (has_one()) {
    clear_has_number();
      ::flare::testing::One* temp = number_.one_;
    number_.one_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline const ::flare::testing::One& ComplexMessage::one() const {
  // @@protoc_insertion_point(field_get:flare.testing.ComplexMessage.one)
  return has_one()
      ? *number_.one_
      : *reinterpret_cast< ::flare::testing::One*>(&::flare::testing::_One_default_instance_);
}
inline ::flare::testing::One* ComplexMessage::mutable_one() {
  if (!has_one()) {
    clear_number();
    set_has_one();
    number_.one_ = CreateMaybeMessage< ::flare::testing::One >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:flare.testing.ComplexMessage.one)
  return number_.one_;
}

// .flare.testing.Two two = 6;
inline bool ComplexMessage::has_two() const {
  return number_case() == kTwo;
}
inline void ComplexMessage::set_has_two() {
  _oneof_case_[0] = kTwo;
}
inline void ComplexMessage::clear_two() {
  if (has_two()) {
    delete number_.two_;
    clear_has_number();
  }
}
inline const ::flare::testing::Two& ComplexMessage::_internal_two() const {
  return *number_.two_;
}
inline ::flare::testing::Two* ComplexMessage::release_two() {
  // @@protoc_insertion_point(field_release:flare.testing.ComplexMessage.two)
  if (has_two()) {
    clear_has_number();
      ::flare::testing::Two* temp = number_.two_;
    number_.two_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline const ::flare::testing::Two& ComplexMessage::two() const {
  // @@protoc_insertion_point(field_get:flare.testing.ComplexMessage.two)
  return has_two()
      ? *number_.two_
      : *reinterpret_cast< ::flare::testing::Two*>(&::flare::testing::_Two_default_instance_);
}
inline ::flare::testing::Two* ComplexMessage::mutable_two() {
  if (!has_two()) {
    clear_number();
    set_has_two();
    number_.two_ = CreateMaybeMessage< ::flare::testing::Two >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:flare.testing.ComplexMessage.two)
  return number_.two_;
}

// repeated int32 numbers = 7;
inline int ComplexMessage::numbers_size() const {
  return numbers_.size();
}
inline void ComplexMessage::clear_numbers() {
  numbers_.Clear();
}
inline ::google::protobuf::int32 ComplexMessage::numbers(int index) const {
  // @@protoc_insertion_point(field_get:flare.testing.ComplexMessage.numbers)
  return numbers_.Get(index);
}
inline void ComplexMessage::set_numbers(int index, ::google::protobuf::int32 value) {
  numbers_.Set(index, value);
  // @@protoc_insertion_point(field_set:flare.testing.ComplexMessage.numbers)
}
inline void ComplexMessage::add_numbers(::google::protobuf::int32 value) {
  numbers_.Add(value);
  // @@protoc_insertion_point(field_add:flare.testing.ComplexMessage.numbers)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
ComplexMessage::numbers() const {
  // @@protoc_insertion_point(field_list:flare.testing.ComplexMessage.numbers)
  return numbers_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
ComplexMessage::mutable_numbers() {
  // @@protoc_insertion_point(field_mutable_list:flare.testing.ComplexMessage.numbers)
  return &numbers_;
}

// repeated string strs = 8;
inline int ComplexMessage::strs_size() const {
  return strs_.size();
}
inline void ComplexMessage::clear_strs() {
  strs_.Clear();
}
inline const ::std::string& ComplexMessage::strs(int index) const {
  // @@protoc_insertion_point(field_get:flare.testing.ComplexMessage.strs)
  return strs_.Get(index);
}
inline ::std::string* ComplexMessage::mutable_strs(int index) {
  // @@protoc_insertion_point(field_mutable:flare.testing.ComplexMessage.strs)
  return strs_.Mutable(index);
}
inline void ComplexMessage::set_strs(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:flare.testing.ComplexMessage.strs)
  strs_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void ComplexMessage::set_strs(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:flare.testing.ComplexMessage.strs)
  strs_.Mutable(index)->assign(std::move(value));
}
#endif
inline void ComplexMessage::set_strs(int index, const char* value) {
  GOOGLE_DCHECK(value != NULL);
  strs_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:flare.testing.ComplexMessage.strs)
}
inline void ComplexMessage::set_strs(int index, const char* value, size_t size) {
  strs_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:flare.testing.ComplexMessage.strs)
}
inline ::std::string* ComplexMessage::add_strs() {
  // @@protoc_insertion_point(field_add_mutable:flare.testing.ComplexMessage.strs)
  return strs_.Add();
}
inline void ComplexMessage::add_strs(const ::std::string& value) {
  strs_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:flare.testing.ComplexMessage.strs)
}
#if LANG_CXX11
inline void ComplexMessage::add_strs(::std::string&& value) {
  strs_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:flare.testing.ComplexMessage.strs)
}
#endif
inline void ComplexMessage::add_strs(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  strs_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:flare.testing.ComplexMessage.strs)
}
inline void ComplexMessage::add_strs(const char* value, size_t size) {
  strs_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:flare.testing.ComplexMessage.strs)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
ComplexMessage::strs() const {
  // @@protoc_insertion_point(field_list:flare.testing.ComplexMessage.strs)
  return strs_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
ComplexMessage::mutable_strs() {
  // @@protoc_insertion_point(field_mutable_list:flare.testing.ComplexMessage.strs)
  return &strs_;
}

inline bool ComplexMessage::has_number() const {
  return number_case() != NUMBER_NOT_SET;
}
inline void ComplexMessage::clear_has_number() {
  _oneof_case_[0] = NUMBER_NOT_SET;
}
inline ComplexMessage::NumberCase ComplexMessage::number_case() const {
  return ComplexMessage::NumberCase(_oneof_case_[0]);
}
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace testing
}  // namespace flare

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::flare::testing::Enum> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::flare::testing::Enum>() {
  return ::flare::testing::Enum_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_message_2eproto