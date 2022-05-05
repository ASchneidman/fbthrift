/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include "thrift/compiler/test/fixtures/tablebased/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/tablebased/gen-cpp2/module_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "thrift/compiler/test/fixtures/tablebased/gen-cpp2/module_data.h"


namespace apache { namespace thrift {

constexpr std::size_t const TEnumTraits<::test::fixtures::tablebased::ExampleEnum>::size;
folly::Range<::test::fixtures::tablebased::ExampleEnum const*> const TEnumTraits<::test::fixtures::tablebased::ExampleEnum>::values = folly::range(TEnumDataStorage<::test::fixtures::tablebased::ExampleEnum>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::test::fixtures::tablebased::ExampleEnum>::names = folly::range(TEnumDataStorage<::test::fixtures::tablebased::ExampleEnum>::names);

bool TEnumTraits<::test::fixtures::tablebased::ExampleEnum>::findName(type value, folly::StringPiece* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_name(value, out);
}

bool TEnumTraits<::test::fixtures::tablebased::ExampleEnum>::findValue(folly::StringPiece name, type* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_value(name, out);
}

}} // apache::thrift

namespace test { namespace fixtures { namespace tablebased {
#ifndef ANDROID
FOLLY_PUSH_WARNING
FOLLY_GNU_DISABLE_WARNING("-Wdeprecated-declarations")
const _ExampleEnum_EnumMapFactory::ValuesToNamesMapType _ExampleEnum_VALUES_TO_NAMES = _ExampleEnum_EnumMapFactory::makeValuesToNamesMap();
const _ExampleEnum_EnumMapFactory::NamesToValuesMapType _ExampleEnum_NAMES_TO_VALUES = _ExampleEnum_EnumMapFactory::makeNamesToValuesMap();
FOLLY_POP_WARNING
#endif
}}} // test::fixtures::tablebased
namespace apache {
namespace thrift {
namespace detail {
FOLLY_PUSH_WARNING
FOLLY_GNU_DISABLE_WARNING("-Winvalid-offsetof")
template<>
constexpr ptrdiff_t fieldOffset<::test::fixtures::tablebased::TrivialTypesStruct>(std::int16_t fieldIndex) {
  constexpr ptrdiff_t offsets[] = {
    offsetof(::test::fixtures::tablebased::TrivialTypesStruct, __fbthrift_field_fieldA),
    offsetof(::test::fixtures::tablebased::TrivialTypesStruct, __fbthrift_field_fieldB),
    offsetof(::test::fixtures::tablebased::TrivialTypesStruct, __fbthrift_field_fieldC),
    offsetof(::test::fixtures::tablebased::TrivialTypesStruct, fieldD),
    offsetof(::test::fixtures::tablebased::TrivialTypesStruct, __fbthrift_field_fieldE)};
  return offsets[fieldIndex];
}

template<>
constexpr ptrdiff_t issetOffset<::test::fixtures::tablebased::TrivialTypesStruct>(std::int16_t fieldIndex) {
  constexpr ptrdiff_t offsets[] = {
    offsetof(::test::fixtures::tablebased::TrivialTypesStruct, __isset) + isset_bitset<5>::get_offset() + 0,
    offsetof(::test::fixtures::tablebased::TrivialTypesStruct, __isset) + isset_bitset<5>::get_offset() + 1,
    offsetof(::test::fixtures::tablebased::TrivialTypesStruct, __isset) + isset_bitset<5>::get_offset() + 2,
    offsetof(::test::fixtures::tablebased::TrivialTypesStruct, __isset) + isset_bitset<5>::get_offset() + 3,
    offsetof(::test::fixtures::tablebased::TrivialTypesStruct, __isset) + isset_bitset<5>::get_offset() + 4};
  return offsets[fieldIndex];
}

template<>
constexpr ptrdiff_t fieldOffset<::test::fixtures::tablebased::ContainerStruct>(std::int16_t fieldIndex) {
  constexpr ptrdiff_t offsets[] = {
    offsetof(::test::fixtures::tablebased::ContainerStruct, __fbthrift_field_fieldB),
    offsetof(::test::fixtures::tablebased::ContainerStruct, __fbthrift_field_fieldC),
    offsetof(::test::fixtures::tablebased::ContainerStruct, __fbthrift_field_fieldD),
    offsetof(::test::fixtures::tablebased::ContainerStruct, __fbthrift_field_fieldE),
    offsetof(::test::fixtures::tablebased::ContainerStruct, __fbthrift_field_fieldF),
    offsetof(::test::fixtures::tablebased::ContainerStruct, __fbthrift_field_fieldG),
    offsetof(::test::fixtures::tablebased::ContainerStruct, __fbthrift_field_fieldH),
    offsetof(::test::fixtures::tablebased::ContainerStruct, __fbthrift_field_fieldA)};
  return offsets[fieldIndex];
}

template<>
constexpr ptrdiff_t issetOffset<::test::fixtures::tablebased::ContainerStruct>(std::int16_t fieldIndex) {
  constexpr ptrdiff_t offsets[] = {
    offsetof(::test::fixtures::tablebased::ContainerStruct, __isset) + isset_bitset<8>::get_offset() + 1,
    offsetof(::test::fixtures::tablebased::ContainerStruct, __isset) + isset_bitset<8>::get_offset() + 2,
    offsetof(::test::fixtures::tablebased::ContainerStruct, __isset) + isset_bitset<8>::get_offset() + 3,
    offsetof(::test::fixtures::tablebased::ContainerStruct, __isset) + isset_bitset<8>::get_offset() + 4,
    offsetof(::test::fixtures::tablebased::ContainerStruct, __isset) + isset_bitset<8>::get_offset() + 5,
    offsetof(::test::fixtures::tablebased::ContainerStruct, __isset) + isset_bitset<8>::get_offset() + 6,
    offsetof(::test::fixtures::tablebased::ContainerStruct, __isset) + isset_bitset<8>::get_offset() + 7,
    offsetof(::test::fixtures::tablebased::ContainerStruct, __isset) + isset_bitset<8>::get_offset() + 0};
  return offsets[fieldIndex];
}


template<>
constexpr ptrdiff_t unionTypeOffset<::test::fixtures::tablebased::ExampleUnion>() {
  return offsetof(::test::fixtures::tablebased::ExampleUnion, type_);
}
FOLLY_POP_WARNING
}}} // apache::thrift::detail

namespace test { namespace fixtures { namespace tablebased {

TrivialTypesStruct::TrivialTypesStruct(const TrivialTypesStruct& srcObj) {
  __fbthrift_field_fieldA = srcObj.__fbthrift_field_fieldA;
  __isset.set(0,srcObj.__isset.get(0));
  __fbthrift_field_fieldB = srcObj.__fbthrift_field_fieldB;
  __isset.set(1,srcObj.__isset.get(1));
  __fbthrift_field_fieldC = srcObj.__fbthrift_field_fieldC;
  __isset.set(2,srcObj.__isset.get(2));
  fieldD = ::apache::thrift::detail::st::copy_field<
        ::apache::thrift::type_class::binary>(srcObj.fieldD);
  __isset.set(3,srcObj.__isset.get(3));
  __fbthrift_field_fieldE = srcObj.__fbthrift_field_fieldE;
  __isset.set(4,srcObj.__isset.get(4));
}

TrivialTypesStruct& TrivialTypesStruct::operator=(const TrivialTypesStruct& src) {
  TrivialTypesStruct tmp(src);
  swap(*this, tmp);
  return *this;
}

TrivialTypesStruct::TrivialTypesStruct() :
      __fbthrift_field_fieldA(),
      __fbthrift_field_fieldE() {
}


TrivialTypesStruct::~TrivialTypesStruct() {}

TrivialTypesStruct::TrivialTypesStruct(TrivialTypesStruct&& other) noexcept  :
    __fbthrift_field_fieldA(std::move(other.__fbthrift_field_fieldA)),
    __fbthrift_field_fieldB(std::move(other.__fbthrift_field_fieldB)),
    __fbthrift_field_fieldC(std::move(other.__fbthrift_field_fieldC)),
    fieldD(std::move(other.fieldD)),
    __fbthrift_field_fieldE(std::move(other.__fbthrift_field_fieldE)),
    __isset(other.__isset) {
}

TrivialTypesStruct& TrivialTypesStruct::operator=(FOLLY_MAYBE_UNUSED TrivialTypesStruct&& other) noexcept {
    this->__fbthrift_field_fieldA = std::move(other.__fbthrift_field_fieldA);
    this->__fbthrift_field_fieldB = std::move(other.__fbthrift_field_fieldB);
    this->__fbthrift_field_fieldC = std::move(other.__fbthrift_field_fieldC);
    this->fieldD = std::move(other.fieldD);
    this->__fbthrift_field_fieldE = std::move(other.__fbthrift_field_fieldE);
    __isset = other.__isset;
    return *this;
}


TrivialTypesStruct::TrivialTypesStruct(apache::thrift::FragileConstructor, ::std::int32_t fieldA__arg, ::std::string fieldB__arg, ::std::string fieldC__arg, ::test::fixtures::tablebased::IOBufPtr fieldD__arg, ::test::fixtures::tablebased::ExampleEnum fieldE__arg) :
    __fbthrift_field_fieldA(std::move(fieldA__arg)),
    __fbthrift_field_fieldB(std::move(fieldB__arg)),
    __fbthrift_field_fieldC(std::move(fieldC__arg)),
    fieldD(std::move(fieldD__arg)),
    __fbthrift_field_fieldE(std::move(fieldE__arg)) {
  __isset.set(folly::index_constant<0>(), true);
  __isset.set(folly::index_constant<1>(), true);
  __isset.set(folly::index_constant<2>(), true);
  __isset.set(folly::index_constant<3>(), true);
  __isset.set(folly::index_constant<4>(), true);
}


void TrivialTypesStruct::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_fieldA = ::std::int32_t();
  this->__fbthrift_field_fieldB = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->__fbthrift_field_fieldC = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->fieldD = apache::thrift::StringTraits<std::unique_ptr<folly::IOBuf>>::fromStringLiteral("");
  this->__fbthrift_field_fieldE = ::test::fixtures::tablebased::ExampleEnum();
  __isset = {};
}

bool TrivialTypesStruct::__fbthrift_is_empty() const {
  return false;
}

bool TrivialTypesStruct::operator==(const TrivialTypesStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.fieldA_ref() == rhs.fieldA_ref())) {
    return false;
  }
  if (!(lhs.fieldB_ref() == rhs.fieldB_ref())) {
    return false;
  }
  if (lhs.fieldC_ref().has_value() != rhs.fieldC_ref().has_value() || (lhs.fieldC_ref().has_value() && !apache::thrift::StringTraits<std::string>::isEqual(lhs.__fbthrift_field_fieldC, rhs.__fbthrift_field_fieldC))) {
    return false;
  }
  if (lhs.fieldD_ref().has_value() != rhs.fieldD_ref().has_value() || (lhs.fieldD_ref().has_value() && !apache::thrift::StringTraits<std::unique_ptr<folly::IOBuf>>::isEqual(lhs.fieldD, rhs.fieldD))) {
    return false;
  }
  if (!(lhs.fieldE_ref() == rhs.fieldE_ref())) {
    return false;
  }
  return true;
}

bool TrivialTypesStruct::operator<(const TrivialTypesStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.fieldA_ref() == rhs.fieldA_ref())) {
    return lhs.fieldA_ref() < rhs.fieldA_ref();
  }
  if (!(lhs.fieldB_ref() == rhs.fieldB_ref())) {
    return lhs.fieldB_ref() < rhs.fieldB_ref();
  }
  if (lhs.fieldC_ref().has_value() != rhs.fieldC_ref().has_value() || (lhs.fieldC_ref().has_value() && !apache::thrift::StringTraits<std::string>::isEqual(lhs.__fbthrift_field_fieldC, rhs.__fbthrift_field_fieldC))) {
    return !lhs.fieldC_ref().has_value() || (rhs.fieldC_ref().has_value() && apache::thrift::StringTraits<std::string>::isLess(lhs.__fbthrift_field_fieldC, rhs.__fbthrift_field_fieldC));
  }
  if (lhs.fieldD_ref().has_value() != rhs.fieldD_ref().has_value() || (lhs.fieldD_ref().has_value() && !apache::thrift::StringTraits<std::unique_ptr<folly::IOBuf>>::isEqual(lhs.fieldD, rhs.fieldD))) {
    return !lhs.fieldD_ref().has_value() || (rhs.fieldD_ref().has_value() && apache::thrift::StringTraits<std::unique_ptr<folly::IOBuf>>::isLess(lhs.fieldD, rhs.fieldD));
  }
  if (!(lhs.fieldE_ref() == rhs.fieldE_ref())) {
    return lhs.fieldE_ref() < rhs.fieldE_ref();
  }
  return false;
}


