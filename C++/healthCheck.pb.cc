// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: healthCheck.proto

#include "healthCheck.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace grpc {
namespace health {
namespace v1 {
constexpr HealthCheckRequest::HealthCheckRequest(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : service_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct HealthCheckRequestDefaultTypeInternal {
  constexpr HealthCheckRequestDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~HealthCheckRequestDefaultTypeInternal() {}
  union {
    HealthCheckRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT HealthCheckRequestDefaultTypeInternal _HealthCheckRequest_default_instance_;
constexpr HealthCheckResponse::HealthCheckResponse(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : status_(0)
{}
struct HealthCheckResponseDefaultTypeInternal {
  constexpr HealthCheckResponseDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~HealthCheckResponseDefaultTypeInternal() {}
  union {
    HealthCheckResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT HealthCheckResponseDefaultTypeInternal _HealthCheckResponse_default_instance_;
}  // namespace v1
}  // namespace health
}  // namespace grpc
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_healthCheck_2eproto[2];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_healthCheck_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_healthCheck_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_healthCheck_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::grpc::health::v1::HealthCheckRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::grpc::health::v1::HealthCheckRequest, service_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::grpc::health::v1::HealthCheckResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::grpc::health::v1::HealthCheckResponse, status_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::grpc::health::v1::HealthCheckRequest)},
  { 7, -1, -1, sizeof(::grpc::health::v1::HealthCheckResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::grpc::health::v1::_HealthCheckRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::grpc::health::v1::_HealthCheckResponse_default_instance_),
};

const char descriptor_table_protodef_healthCheck_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\021healthCheck.proto\022\016grpc.health.v1\"%\n\022H"
  "ealthCheckRequest\022\017\n\007service\030\001 \001(\t\"\251\001\n\023H"
  "ealthCheckResponse\022A\n\006status\030\001 \001(\01621.grp"
  "c.health.v1.HealthCheckResponse.ServingS"
  "tatus\"O\n\rServingStatus\022\013\n\007UNKNOWN\020\000\022\013\n\007S"
  "ERVING\020\001\022\017\n\013NOT_SERVING\020\002\022\023\n\017SERVICE_UNK"
  "NOWN\020\0032\262\001\n\006Health\022R\n\005Check\022\".grpc.health"
  ".v1.HealthCheckRequest\032#.grpc.health.v1."
  "HealthCheckResponse\"\000\022T\n\005Watch\022\".grpc.he"
  "alth.v1.HealthCheckRequest\032#.grpc.health"
  ".v1.HealthCheckResponse\"\0000\001b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_healthCheck_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_healthCheck_2eproto = {
  false, false, 435, descriptor_table_protodef_healthCheck_2eproto, "healthCheck.proto", 
  &descriptor_table_healthCheck_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_healthCheck_2eproto::offsets,
  file_level_metadata_healthCheck_2eproto, file_level_enum_descriptors_healthCheck_2eproto, file_level_service_descriptors_healthCheck_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_healthCheck_2eproto_getter() {
  return &descriptor_table_healthCheck_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_healthCheck_2eproto(&descriptor_table_healthCheck_2eproto);
namespace grpc {
namespace health {
namespace v1 {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* HealthCheckResponse_ServingStatus_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_healthCheck_2eproto);
  return file_level_enum_descriptors_healthCheck_2eproto[0];
}
bool HealthCheckResponse_ServingStatus_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr HealthCheckResponse_ServingStatus HealthCheckResponse::UNKNOWN;
constexpr HealthCheckResponse_ServingStatus HealthCheckResponse::SERVING;
constexpr HealthCheckResponse_ServingStatus HealthCheckResponse::NOT_SERVING;
constexpr HealthCheckResponse_ServingStatus HealthCheckResponse::SERVICE_UNKNOWN;
constexpr HealthCheckResponse_ServingStatus HealthCheckResponse::ServingStatus_MIN;
constexpr HealthCheckResponse_ServingStatus HealthCheckResponse::ServingStatus_MAX;
constexpr int HealthCheckResponse::ServingStatus_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)

// ===================================================================

class HealthCheckRequest::_Internal {
 public:
};

HealthCheckRequest::HealthCheckRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:grpc.health.v1.HealthCheckRequest)
}
HealthCheckRequest::HealthCheckRequest(const HealthCheckRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  service_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_service().empty()) {
    service_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_service(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:grpc.health.v1.HealthCheckRequest)
}

void HealthCheckRequest::SharedCtor() {
service_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

HealthCheckRequest::~HealthCheckRequest() {
  // @@protoc_insertion_point(destructor:grpc.health.v1.HealthCheckRequest)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void HealthCheckRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  service_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void HealthCheckRequest::ArenaDtor(void* object) {
  HealthCheckRequest* _this = reinterpret_cast< HealthCheckRequest* >(object);
  (void)_this;
}
void HealthCheckRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void HealthCheckRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void HealthCheckRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:grpc.health.v1.HealthCheckRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  service_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* HealthCheckRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string service = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_service();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "grpc.health.v1.HealthCheckRequest.service"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* HealthCheckRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:grpc.health.v1.HealthCheckRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string service = 1;
  if (!this->_internal_service().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_service().data(), static_cast<int>(this->_internal_service().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "grpc.health.v1.HealthCheckRequest.service");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_service(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:grpc.health.v1.HealthCheckRequest)
  return target;
}

size_t HealthCheckRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:grpc.health.v1.HealthCheckRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string service = 1;
  if (!this->_internal_service().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_service());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData HealthCheckRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    HealthCheckRequest::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*HealthCheckRequest::GetClassData() const { return &_class_data_; }

void HealthCheckRequest::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<HealthCheckRequest *>(to)->MergeFrom(
      static_cast<const HealthCheckRequest &>(from));
}


void HealthCheckRequest::MergeFrom(const HealthCheckRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:grpc.health.v1.HealthCheckRequest)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_service().empty()) {
    _internal_set_service(from._internal_service());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void HealthCheckRequest::CopyFrom(const HealthCheckRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:grpc.health.v1.HealthCheckRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HealthCheckRequest::IsInitialized() const {
  return true;
}

void HealthCheckRequest::InternalSwap(HealthCheckRequest* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &service_, lhs_arena,
      &other->service_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata HealthCheckRequest::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_healthCheck_2eproto_getter, &descriptor_table_healthCheck_2eproto_once,
      file_level_metadata_healthCheck_2eproto[0]);
}

// ===================================================================

class HealthCheckResponse::_Internal {
 public:
};

HealthCheckResponse::HealthCheckResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:grpc.health.v1.HealthCheckResponse)
}
HealthCheckResponse::HealthCheckResponse(const HealthCheckResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  status_ = from.status_;
  // @@protoc_insertion_point(copy_constructor:grpc.health.v1.HealthCheckResponse)
}

