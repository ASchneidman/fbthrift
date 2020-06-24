/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_types_h.h>



namespace apache {
namespace thrift {
namespace tag {
struct MyIntField;
struct MyStringField;
} // namespace tag
namespace detail {
#ifndef APACHE_THRIFT_ACCESSOR_MyIntField
#define APACHE_THRIFT_ACCESSOR_MyIntField
APACHE_THRIFT_DEFINE_ACCESSOR(MyIntField);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_MyStringField
#define APACHE_THRIFT_ACCESSOR_MyStringField
APACHE_THRIFT_DEFINE_ACCESSOR(MyStringField);
#endif
} // namespace detail
} // namespace thrift
} // namespace apache

// BEGIN declare_enums
namespace cpp2 {

enum class MyEnum {
  MyValue1 = 0,
  MyValue2 = 1,
};




} // cpp2
namespace std {


template<> struct hash<typename ::cpp2::MyEnum> : public apache::thrift::detail::enum_hash<typename ::cpp2::MyEnum> {};
template<> struct equal_to<typename ::cpp2::MyEnum> : public apache::thrift::detail::enum_equal_to<typename ::cpp2::MyEnum> {};


} // std

namespace apache { namespace thrift {


template <> struct TEnumDataStorage<::cpp2::MyEnum>;

template <> struct TEnumTraits<::cpp2::MyEnum> {
  using type = ::cpp2::MyEnum;

  static constexpr std::size_t const size = 2;
  static folly::Range<type const*> const values;
  static folly::Range<folly::StringPiece const*> const names;

  static char const* findName(type value);
  static bool findValue(char const* name, type* out);

  static constexpr type min() { return type::MyValue1; }
  static constexpr type max() { return type::MyValue2; }
};


}} // apache::thrift

namespace cpp2 {

using _MyEnum_EnumMapFactory = apache::thrift::detail::TEnumMapFactory<MyEnum>;
[[deprecated("use apache::thrift::util::enumNameSafe, apache::thrift::util::enumName, or apache::thrift::TEnumTraits")]]
extern const _MyEnum_EnumMapFactory::ValuesToNamesMapType _MyEnum_VALUES_TO_NAMES;
[[deprecated("use apache::thrift::TEnumTraits")]]
extern const _MyEnum_EnumMapFactory::NamesToValuesMapType _MyEnum_NAMES_TO_VALUES;

} // cpp2

// END declare_enums
// BEGIN struct_indirection

// END struct_indirection
// BEGIN forward_declare
namespace cpp2 {
class MyStruct;
} // cpp2
// END forward_declare
// BEGIN typedefs

// END typedefs
// BEGIN hash_and_equal_to
// END hash_and_equal_to
namespace cpp2 {
class MyStruct final : private apache::thrift::detail::st::ComparisonOperators<MyStruct> {
 public:

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  MyStruct() :
      MyIntField(0) {}
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  MyStruct(apache::thrift::FragileConstructor, int64_t MyIntField__arg, ::std::string MyStringField__arg);

  MyStruct(MyStruct&&) = default;

  MyStruct(const MyStruct&) = default;

  MyStruct& operator=(MyStruct&&) = default;

  MyStruct& operator=(const MyStruct&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  void __clear();
 public:
  int64_t MyIntField;
 public:
  ::std::string MyStringField;

 public:
  [[deprecated("__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]]
  struct __isset {
    bool MyIntField;
    bool MyStringField;
  } __isset = {};
  bool operator==(const MyStruct& rhs) const;
  bool operator<(const MyStruct& rhs) const;

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = int64_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> MyIntField_ref() const& {
    return {this->MyIntField, __isset.MyIntField};
  }

  template <typename..., typename T = int64_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> MyIntField_ref() const&& {
    return {std::move(this->MyIntField), __isset.MyIntField};
  }

  template <typename..., typename T = int64_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> MyIntField_ref() & {
    return {this->MyIntField, __isset.MyIntField};
  }

  template <typename..., typename T = int64_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> MyIntField_ref() && {
    return {std::move(this->MyIntField), __isset.MyIntField};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> MyStringField_ref() const& {
    return {this->MyStringField, __isset.MyStringField};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> MyStringField_ref() const&& {
    return {std::move(this->MyStringField), __isset.MyStringField};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> MyStringField_ref() & {
    return {this->MyStringField, __isset.MyStringField};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> MyStringField_ref() && {
    return {std::move(this->MyStringField), __isset.MyStringField};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END

  int64_t get_MyIntField() const {
    return MyIntField;
  }

  int64_t& set_MyIntField(int64_t MyIntField_) {
    MyIntField = MyIntField_;
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.MyIntField = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return MyIntField;
  }

  const ::std::string& get_MyStringField() const& {
    return MyStringField;
  }

  ::std::string get_MyStringField() && {
    return std::move(MyStringField);
  }

  template <typename T_MyStruct_MyStringField_struct_setter = ::std::string>
  ::std::string& set_MyStringField(T_MyStruct_MyStringField_struct_setter&& MyStringField_) {
    MyStringField = std::forward<T_MyStruct_MyStringField_struct_setter>(MyStringField_);
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.MyStringField = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return MyStringField;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< MyStruct >;
};

void swap(MyStruct& a, MyStruct& b);

template <class Protocol_>
uint32_t MyStruct::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