void swap(TrivialTypesStruct& a, TrivialTypesStruct& b) {
  using ::std::swap;
  swap(a.fieldA_ref().value_unchecked(), b.fieldA_ref().value_unchecked());
  swap(a.fieldB_ref().value_unchecked(), b.fieldB_ref().value_unchecked());
  swap(a.fieldC_ref().value_unchecked(), b.fieldC_ref().value_unchecked());
  swap(a.fieldD_ref().value_unchecked(), b.fieldD_ref().value_unchecked());
  swap(a.fieldE_ref().value(), b.fieldE_ref().value());
  swap(a.__isset, b.__isset);
}

template void TrivialTypesStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t TrivialTypesStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t TrivialTypesStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t TrivialTypesStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void TrivialTypesStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t TrivialTypesStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t TrivialTypesStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t TrivialTypesStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;
template void TrivialTypesStruct::readNoXfer<>(apache::thrift::SimpleJSONProtocolReader*);
template uint32_t TrivialTypesStruct::write<>(apache::thrift::SimpleJSONProtocolWriter*) const;
template uint32_t TrivialTypesStruct::serializedSize<>(apache::thrift::SimpleJSONProtocolWriter const*) const;
template uint32_t TrivialTypesStruct::serializedSizeZC<>(apache::thrift::SimpleJSONProtocolWriter const*) const;

