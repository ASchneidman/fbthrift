/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/compiler/test/fixtures/complex-union/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/complex-union/gen-cpp2/module_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "thrift/compiler/test/fixtures/complex-union/gen-cpp2/module_data.h"


namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::ComplexUnion>::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "intValue") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_I64;
  }
  else if (_fname == "stringValue") {
    fid = 5;
    _ftype = apache::thrift::protocol::T_STRING;
  }
  else if (_fname == "intListValue") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_LIST;
  }
  else if (_fname == "stringListValue") {
    fid = 3;
    _ftype = apache::thrift::protocol::T_LIST;
  }
  else if (_fname == "typedefValue") {
    fid = 9;
    _ftype = apache::thrift::protocol::T_MAP;
  }
  else if (_fname == "stringRef") {
    fid = 14;
    _ftype = apache::thrift::protocol::T_STRING;
  }
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace apache { namespace thrift {

constexpr std::size_t const TEnumTraits<::cpp2::ComplexUnion::Type>::size;
folly::Range<::cpp2::ComplexUnion::Type const*> const TEnumTraits<::cpp2::ComplexUnion::Type>::values = folly::range(TEnumDataStorage<::cpp2::ComplexUnion::Type>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::cpp2::ComplexUnion::Type>::names = folly::range(TEnumDataStorage<::cpp2::ComplexUnion::Type>::names);

char const* TEnumTraits<::cpp2::ComplexUnion::Type>::findName(type value) {
  using factory = detail::TEnumMapFactory<::cpp2::ComplexUnion::Type>;
  static folly::Indestructible<factory::ValuesToNamesMapType> const map{
      factory::makeValuesToNamesMap()};
  auto found = map->find(value);
  return found == map->end() ? nullptr : found->second;
}

bool TEnumTraits<::cpp2::ComplexUnion::Type>::findValue(char const* name, type* out) {
  using factory = detail::TEnumMapFactory<::cpp2::ComplexUnion::Type>;
  static folly::Indestructible<factory::NamesToValuesMapType> const map{
      factory::makeNamesToValuesMap()};
  auto found = map->find(name);
  return found == map->end() ? false : (*out = found->second, true);
}
}} // apache::thrift
namespace cpp2 {

void ComplexUnion::__clear() {
  // clear all fields
  if (type_ == Type::__EMPTY__) { return; }
  switch(type_) {
    case Type::intValue:
    {
      destruct(value_.intValue);
      break;
    }
    case Type::stringValue:
    {
      destruct(value_.stringValue);
      break;
    }
    case Type::intListValue:
    {
      destruct(value_.intListValue);
      break;
    }
    case Type::stringListValue:
    {
      destruct(value_.stringListValue);
      break;
    }
    case Type::typedefValue:
    {
      destruct(value_.typedefValue);
      break;
    }
    case Type::stringRef:
    {
      destruct(value_.stringRef);
      break;
    }
    default:
    {
      assert(false);
      break;
    }
  }
  type_ = Type::__EMPTY__;
}

bool ComplexUnion::operator==(const ComplexUnion& rhs) const {
  if (type_ != rhs.type_) { return false; }
  switch(type_) {
    case Type::intValue:
    {
      return value_.intValue == rhs.value_.intValue;
    }
    case Type::stringValue:
    {
      return value_.stringValue == rhs.value_.stringValue;
    }
    case Type::intListValue:
    {
      return value_.intListValue == rhs.value_.intListValue;
    }
    case Type::stringListValue:
    {
      return value_.stringListValue == rhs.value_.stringListValue;
    }
    case Type::typedefValue:
    {
      return value_.typedefValue == rhs.value_.typedefValue;
    }
    case Type::stringRef:
    {
      return *value_.stringRef == *rhs.value_.stringRef;
    }
    default:
    {
      return true;
    }
  }
}

bool ComplexUnion::operator<(const ComplexUnion& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (lhs.type_ != rhs.type_) {
    return lhs.type_ < rhs.type_;
  }
  switch (lhs.type_) {
    case Type::intValue:
      return lhs.value_.intValue < rhs.value_.intValue;
    case Type::stringValue:
      return lhs.value_.stringValue < rhs.value_.stringValue;
    case Type::intListValue:
      return lhs.value_.intListValue < rhs.value_.intListValue;
    case Type::stringListValue:
      return lhs.value_.stringListValue < rhs.value_.stringListValue;
    case Type::typedefValue:
      return lhs.value_.typedefValue < rhs.value_.typedefValue;
    case Type::stringRef:
      return lhs.value_.stringRef < rhs.value_.stringRef;
    default:
      return false;
  }
}

void swap(ComplexUnion& a, ComplexUnion& b) {
  ComplexUnion temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template void ComplexUnion::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t ComplexUnion::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t ComplexUnion::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t ComplexUnion::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void ComplexUnion::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t ComplexUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t ComplexUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t ComplexUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2
namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::ListUnion>::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "intListValue") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_LIST;
  }
  else if (_fname == "stringListValue") {
    fid = 3;
    _ftype = apache::thrift::protocol::T_LIST;
  }
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace apache { namespace thrift {

constexpr std::size_t const TEnumTraits<::cpp2::ListUnion::Type>::size;
folly::Range<::cpp2::ListUnion::Type const*> const TEnumTraits<::cpp2::ListUnion::Type>::values = folly::range(TEnumDataStorage<::cpp2::ListUnion::Type>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::cpp2::ListUnion::Type>::names = folly::range(TEnumDataStorage<::cpp2::ListUnion::Type>::names);

char const* TEnumTraits<::cpp2::ListUnion::Type>::findName(type value) {
  using factory = detail::TEnumMapFactory<::cpp2::ListUnion::Type>;
  static folly::Indestructible<factory::ValuesToNamesMapType> const map{
      factory::makeValuesToNamesMap()};
  auto found = map->find(value);
  return found == map->end() ? nullptr : found->second;
}

bool TEnumTraits<::cpp2::ListUnion::Type>::findValue(char const* name, type* out) {
  using factory = detail::TEnumMapFactory<::cpp2::ListUnion::Type>;
  static folly::Indestructible<factory::NamesToValuesMapType> const map{
      factory::makeNamesToValuesMap()};
  auto found = map->find(name);
  return found == map->end() ? false : (*out = found->second, true);
}
}} // apache::thrift
namespace cpp2 {

void ListUnion::__clear() {
  // clear all fields
  if (type_ == Type::__EMPTY__) { return; }
  switch(type_) {
    case Type::intListValue:
    {
      destruct(value_.intListValue);
      break;
    }
    case Type::stringListValue:
    {
      destruct(value_.stringListValue);
      break;
    }
    default:
    {
      assert(false);
      break;
    }
  }
  type_ = Type::__EMPTY__;
}

bool ListUnion::operator==(const ListUnion& rhs) const {
  if (type_ != rhs.type_) { return false; }
  switch(type_) {
    case Type::intListValue:
    {
      return value_.intListValue == rhs.value_.intListValue;
    }
    case Type::stringListValue:
    {
      return value_.stringListValue == rhs.value_.stringListValue;
    }
    default:
    {
      return true;
    }
  }
}

bool ListUnion::operator<(const ListUnion& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (lhs.type_ != rhs.type_) {
    return lhs.type_ < rhs.type_;
  }
  switch (lhs.type_) {
    case Type::intListValue:
      return lhs.value_.intListValue < rhs.value_.intListValue;
    case Type::stringListValue:
      return lhs.value_.stringListValue < rhs.value_.stringListValue;
    default:
      return false;
  }
}

void swap(ListUnion& a, ListUnion& b) {
  ListUnion temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template void ListUnion::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t ListUnion::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t ListUnion::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t ListUnion::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void ListUnion::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t ListUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t ListUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t ListUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2
namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::DataUnion>::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "binaryData") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_STRING;
  }
  else if (_fname == "stringData") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_STRING;
  }
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace apache { namespace thrift {

constexpr std::size_t const TEnumTraits<::cpp2::DataUnion::Type>::size;
folly::Range<::cpp2::DataUnion::Type const*> const TEnumTraits<::cpp2::DataUnion::Type>::values = folly::range(TEnumDataStorage<::cpp2::DataUnion::Type>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::cpp2::DataUnion::Type>::names = folly::range(TEnumDataStorage<::cpp2::DataUnion::Type>::names);

char const* TEnumTraits<::cpp2::DataUnion::Type>::findName(type value) {
  using factory = detail::TEnumMapFactory<::cpp2::DataUnion::Type>;
  static folly::Indestructible<factory::ValuesToNamesMapType> const map{
      factory::makeValuesToNamesMap()};
  auto found = map->find(value);
  return found == map->end() ? nullptr : found->second;
}

bool TEnumTraits<::cpp2::DataUnion::Type>::findValue(char const* name, type* out) {
  using factory = detail::TEnumMapFactory<::cpp2::DataUnion::Type>;
  static folly::Indestructible<factory::NamesToValuesMapType> const map{
      factory::makeNamesToValuesMap()};
  auto found = map->find(name);
  return found == map->end() ? false : (*out = found->second, true);
}
}} // apache::thrift
namespace cpp2 {

void DataUnion::__clear() {
  // clear all fields
  if (type_ == Type::__EMPTY__) { return; }
  switch(type_) {
    case Type::binaryData:
    {
      destruct(value_.binaryData);
      break;
    }
    case Type::stringData:
    {
      destruct(value_.stringData);
      break;
    }
    default:
    {
      assert(false);
      break;
    }
  }
  type_ = Type::__EMPTY__;
}

bool DataUnion::operator==(const DataUnion& rhs) const {
  if (type_ != rhs.type_) { return false; }
  switch(type_) {
    case Type::binaryData:
    {
      return value_.binaryData == rhs.value_.binaryData;
    }
    case Type::stringData:
    {
      return value_.stringData == rhs.value_.stringData;
    }
    default:
    {
      return true;
    }
  }
}

bool DataUnion::operator<(const DataUnion& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (lhs.type_ != rhs.type_) {
    return lhs.type_ < rhs.type_;
  }
  switch (lhs.type_) {
    case Type::binaryData:
      return lhs.value_.binaryData < rhs.value_.binaryData;
    case Type::stringData:
      return lhs.value_.stringData < rhs.value_.stringData;
    default:
      return false;
  }
}

void swap(DataUnion& a, DataUnion& b) {
  DataUnion temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template void DataUnion::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t DataUnion::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t DataUnion::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t DataUnion::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void DataUnion::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t DataUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t DataUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t DataUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2
namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::Val>::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "strVal") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_STRING;
  }
  else if (_fname == "intVal") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_I32;
  }
  else if (_fname == "typedefValue") {
    fid = 9;
    _ftype = apache::thrift::protocol::T_MAP;
  }
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
Val::Val(apache::thrift::FragileConstructor, ::std::string strVal__arg, int32_t intVal__arg,  ::cpp2::containerTypedef typedefValue__arg) :
    strVal(std::move(strVal__arg)),
    intVal(std::move(intVal__arg)),
    typedefValue(std::move(typedefValue__arg)) {
  __isset.strVal = true;
  __isset.intVal = true;
  __isset.typedefValue = true;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END
void Val::__clear() {
  // clear all fields
  strVal = apache::thrift::StringTraits< std::string>::fromStringLiteral("");
  intVal = 0;
  typedefValue.clear();
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset = {};
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

bool Val::operator==(const Val& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.strVal == rhs.strVal)) {
    return false;
  }
  if (!(lhs.intVal == rhs.intVal)) {
    return false;
  }
  if (!(lhs.typedefValue == rhs.typedefValue)) {
    return false;
  }
  return true;
}

bool Val::operator<(const Val& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.strVal == rhs.strVal)) {
    return lhs.strVal < rhs.strVal;
  }
  if (!(lhs.intVal == rhs.intVal)) {
    return lhs.intVal < rhs.intVal;
  }
  if (!(lhs.typedefValue == rhs.typedefValue)) {
    return lhs.typedefValue < rhs.typedefValue;
  }
  return false;
}