void HealthCheckResponse::SharedCtor() {
status_ = 0;
}

HealthCheckResponse::~HealthCheckResponse() {
  // @@protoc_insertion_point(destructor:grpc.health.v1.HealthCheckResponse)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void HealthCheckResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void HealthCheckResponse::ArenaDtor(void* object) {
  HealthCheckResponse* _this = reinterpret_cast< HealthCheckResponse* >(object);
  (void)_this;
}
void HealthCheckResponse::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void HealthCheckResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void HealthCheckResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:grpc.health.v1.HealthCheckResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  status_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* HealthCheckResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .grpc.health.v1.HealthCheckResponse.ServingStatus status = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_status(static_cast<::grpc::health::v1::HealthCheckResponse_ServingStatus>(val));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* HealthCheckResponse::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:grpc.health.v1.HealthCheckResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .grpc.health.v1.HealthCheckResponse.ServingStatus status = 1;
  if (this->_internal_status() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_status(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:grpc.health.v1.HealthCheckResponse)
  return target;
}

size_t HealthCheckResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:grpc.health.v1.HealthCheckResponse)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .grpc.health.v1.HealthCheckResponse.ServingStatus status = 1;
  if (this->_internal_status() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_status());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData HealthCheckResponse::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    HealthCheckResponse::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*HealthCheckResponse::GetClassData() const { return &_class_data_; }

void HealthCheckResponse::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<HealthCheckResponse *>(to)->MergeFrom(
      static_cast<const HealthCheckResponse &>(from));
}


void HealthCheckResponse::MergeFrom(const HealthCheckResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:grpc.health.v1.HealthCheckResponse)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_status() != 0) {
    _internal_set_status(from._internal_status());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void HealthCheckResponse::CopyFrom(const HealthCheckResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:grpc.health.v1.HealthCheckResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HealthCheckResponse::IsInitialized() const {
  return true;
}

void HealthCheckResponse::InternalSwap(HealthCheckResponse* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(status_, other->status_);
}

::PROTOBUF_NAMESPACE_ID::Metadata HealthCheckResponse::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_healthCheck_2eproto_getter, &descriptor_table_healthCheck_2eproto_once,
      file_level_metadata_healthCheck_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace v1
}  // namespace health
}  // namespace grpc
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::grpc::health::v1::HealthCheckRequest* Arena::CreateMaybeMessage< ::grpc::health::v1::HealthCheckRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::grpc::health::v1::HealthCheckRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::grpc::health::v1::HealthCheckResponse* Arena::CreateMaybeMessage< ::grpc::health::v1::HealthCheckResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::grpc::health::v1::HealthCheckResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