constexpr ::apache::thrift::detail::StructInfoN<5> __fbthrift_struct_info_TrivialTypesStruct = {
  /* .numFields */ 5,
  /* .name */ "TrivialTypesStruct",
  /* .unionExt */ nullptr,
  /* .getIsset */ nullptr,
  /* .setIsset */ nullptr,
  /* .customExt */ nullptr,
  /* .fieldInfos */ {
  {
    /* .id */ 1,
    /* .isUnqualified */ false,
    /* .name */ "fieldA",
    /* .memberOffset */ ::apache::thrift::detail::fieldOffset<::test::fixtures::tablebased::TrivialTypesStruct>(0),
    /* .issetOffset */ ::apache::thrift::detail::issetOffset<::test::fixtures::tablebased::TrivialTypesStruct>(0),
    /* .typeInfo */ &::apache::thrift::detail::TypeToInfo<::apache::thrift::type_class::integral, ::std::int32_t>::typeInfo,
  },
  {
    /* .id */ 2,
    /* .isUnqualified */ false,
    /* .name */ "fieldB",
    /* .memberOffset */ ::apache::thrift::detail::fieldOffset<::test::fixtures::tablebased::TrivialTypesStruct>(1),
    /* .issetOffset */ ::apache::thrift::detail::issetOffset<::test::fixtures::tablebased::TrivialTypesStruct>(1),
    /* .typeInfo */ &::apache::thrift::detail::TypeToInfo<::apache::thrift::type_class::string, ::std::string>::typeInfo,
  },
  {
    /* .id */ 3,
    /* .isUnqualified */ false,
    /* .name */ "fieldC",
    /* .memberOffset */ ::apache::thrift::detail::fieldOffset<::test::fixtures::tablebased::TrivialTypesStruct>(2),
    /* .issetOffset */ ::apache::thrift::detail::issetOffset<::test::fixtures::tablebased::TrivialTypesStruct>(2),
    /* .typeInfo */ &::apache::thrift::detail::TypeToInfo<::apache::thrift::type_class::binary, ::std::string>::typeInfo,
  },
  {
    /* .id */ 4,
    /* .isUnqualified */ false,
    /* .name */ "fieldD",
    /* .memberOffset */ ::apache::thrift::detail::fieldOffset<::test::fixtures::tablebased::TrivialTypesStruct>(3),
    /* .issetOffset */ ::apache::thrift::detail::issetOffset<::test::fixtures::tablebased::TrivialTypesStruct>(3),
    /* .typeInfo */ &::apache::thrift::detail::TypeToInfo<::apache::thrift::type_class::binary, ::test::fixtures::tablebased::IOBufPtr>::typeInfo,
  },
  {
    /* .id */ 5,
    /* .isUnqualified */ true,
    /* .name */ "fieldE",
    /* .memberOffset */ ::apache::thrift::detail::fieldOffset<::test::fixtures::tablebased::TrivialTypesStruct>(4),
    /* .issetOffset */ ::apache::thrift::detail::issetOffset<::test::fixtures::tablebased::TrivialTypesStruct>(4),
    /* .typeInfo */ &::apache::thrift::detail::TypeToInfo<::apache::thrift::type_class::enumeration, ::test::fixtures::tablebased::ExampleEnum>::typeInfo,
  }}
};

}}} // test::fixtures::tablebased