const  ::cpp2::containerTypedef& Val::get_typedefValue() const& {
  return typedefValue;
}

 ::cpp2::containerTypedef Val::get_typedefValue() && {
  return std::move(typedefValue);
}


void swap(Val& a, Val& b) {
  using ::std::swap;
  swap(a.strVal, b.strVal);
  swap(a.intVal, b.intVal);
  swap(a.typedefValue, b.typedefValue);
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  swap(a.__isset, b.__isset);
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

template void Val::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t Val::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t Val::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Val::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void Val::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t Val::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t Val::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t Val::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2
namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::ValUnion>::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "v1") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_STRUCT;
  }
  else if (_fname == "v2") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_STRUCT;
  }
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace apache { namespace thrift {

constexpr std::size_t const TEnumTraits<::cpp2::ValUnion::Type>::size;
folly::Range<::cpp2::ValUnion::Type const*> const TEnumTraits<::cpp2::ValUnion::Type>::values = folly::range(TEnumDataStorage<::cpp2::ValUnion::Type>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::cpp2::ValUnion::Type>::names = folly::range(TEnumDataStorage<::cpp2::ValUnion::Type>::names);

char const* TEnumTraits<::cpp2::ValUnion::Type>::findName(type value) {
  using factory = detail::TEnumMapFactory<::cpp2::ValUnion::Type>;
  static folly::Indestructible<factory::ValuesToNamesMapType> const map{
      factory::makeValuesToNamesMap()};
  auto found = map->find(value);
  return found == map->end() ? nullptr : found->second;
}

bool TEnumTraits<::cpp2::ValUnion::Type>::findValue(char const* name, type* out) {
  using factory = detail::TEnumMapFactory<::cpp2::ValUnion::Type>;
  static folly::Indestructible<factory::NamesToValuesMapType> const map{
      factory::makeNamesToValuesMap()};
  auto found = map->find(name);
  return found == map->end() ? false : (*out = found->second, true);
}
}} // apache::thrift
namespace cpp2 {

void ValUnion::__clear() {
  // clear all fields
  if (type_ == Type::__EMPTY__) { return; }
  switch(type_) {
    case Type::v1:
    {
      destruct(value_.v1);
      break;
    }
    case Type::v2:
    {
      destruct(value_.v2);
      break;
    }
    default:
    {
      assert(false);
      break;
    }
  }
  type_ = Type::__EMPTY__;
}

bool ValUnion::operator==(const ValUnion& rhs) const {
  if (type_ != rhs.type_) { return false; }
  switch(type_) {
    case Type::v1:
    {
      return value_.v1 == rhs.value_.v1;
    }
    case Type::v2:
    {
      return value_.v2 == rhs.value_.v2;
    }
    default:
    {
      return true;
    }
  }
}

bool ValUnion::operator<(const ValUnion& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (lhs.type_ != rhs.type_) {
    return lhs.type_ < rhs.type_;
  }
  switch (lhs.type_) {
    case Type::v1:
      return lhs.value_.v1 < rhs.value_.v1;
    case Type::v2:
      return lhs.value_.v2 < rhs.value_.v2;
    default:
      return false;
  }
}

void swap(ValUnion& a, ValUnion& b) {
  ValUnion temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template void ValUnion::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t ValUnion::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t ValUnion::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t ValUnion::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void ValUnion::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t ValUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t ValUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t ValUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

//  enforce that if this thrift file is generated with extern template instances
//  for simple-json protocol then all its dependencies are too
static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        ValUnion,
        ::apache::thrift::type_class::structure,
         ::cpp2::Val>,
    "inconsistent use of json option");
//  enforce that if this thrift file is generated with extern template instances
//  for simple-json protocol then all its dependencies are too
static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        ValUnion,
        ::apache::thrift::type_class::structure,
         ::cpp2::Val>,
    "inconsistent use of json option");

//  if this struct is generated with extern template instances for nimble
//  protocol, enforce that all its dependencies are too
static_assert(
    ::apache::thrift::detail::st::gen_check_nimble<
        ValUnion,
        ::apache::thrift::type_class::structure,
         ::cpp2::Val>,
    "inconsistent use of nimble option");
//  if this struct is generated with extern template instances for nimble
//  protocol, enforce that all its dependencies are too
static_assert(
    ::apache::thrift::detail::st::gen_check_nimble<
        ValUnion,
        ::apache::thrift::type_class::structure,
         ::cpp2::Val>,
    "inconsistent use of nimble option");

} // cpp2
namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::VirtualComplexUnion>::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "thingOne") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_STRING;
  }
  else if (_fname == "thingTwo") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_STRING;
  }
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace apache { namespace thrift {

constexpr std::size_t const TEnumTraits<::cpp2::VirtualComplexUnion::Type>::size;
folly::Range<::cpp2::VirtualComplexUnion::Type const*> const TEnumTraits<::cpp2::VirtualComplexUnion::Type>::values = folly::range(TEnumDataStorage<::cpp2::VirtualComplexUnion::Type>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::cpp2::VirtualComplexUnion::Type>::names = folly::range(TEnumDataStorage<::cpp2::VirtualComplexUnion::Type>::names);

char const* TEnumTraits<::cpp2::VirtualComplexUnion::Type>::findName(type value) {
  using factory = detail::TEnumMapFactory<::cpp2::VirtualComplexUnion::Type>;
  static folly::Indestructible<factory::ValuesToNamesMapType> const map{
      factory::makeValuesToNamesMap()};
  auto found = map->find(value);
  return found == map->end() ? nullptr : found->second;
}

bool TEnumTraits<::cpp2::VirtualComplexUnion::Type>::findValue(char const* name, type* out) {
  using factory = detail::TEnumMapFactory<::cpp2::VirtualComplexUnion::Type>;
  static folly::Indestructible<factory::NamesToValuesMapType> const map{
      factory::makeNamesToValuesMap()};
  auto found = map->find(name);
  return found == map->end() ? false : (*out = found->second, true);
}
}} // apache::thrift
namespace cpp2 {

void VirtualComplexUnion::__clear() {
  // clear all fields
  if (type_ == Type::__EMPTY__) { return; }
  switch(type_) {
    case Type::thingOne:
    {
      destruct(value_.thingOne);
      break;
    }
    case Type::thingTwo:
    {
      destruct(value_.thingTwo);
      break;
    }
    default:
    {
      assert(false);
      break;
    }
  }
  type_ = Type::__EMPTY__;
}

bool VirtualComplexUnion::operator==(const VirtualComplexUnion& rhs) const {
  if (type_ != rhs.type_) { return false; }
  switch(type_) {
    case Type::thingOne:
    {
      return value_.thingOne == rhs.value_.thingOne;
    }
    case Type::thingTwo:
    {
      return value_.thingTwo == rhs.value_.thingTwo;
    }
    default:
    {
      return true;
    }
  }
}

bool VirtualComplexUnion::operator<(const VirtualComplexUnion& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (lhs.type_ != rhs.type_) {
    return lhs.type_ < rhs.type_;
  }
  switch (lhs.type_) {
    case Type::thingOne:
      return lhs.value_.thingOne < rhs.value_.thingOne;
    case Type::thingTwo:
      return lhs.value_.thingTwo < rhs.value_.thingTwo;
    default:
      return false;
  }
}

void swap(VirtualComplexUnion& a, VirtualComplexUnion& b) {
  VirtualComplexUnion temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template void VirtualComplexUnion::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t VirtualComplexUnion::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t VirtualComplexUnion::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t VirtualComplexUnion::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void VirtualComplexUnion::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t VirtualComplexUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t VirtualComplexUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t VirtualComplexUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2
namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::NonCopyableStruct>::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "num") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_I64;
  }
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
NonCopyableStruct::NonCopyableStruct(apache::thrift::FragileConstructor, int64_t num__arg) :
    num(std::move(num__arg)) {
  __isset.num = true;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END
void NonCopyableStruct::__clear() {
  // clear all fields
  num = 0;
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset = {};
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

bool NonCopyableStruct::operator==(const NonCopyableStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.num == rhs.num)) {
    return false;
  }
  return true;
}

bool NonCopyableStruct::operator<(const NonCopyableStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.num == rhs.num)) {
    return lhs.num < rhs.num;
  }
  return false;
}


