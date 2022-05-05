/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include "thrift/compiler/test/fixtures/no-legacy-apis/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/no-legacy-apis/gen-cpp2/module_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "thrift/compiler/test/fixtures/no-legacy-apis/gen-cpp2/module_data.h"


namespace apache { namespace thrift {

constexpr std::size_t const TEnumTraits<::test::fixtures::basic::MyEnum>::size;
folly::Range<::test::fixtures::basic::MyEnum const*> const TEnumTraits<::test::fixtures::basic::MyEnum>::values = folly::range(TEnumDataStorage<::test::fixtures::basic::MyEnum>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::test::fixtures::basic::MyEnum>::names = folly::range(TEnumDataStorage<::test::fixtures::basic::MyEnum>::names);

bool TEnumTraits<::test::fixtures::basic::MyEnum>::findName(type value, folly::StringPiece* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_name(value, out);
}

bool TEnumTraits<::test::fixtures::basic::MyEnum>::findValue(folly::StringPiece name, type* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_value(name, out);
}

}} // apache::thrift

namespace test { namespace fixtures { namespace basic {
#ifndef ANDROID
FOLLY_PUSH_WARNING
FOLLY_GNU_DISABLE_WARNING("-Wdeprecated-declarations")
const _MyEnum_EnumMapFactory::ValuesToNamesMapType _MyEnum_VALUES_TO_NAMES = _MyEnum_EnumMapFactory::makeValuesToNamesMap();
const _MyEnum_EnumMapFactory::NamesToValuesMapType _MyEnum_NAMES_TO_VALUES = _MyEnum_EnumMapFactory::makeNamesToValuesMap();
FOLLY_POP_WARNING
#endif
}}} // test::fixtures::basic

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::test::fixtures::basic::MyStruct>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::test::fixtures::basic::MyStruct>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace test { namespace fixtures { namespace basic {

const char* MyStruct::__fbthrift_thrift_uri() {
  return "test.dev/fixtures/no-legacy-apis/MyStruct";
}

MyStruct::MyStruct(const MyStruct&) = default;
MyStruct& MyStruct::operator=(const MyStruct&) = default;
MyStruct::MyStruct(MyStruct&& other) noexcept  :
    __fbthrift_field_myIntField(std::move(other.__fbthrift_field_myIntField)),
    __fbthrift_field_myStringField(std::move(other.__fbthrift_field_myStringField)),
    __isset(other.__isset) {
}

MyStruct& MyStruct::operator=(FOLLY_MAYBE_UNUSED MyStruct&& other) noexcept {
    this->__fbthrift_field_myIntField = std::move(other.__fbthrift_field_myIntField);
    this->__fbthrift_field_myStringField = std::move(other.__fbthrift_field_myStringField);
    __isset = other.__isset;
    return *this;
}




void MyStruct::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_myIntField = ::std::int64_t();
  this->__fbthrift_field_myStringField = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  __isset = {};
}

bool MyStruct::__fbthrift_is_empty() const {
  return false;
}

bool MyStruct::operator==(const MyStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.myIntField_ref() == rhs.myIntField_ref())) {
    return false;
  }
  if (!(lhs.myStringField_ref() == rhs.myStringField_ref())) {
    return false;
  }
  return true;
}

bool MyStruct::operator<(const MyStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.myIntField_ref() == rhs.myIntField_ref())) {
    return lhs.myIntField_ref() < rhs.myIntField_ref();
  }
  if (!(lhs.myStringField_ref() == rhs.myStringField_ref())) {
    return lhs.myStringField_ref() < rhs.myStringField_ref();
  }
  return false;
}


void swap(MyStruct& a, MyStruct& b) {
  using ::std::swap;
  swap(a.myIntField_ref().value(), b.myIntField_ref().value());
  swap(a.myStringField_ref().value(), b.myStringField_ref().value());
  swap(a.__isset, b.__isset);
}

template void MyStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MyStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MyStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MyStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


}}} // test::fixtures::basic

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::test::fixtures::basic::MyUnion>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::test::fixtures::basic::MyUnion>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace apache { namespace thrift {

constexpr std::size_t const TEnumTraits<::test::fixtures::basic::MyUnion::Type>::size;
folly::Range<::test::fixtures::basic::MyUnion::Type const*> const TEnumTraits<::test::fixtures::basic::MyUnion::Type>::values = folly::range(TEnumDataStorage<::test::fixtures::basic::MyUnion::Type>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::test::fixtures::basic::MyUnion::Type>::names = folly::range(TEnumDataStorage<::test::fixtures::basic::MyUnion::Type>::names);

bool TEnumTraits<::test::fixtures::basic::MyUnion::Type>::findName(type value, folly::StringPiece* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_name(value, out);
}

bool TEnumTraits<::test::fixtures::basic::MyUnion::Type>::findValue(folly::StringPiece name, type* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_value(name, out);
}
}} // apache::thrift
namespace test { namespace fixtures { namespace basic {

const char* MyUnion::__fbthrift_thrift_uri() {
  return "test.dev/fixtures/no-legacy-apis/MyUnion";
}

void MyUnion::__fbthrift_clear() {
  // clear all fields
  if (type_ == Type::__EMPTY__) { return; }
  switch(type_) {
    case Type::myEnum:
      destruct(value_.myEnum);
      break;
    case Type::myDataItem:
      destruct(value_.myDataItem);
      break;
    default:
      assert(false);
      break;
  }
  type_ = Type::__EMPTY__;
}

bool MyUnion::__fbthrift_is_empty() const {
  return type_ == Type::__EMPTY__;
}

bool MyUnion::operator==(const MyUnion& rhs) const {
  if (type_ != rhs.type_) { return false; }
  switch(type_) {
    case Type::myEnum:
      return value_.myEnum == rhs.value_.myEnum;
    case Type::myDataItem:
      return value_.myDataItem == rhs.value_.myDataItem;
    default:
      return true;
  }
}

bool MyUnion::operator<(const MyUnion& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (lhs.type_ != rhs.type_) {
    return lhs.type_ < rhs.type_;
  }
  switch (lhs.type_) {
    case Type::myEnum:
      return lhs.value_.myEnum < rhs.value_.myEnum;
    case Type::myDataItem:
      return lhs.value_.myDataItem < rhs.value_.myDataItem;
    default:
      return false;
  }
}

void swap(MyUnion& a, MyUnion& b) {
  MyUnion temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template void MyUnion::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MyUnion::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MyUnion::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MyUnion::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MyUnion::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        MyUnion,
        ::apache::thrift::type_class::structure,
        ::test::fixtures::basic::MyStruct>,
    "inconsistent use of json option");

}}} // test::fixtures::basic

namespace test { namespace fixtures { namespace basic { namespace {
FOLLY_MAYBE_UNUSED FOLLY_ERASE void validateAdapters() {
}
}}}} // test::fixtures::basic