namespace test { namespace fixtures { namespace tablebased {

ContainerStruct::ContainerStruct(const ContainerStruct&) = default;
ContainerStruct& ContainerStruct::operator=(const ContainerStruct&) = default;
ContainerStruct::ContainerStruct() {
}


ContainerStruct::~ContainerStruct() {}

ContainerStruct::ContainerStruct(ContainerStruct&& other) noexcept  :
    __fbthrift_field_fieldA(std::move(other.__fbthrift_field_fieldA)),
    __fbthrift_field_fieldB(std::move(other.__fbthrift_field_fieldB)),
    __fbthrift_field_fieldC(std::move(other.__fbthrift_field_fieldC)),
    __fbthrift_field_fieldD(std::move(other.__fbthrift_field_fieldD)),
    __fbthrift_field_fieldE(std::move(other.__fbthrift_field_fieldE)),
    __fbthrift_field_fieldF(std::move(other.__fbthrift_field_fieldF)),
    __fbthrift_field_fieldG(std::move(other.__fbthrift_field_fieldG)),
    __fbthrift_field_fieldH(std::move(other.__fbthrift_field_fieldH)),
    __isset(other.__isset) {
}

ContainerStruct& ContainerStruct::operator=(FOLLY_MAYBE_UNUSED ContainerStruct&& other) noexcept {
    this->__fbthrift_field_fieldA = std::move(other.__fbthrift_field_fieldA);
    this->__fbthrift_field_fieldB = std::move(other.__fbthrift_field_fieldB);
    this->__fbthrift_field_fieldC = std::move(other.__fbthrift_field_fieldC);
    this->__fbthrift_field_fieldD = std::move(other.__fbthrift_field_fieldD);
    this->__fbthrift_field_fieldE = std::move(other.__fbthrift_field_fieldE);
    this->__fbthrift_field_fieldF = std::move(other.__fbthrift_field_fieldF);
    this->__fbthrift_field_fieldG = std::move(other.__fbthrift_field_fieldG);
    this->__fbthrift_field_fieldH = std::move(other.__fbthrift_field_fieldH);
    __isset = other.__isset;
    return *this;
}


ContainerStruct::ContainerStruct(apache::thrift::FragileConstructor, ::std::vector<::std::int32_t> fieldA__arg, std::list<::std::int32_t> fieldB__arg, std::deque<::std::int32_t> fieldC__arg, folly::fbvector<::std::int32_t> fieldD__arg, folly::small_vector<::std::int32_t> fieldE__arg, folly::sorted_vector_set<::std::int32_t> fieldF__arg, folly::sorted_vector_map<::std::int32_t, ::std::string> fieldG__arg, ::std::vector<::test::fixtures::tablebased::TrivialTypesStruct> fieldH__arg) :
    __fbthrift_field_fieldA(std::move(fieldA__arg)),
    __fbthrift_field_fieldB(std::move(fieldB__arg)),
    __fbthrift_field_fieldC(std::move(fieldC__arg)),
    __fbthrift_field_fieldD(std::move(fieldD__arg)),
    __fbthrift_field_fieldE(std::move(fieldE__arg)),
    __fbthrift_field_fieldF(std::move(fieldF__arg)),
    __fbthrift_field_fieldG(std::move(fieldG__arg)),
    __fbthrift_field_fieldH(std::move(fieldH__arg)) {
  __isset.set(folly::index_constant<0>(), true);
  __isset.set(folly::index_constant<1>(), true);
  __isset.set(folly::index_constant<2>(), true);
  __isset.set(folly::index_constant<3>(), true);
  __isset.set(folly::index_constant<4>(), true);
  __isset.set(folly::index_constant<5>(), true);
  __isset.set(folly::index_constant<6>(), true);
  __isset.set(folly::index_constant<7>(), true);
}


void ContainerStruct::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_fieldA.clear();
  this->__fbthrift_field_fieldB.clear();
  this->__fbthrift_field_fieldC.clear();
  this->__fbthrift_field_fieldD.clear();
  this->__fbthrift_field_fieldE.clear();
  this->__fbthrift_field_fieldF.clear();
  this->__fbthrift_field_fieldG.clear();
  this->__fbthrift_field_fieldH.clear();
  __isset = {};
}

bool ContainerStruct::__fbthrift_is_empty() const {
  return false;
}

bool ContainerStruct::operator==(const ContainerStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.fieldA_ref() == rhs.fieldA_ref())) {
    return false;
  }
  if (!(lhs.fieldB_ref() == rhs.fieldB_ref())) {
    return false;
  }
  if (!(lhs.fieldC_ref() == rhs.fieldC_ref())) {
    return false;
  }
  if (!(lhs.fieldD_ref() == rhs.fieldD_ref())) {
    return false;
  }
  if (!(lhs.fieldE_ref() == rhs.fieldE_ref())) {
    return false;
  }
  if (!(lhs.fieldF_ref() == rhs.fieldF_ref())) {
    return false;
  }
  if (!(lhs.fieldG_ref() == rhs.fieldG_ref())) {
    return false;
  }
  if (!(lhs.fieldH_ref() == rhs.fieldH_ref())) {
    return false;
  }
  return true;
}