void swap(NonCopyableStruct& a, NonCopyableStruct& b) {
  using ::std::swap;
  swap(a.num, b.num);
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  swap(a.__isset, b.__isset);
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

template void NonCopyableStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t NonCopyableStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t NonCopyableStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t NonCopyableStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void NonCopyableStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t NonCopyableStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t NonCopyableStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t NonCopyableStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2
namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::NonCopyableUnion>::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "s") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_STRUCT;
  }
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace apache { namespace thrift {

constexpr std::size_t const TEnumTraits<::cpp2::NonCopyableUnion::Type>::size;
folly::Range<::cpp2::NonCopyableUnion::Type const*> const TEnumTraits<::cpp2::NonCopyableUnion::Type>::values = folly::range(TEnumDataStorage<::cpp2::NonCopyableUnion::Type>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::cpp2::NonCopyableUnion::Type>::names = folly::range(TEnumDataStorage<::cpp2::NonCopyableUnion::Type>::names);

char const* TEnumTraits<::cpp2::NonCopyableUnion::Type>::findName(type value) {
  using factory = detail::TEnumMapFactory<::cpp2::NonCopyableUnion::Type>;
  static folly::Indestructible<factory::ValuesToNamesMapType> const map{
      factory::makeValuesToNamesMap()};
  auto found = map->find(value);
  return found == map->end() ? nullptr : found->second;
}

bool TEnumTraits<::cpp2::NonCopyableUnion::Type>::findValue(char const* name, type* out) {
  using factory = detail::TEnumMapFactory<::cpp2::NonCopyableUnion::Type>;
  static folly::Indestructible<factory::NamesToValuesMapType> const map{
      factory::makeNamesToValuesMap()};
  auto found = map->find(name);
  return found == map->end() ? false : (*out = found->second, true);
}
}} // apache::thrift
namespace cpp2 {

void NonCopyableUnion::__clear() {
  // clear all fields
  if (type_ == Type::__EMPTY__) { return; }
  switch(type_) {
    case Type::s:
    {
      destruct(value_.s);
      break;
    }
    default:
    {
      assert(false);
      break;
    }
  }
  type_ = Type::__EMPTY__;
}

bool NonCopyableUnion::operator==(const NonCopyableUnion& rhs) const {
  if (type_ != rhs.type_) { return false; }
  switch(type_) {
    case Type::s:
    {
      return value_.s == rhs.value_.s;
    }
    default:
    {
      return true;
    }
  }
}

bool NonCopyableUnion::operator<(const NonCopyableUnion& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (lhs.type_ != rhs.type_) {
    return lhs.type_ < rhs.type_;
  }
  switch (lhs.type_) {
    case Type::s:
      return lhs.value_.s < rhs.value_.s;
    default:
      return false;
  }
}

void swap(NonCopyableUnion& a, NonCopyableUnion& b) {
  NonCopyableUnion temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template void NonCopyableUnion::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t NonCopyableUnion::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t NonCopyableUnion::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t NonCopyableUnion::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void NonCopyableUnion::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t NonCopyableUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t NonCopyableUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t NonCopyableUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

//  enforce that if this thrift file is generated with extern template instances
//  for simple-json protocol then all its dependencies are too
static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        NonCopyableUnion,
        ::apache::thrift::type_class::structure,
         ::cpp2::NonCopyableStruct>,
    "inconsistent use of json option");

//  if this struct is generated with extern template instances for nimble
//  protocol, enforce that all its dependencies are too
static_assert(
    ::apache::thrift::detail::st::gen_check_nimble<
        NonCopyableUnion,
        ::apache::thrift::type_class::structure,
         ::cpp2::NonCopyableStruct>,
    "inconsistent use of nimble option");

} // cpp2