const ::std::vector<::std::int32_t>& ContainerStruct::get_fieldA() const& {
  return __fbthrift_field_fieldA;
}

::std::vector<::std::int32_t> ContainerStruct::get_fieldA() && {
  return std::move(__fbthrift_field_fieldA);
}

const std::list<::std::int32_t>& ContainerStruct::get_fieldB() const& {
  return __fbthrift_field_fieldB;
}

std::list<::std::int32_t> ContainerStruct::get_fieldB() && {
  return std::move(__fbthrift_field_fieldB);
}

const std::deque<::std::int32_t>& ContainerStruct::get_fieldC() const& {
  return __fbthrift_field_fieldC;
}

std::deque<::std::int32_t> ContainerStruct::get_fieldC() && {
  return std::move(__fbthrift_field_fieldC);
}

const folly::fbvector<::std::int32_t>& ContainerStruct::get_fieldD() const& {
  return __fbthrift_field_fieldD;
}

folly::fbvector<::std::int32_t> ContainerStruct::get_fieldD() && {
  return std::move(__fbthrift_field_fieldD);
}

const folly::small_vector<::std::int32_t>& ContainerStruct::get_fieldE() const& {
  return __fbthrift_field_fieldE;
}

folly::small_vector<::std::int32_t> ContainerStruct::get_fieldE() && {
  return std::move(__fbthrift_field_fieldE);
}

const folly::sorted_vector_set<::std::int32_t>& ContainerStruct::get_fieldF() const& {
  return __fbthrift_field_fieldF;
}

folly::sorted_vector_set<::std::int32_t> ContainerStruct::get_fieldF() && {
  return std::move(__fbthrift_field_fieldF);
}

const folly::sorted_vector_map<::std::int32_t, ::std::string>& ContainerStruct::get_fieldG() const& {
  return __fbthrift_field_fieldG;
}

folly::sorted_vector_map<::std::int32_t, ::std::string> ContainerStruct::get_fieldG() && {
  return std::move(__fbthrift_field_fieldG);
}

const ::std::vector<::test::fixtures::tablebased::TrivialTypesStruct>& ContainerStruct::get_fieldH() const& {
  return __fbthrift_field_fieldH;
}

::std::vector<::test::fixtures::tablebased::TrivialTypesStruct> ContainerStruct::get_fieldH() && {
  return std::move(__fbthrift_field_fieldH);
}


void swap(ContainerStruct& a, ContainerStruct& b) {
  using ::std::swap;
  swap(a.fieldA_ref().value(), b.fieldA_ref().value());
  swap(a.fieldB_ref().value(), b.fieldB_ref().value());
  swap(a.fieldC_ref().value(), b.fieldC_ref().value());
  swap(a.fieldD_ref().value(), b.fieldD_ref().value());
  swap(a.fieldE_ref().value(), b.fieldE_ref().value());
  swap(a.fieldF_ref().value(), b.fieldF_ref().value());
  swap(a.fieldG_ref().value(), b.fieldG_ref().value());
  swap(a.fieldH_ref().value(), b.fieldH_ref().value());
  swap(a.__isset, b.__isset);
}

template void ContainerStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t ContainerStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t ContainerStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t ContainerStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void ContainerStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t ContainerStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t ContainerStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t ContainerStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;
template void ContainerStruct::readNoXfer<>(apache::thrift::SimpleJSONProtocolReader*);
template uint32_t ContainerStruct::write<>(apache::thrift::SimpleJSONProtocolWriter*) const;
template uint32_t ContainerStruct::serializedSize<>(apache::thrift::SimpleJSONProtocolWriter const*) const;
template uint32_t ContainerStruct::serializedSizeZC<>(apache::thrift::SimpleJSONProtocolWriter const*) const;

constexpr ::apache::thrift::detail::StructInfoN<8> __fbthrift_struct_info_ContainerStruct = {
  /* .numFields */ 8,
  /* .name */ "ContainerStruct",
  /* .unionExt */ nullptr,
  /* .getIsset */ nullptr,
  /* .setIsset */ nullptr,
  /* .customExt */ nullptr,
  /* .fieldInfos */ {
  {
    /* .id */ 2,
    /* .isUnqualified */ true,
    /* .name */ "fieldB",
    /* .memberOffset */ ::apache::thrift::detail::fieldOffset<::test::fixtures::tablebased::ContainerStruct>(0),
    /* .issetOffset */ ::apache::thrift::detail::issetOffset<::test::fixtures::tablebased::ContainerStruct>(0),
    /* .typeInfo */ &::apache::thrift::detail::TypeToInfo<::apache::thrift::type_class::list<::apache::thrift::type_class::integral>, std::list<::std::int32_t>>::typeInfo,
  },
  {
    /* .id */ 3,
    /* .isUnqualified */ true,
    /* .name */ "fieldC",
    /* .memberOffset */ ::apache::thrift::detail::fieldOffset<::test::fixtures::tablebased::ContainerStruct>(1),
    /* .issetOffset */ ::apache::thrift::detail::issetOffset<::test::fixtures::tablebased::ContainerStruct>(1),
    /* .typeInfo */ &::apache::thrift::detail::TypeToInfo<::apache::thrift::type_class::list<::apache::thrift::type_class::integral>, std::deque<::std::int32_t>>::typeInfo,
  },
  {
    /* .id */ 4,
    /* .isUnqualified */ true,
    /* .name */ "fieldD",
    /* .memberOffset */ ::apache::thrift::detail::fieldOffset<::test::fixtures::tablebased::ContainerStruct>(2),
    /* .issetOffset */ ::apache::thrift::detail::issetOffset<::test::fixtures::tablebased::ContainerStruct>(2),
    /* .typeInfo */ &::apache::thrift::detail::TypeToInfo<::apache::thrift::type_class::list<::apache::thrift::type_class::integral>, folly::fbvector<::std::int32_t>>::typeInfo,
  },
  {
    /* .id */ 5,
    /* .isUnqualified */ true,
    /* .name */ "fieldE",
    /* .memberOffset */ ::apache::thrift::detail::fieldOffset<::test::fixtures::tablebased::ContainerStruct>(3),
    /* .issetOffset */ ::apache::thrift::detail::issetOffset<::test::fixtures::tablebased::ContainerStruct>(3),
    /* .typeInfo */ &::apache::thrift::detail::TypeToInfo<::apache::thrift::type_class::list<::apache::thrift::type_class::integral>, folly::small_vector<::std::int32_t>>::typeInfo,
  },
  {
    /* .id */ 6,
    /* .isUnqualified */ true,
    /* .name */ "fieldF",
    /* .memberOffset */ ::apache::thrift::detail::fieldOffset<::test::fixtures::tablebased::ContainerStruct>(4),
    /* .issetOffset */ ::apache::thrift::detail::issetOffset<::test::fixtures::tablebased::ContainerStruct>(4),
    /* .typeInfo */ &::apache::thrift::detail::TypeToInfo<::apache::thrift::type_class::set<::apache::thrift::type_class::integral>, folly::sorted_vector_set<::std::int32_t>>::typeInfo,
  },
  {
    /* .id */ 7,
    /* .isUnqualified */ true,
    /* .name */ "fieldG",
    /* .memberOffset */ ::apache::thrift::detail::fieldOffset<::test::fixtures::tablebased::ContainerStruct>(5),
    /* .issetOffset */ ::apache::thrift::detail::issetOffset<::test::fixtures::tablebased::ContainerStruct>(5),
    /* .typeInfo */ &::apache::thrift::detail::TypeToInfo<::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::string>, folly::sorted_vector_map<::std::int32_t, ::std::string>>::typeInfo,
  },
  {
    /* .id */ 8,
    /* .isUnqualified */ true,
    /* .name */ "fieldH",
    /* .memberOffset */ ::apache::thrift::detail::fieldOffset<::test::fixtures::tablebased::ContainerStruct>(6),
    /* .issetOffset */ ::apache::thrift::detail::issetOffset<::test::fixtures::tablebased::ContainerStruct>(6),
    /* .typeInfo */ &::apache::thrift::detail::TypeToInfo<::apache::thrift::type_class::list<::apache::thrift::type_class::structure>, ::std::vector<::test::fixtures::tablebased::TrivialTypesStruct>>::typeInfo,
  },
  {
    /* .id */ 12,
    /* .isUnqualified */ true,
    /* .name */ "fieldA",
    /* .memberOffset */ ::apache::thrift::detail::fieldOffset<::test::fixtures::tablebased::ContainerStruct>(7),
    /* .issetOffset */ ::apache::thrift::detail::issetOffset<::test::fixtures::tablebased::ContainerStruct>(7),
    /* .typeInfo */ &::apache::thrift::detail::TypeToInfo<::apache::thrift::type_class::list<::apache::thrift::type_class::integral>, ::std::vector<::std::int32_t>>::typeInfo,
  }}
};
static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        ContainerStruct,
        ::apache::thrift::type_class::list<::apache::thrift::type_class::structure>,
        ::std::vector<::test::fixtures::tablebased::TrivialTypesStruct>>,
    "inconsistent use of json option");

}}} // test::fixtures::tablebased

namespace apache { namespace thrift {

constexpr std::size_t const TEnumTraits<::test::fixtures::tablebased::ExampleUnion::Type>::size;
folly::Range<::test::fixtures::tablebased::ExampleUnion::Type const*> const TEnumTraits<::test::fixtures::tablebased::ExampleUnion::Type>::values = folly::range(TEnumDataStorage<::test::fixtures::tablebased::ExampleUnion::Type>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::test::fixtures::tablebased::ExampleUnion::Type>::names = folly::range(TEnumDataStorage<::test::fixtures::tablebased::ExampleUnion::Type>::names);

bool TEnumTraits<::test::fixtures::tablebased::ExampleUnion::Type>::findName(type value, folly::StringPiece* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_name(value, out);
}

bool TEnumTraits<::test::fixtures::tablebased::ExampleUnion::Type>::findValue(folly::StringPiece name, type* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_value(name, out);
}
}} // apache::thrift
namespace test { namespace fixtures { namespace tablebased {

void ExampleUnion::__fbthrift_clear() {
  // clear all fields
  if (type_ == Type::__EMPTY__) { return; }
  switch(type_) {
    case Type::fieldA:
      destruct(value_.fieldA);
      break;
    case Type::fieldB:
      destruct(value_.fieldB);
      break;
    default:
      assert(false);
      break;
  }
  type_ = Type::__EMPTY__;
}

bool ExampleUnion::__fbthrift_is_empty() const {
  return type_ == Type::__EMPTY__;
}

bool ExampleUnion::operator==(const ExampleUnion& rhs) const {
  if (type_ != rhs.type_) { return false; }
  switch(type_) {
    case Type::fieldA:
      return value_.fieldA == rhs.value_.fieldA;
    case Type::fieldB:
      return value_.fieldB == rhs.value_.fieldB;
    default:
      return true;
  }
}

void swap(ExampleUnion& a, ExampleUnion& b) {
  ExampleUnion temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template void ExampleUnion::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t ExampleUnion::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t ExampleUnion::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t ExampleUnion::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void ExampleUnion::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t ExampleUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t ExampleUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t ExampleUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;
template void ExampleUnion::readNoXfer<>(apache::thrift::SimpleJSONProtocolReader*);
template uint32_t ExampleUnion::write<>(apache::thrift::SimpleJSONProtocolWriter*) const;
template uint32_t ExampleUnion::serializedSize<>(apache::thrift::SimpleJSONProtocolWriter const*) const;
template uint32_t ExampleUnion::serializedSizeZC<>(apache::thrift::SimpleJSONProtocolWriter const*) const;

constexpr ::apache::thrift::detail::UnionExtN<2> ExampleUnion_unionExt = {
  /* .clear */ ::apache::thrift::detail::clearUnion<::test::fixtures::tablebased::ExampleUnion>,
  /* .unionTypeOffset */ ::apache::thrift::detail::unionTypeOffset<::test::fixtures::tablebased::ExampleUnion>(),
  /* .getActiveId */ nullptr,
  /* .setActiveId */ nullptr,
  /* .initMember */ {
  ::apache::thrift::detail::placementNewUnionValue<::test::fixtures::tablebased::ContainerStruct>,
::apache::thrift::detail::placementNewUnionValue<::test::fixtures::tablebased::TrivialTypesStruct>},
};
constexpr ::apache::thrift::detail::StructInfoN<2> __fbthrift_struct_info_ExampleUnion = {
  /* .numFields */ 2,
  /* .name */ "ExampleUnion",
  /* .unionExt */ &ExampleUnion_unionExt,
  /* .getIsset */ nullptr,
  /* .setIsset */ nullptr,
  /* .customExt */ nullptr,
  /* .fieldInfos */ {
  {
    /* .id */ 1,
    /* .isUnqualified */ true,
    /* .name */ "fieldA",
    /* .memberOffset */ 0,
    /* .issetOffset */ 0,
    /* .typeInfo */ &::apache::thrift::detail::TypeToInfo<::apache::thrift::type_class::structure, ::test::fixtures::tablebased::ContainerStruct>::typeInfo,
  },
  {
    /* .id */ 2,
    /* .isUnqualified */ true,
    /* .name */ "fieldB",
    /* .memberOffset */ 0,
    /* .issetOffset */ 0,
    /* .typeInfo */ &::apache::thrift::detail::TypeToInfo<::apache::thrift::type_class::structure, ::test::fixtures::tablebased::TrivialTypesStruct>::typeInfo,
  }}
};
static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        ExampleUnion,
        ::apache::thrift::type_class::structure,
        ::test::fixtures::tablebased::ContainerStruct>,
    "inconsistent use of json option");
static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        ExampleUnion,
        ::apache::thrift::type_class::structure,
        ::test::fixtures::tablebased::TrivialTypesStruct>,
    "inconsistent use of json option");

}}} // test::fixtures::tablebased

namespace test { namespace fixtures { namespace tablebased { namespace {
FOLLY_MAYBE_UNUSED FOLLY_ERASE void validateAdapters() {
}
}}}} // test::fixtures::tablebased

namespace apache {
namespace thrift {
namespace detail {
const ::apache::thrift::detail::TypeInfo TypeToInfo<
    apache::thrift::type_class::enumeration,
    ::test::fixtures::tablebased::ExampleEnum>::typeInfo = {
  /* .type */ apache::thrift::protocol::TType::T_I32,
  /* .get */ get<std::int32_t, ::test::fixtures::tablebased::ExampleEnum>,
  /* .set */ reinterpret_cast<VoidFuncPtr>(set<::test::fixtures::tablebased::ExampleEnum, std::int32_t>),
  /* .typeExt */ nullptr,
};
const ::apache::thrift::detail::TypeInfo TypeToInfo<
  ::apache::thrift::type_class::structure,
  ::test::fixtures::tablebased::TrivialTypesStruct>::typeInfo = {
  /* .type */ ::apache::thrift::protocol::TType::T_STRUCT,
  /* .get */ nullptr,
  /* .set */ nullptr,
  /* .typeExt */ &::test::fixtures::tablebased::__fbthrift_struct_info_TrivialTypesStruct,
};
const ::apache::thrift::detail::TypeInfo TypeToInfo<
  ::apache::thrift::type_class::structure,
  ::test::fixtures::tablebased::ContainerStruct>::typeInfo = {
  /* .type */ ::apache::thrift::protocol::TType::T_STRUCT,
  /* .get */ nullptr,
  /* .set */ nullptr,
  /* .typeExt */ &::test::fixtures::tablebased::__fbthrift_struct_info_ContainerStruct,
};
const ::apache::thrift::detail::TypeInfo TypeToInfo<
  ::apache::thrift::type_class::variant,
  ::test::fixtures::tablebased::ExampleUnion>::typeInfo = {
  /* .type */ ::apache::thrift::protocol::TType::T_STRUCT,
  /* .get */ nullptr,
  /* .set */ nullptr,
  /* .typeExt */ &::test::fixtures::tablebased::__fbthrift_struct_info_ExampleUnion,
};
}}} // namespace apache::thrift::detail
