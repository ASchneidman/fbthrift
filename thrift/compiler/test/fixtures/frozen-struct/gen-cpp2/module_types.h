/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_types_h.h>

#include <thrift/lib/cpp2/type/Tag.h>

#include "thrift/compiler/test/fixtures/frozen-struct/gen-cpp2/include1_types.h"
#include "thrift/compiler/test/fixtures/frozen-struct/gen-cpp2/include2_types.h"

namespace apache {
namespace thrift {
namespace tag {
struct i32Field;
struct strField;
struct listField;
struct mapField;
struct inclAField;
struct inclBField;
struct i32Field;
struct inclEnumB;
} // namespace tag
namespace detail {
#ifndef APACHE_THRIFT_ACCESSOR_i32Field
#define APACHE_THRIFT_ACCESSOR_i32Field
APACHE_THRIFT_DEFINE_ACCESSOR(i32Field);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_strField
#define APACHE_THRIFT_ACCESSOR_strField
APACHE_THRIFT_DEFINE_ACCESSOR(strField);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_listField
#define APACHE_THRIFT_ACCESSOR_listField
APACHE_THRIFT_DEFINE_ACCESSOR(listField);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_mapField
#define APACHE_THRIFT_ACCESSOR_mapField
APACHE_THRIFT_DEFINE_ACCESSOR(mapField);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_inclAField
#define APACHE_THRIFT_ACCESSOR_inclAField
APACHE_THRIFT_DEFINE_ACCESSOR(inclAField);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_inclBField
#define APACHE_THRIFT_ACCESSOR_inclBField
APACHE_THRIFT_DEFINE_ACCESSOR(inclBField);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_i32Field
#define APACHE_THRIFT_ACCESSOR_i32Field
APACHE_THRIFT_DEFINE_ACCESSOR(i32Field);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_inclEnumB
#define APACHE_THRIFT_ACCESSOR_inclEnumB
APACHE_THRIFT_DEFINE_ACCESSOR(inclEnumB);
#endif
} // namespace detail
} // namespace thrift
} // namespace apache

// BEGIN declare_enums
namespace some { namespace ns {

enum class EnumB {
  EMPTY = 1,
};




}} // some::ns

namespace std {
template<> struct hash<::some::ns::EnumB> :
  ::apache::thrift::detail::enum_hash<::some::ns::EnumB> {};
} // std

namespace apache { namespace thrift {


template <> struct TEnumDataStorage<::some::ns::EnumB>;

template <> struct TEnumTraits<::some::ns::EnumB> {
  using type = ::some::ns::EnumB;

  static constexpr std::size_t const size = 1;
  static folly::Range<type const*> const values;
  static folly::Range<folly::StringPiece const*> const names;

  static bool findName(type value, folly::StringPiece* out) noexcept;
  static bool findValue(folly::StringPiece name, type* out) noexcept;

#if FOLLY_HAS_STRING_VIEW
  static bool findName(type value, std::string_view* out) noexcept {
    folly::StringPiece outp;
    return findName(value, &outp) && ((*out = outp), true);
  }
#endif
  static char const* findName(type value) noexcept {
    folly::StringPiece ret;
    (void)findName(value, &ret);
    return ret.data();
  }
  static constexpr type min() { return type::EMPTY; }
  static constexpr type max() { return type::EMPTY; }
};


}} // apache::thrift

namespace some { namespace ns {

using _EnumB_EnumMapFactory = apache::thrift::detail::TEnumMapFactory<EnumB>;
#ifndef ANDROID
[[deprecated("use apache::thrift::util::enumNameSafe, apache::thrift::util::enumName, or apache::thrift::TEnumTraits")]]
extern const _EnumB_EnumMapFactory::ValuesToNamesMapType _EnumB_VALUES_TO_NAMES;
[[deprecated("use apache::thrift::TEnumTraits")]]
extern const _EnumB_EnumMapFactory::NamesToValuesMapType _EnumB_NAMES_TO_VALUES;
#endif
}} // some::ns

// END declare_enums
// BEGIN forward_declare
namespace some { namespace ns {
class ModuleA;
class ModuleB;
}} // some::ns
// END forward_declare
// BEGIN typedefs

// END typedefs
// BEGIN hash_and_equal_to
// END hash_and_equal_to
namespace some { namespace ns {
using ::apache::thrift::detail::operator!=;
using ::apache::thrift::detail::operator>;
using ::apache::thrift::detail::operator<=;
using ::apache::thrift::detail::operator>=;
}} // some::ns
namespace some { namespace ns {
class ModuleA final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

  void __fbthrift_clear();
  bool __fbthrift_is_empty() const;

 public:
  using __fbthrift_cpp2_type = ModuleA;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  ModuleA();

  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  ModuleA(apache::thrift::FragileConstructor, ::std::int32_t i32Field__arg, ::std::string strField__arg, ::std::vector<::std::int16_t> listField__arg, ::std::map<::std::string, ::std::int32_t> mapField__arg, ::some::ns::IncludedA inclAField__arg, ::some::ns::IncludedB inclBField__arg);

  ModuleA(ModuleA&&) noexcept;

  ModuleA(const ModuleA& src);


  ModuleA& operator=(ModuleA&&) noexcept;
  ModuleA& operator=(const ModuleA& src);

  ~ModuleA();

 private:
  ::std::int32_t __fbthrift_field_i32Field;
 private:
  ::std::string __fbthrift_field_strField;
 private:
  ::std::vector<::std::int16_t> __fbthrift_field_listField;
 private:
  ::std::map<::std::string, ::std::int32_t> __fbthrift_field_mapField;
 private:
  ::some::ns::IncludedA __fbthrift_field_inclAField;
 private:
  ::some::ns::IncludedB __fbthrift_field_inclBField;
 private:
  apache::thrift::detail::isset_bitset<6, apache::thrift::detail::IssetBitsetOption::Unpacked> __isset;

 public:

  bool operator==(const ModuleA&) const;
  bool operator<(const ModuleA&) const;

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> i32Field_ref() const& {
    return {this->__fbthrift_field_i32Field, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> i32Field_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_i32Field), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> i32Field_ref() & {
    return {this->__fbthrift_field_i32Field, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> i32Field_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_i32Field), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> i32Field() const& {
    return {this->__fbthrift_field_i32Field, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> i32Field() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_i32Field), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> i32Field() & {
    return {this->__fbthrift_field_i32Field, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> i32Field() && {
    return {static_cast<T&&>(this->__fbthrift_field_i32Field), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> strField_ref() const& {
    return {this->__fbthrift_field_strField, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> strField_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_strField), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> strField_ref() & {
    return {this->__fbthrift_field_strField, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> strField_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_strField), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> strField() const& {
    return {this->__fbthrift_field_strField, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> strField() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_strField), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> strField() & {
    return {this->__fbthrift_field_strField, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> strField() && {
    return {static_cast<T&&>(this->__fbthrift_field_strField), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::vector<::std::int16_t>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> listField_ref() const& {
    return {this->__fbthrift_field_listField, __isset.at(2), __isset.bit(2)};
  }

  template <typename..., typename T = ::std::vector<::std::int16_t>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> listField_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_listField), __isset.at(2), __isset.bit(2)};
  }

  template <typename..., typename T = ::std::vector<::std::int16_t>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> listField_ref() & {
    return {this->__fbthrift_field_listField, __isset.at(2), __isset.bit(2)};
  }

  template <typename..., typename T = ::std::vector<::std::int16_t>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> listField_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_listField), __isset.at(2), __isset.bit(2)};
  }

  template <typename..., typename T = ::std::vector<::std::int16_t>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> listField() const& {
    return {this->__fbthrift_field_listField, __isset.at(2), __isset.bit(2)};
  }

  template <typename..., typename T = ::std::vector<::std::int16_t>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> listField() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_listField), __isset.at(2), __isset.bit(2)};
  }

  template <typename..., typename T = ::std::vector<::std::int16_t>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> listField() & {
    return {this->__fbthrift_field_listField, __isset.at(2), __isset.bit(2)};
  }

  template <typename..., typename T = ::std::vector<::std::int16_t>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> listField() && {
    return {static_cast<T&&>(this->__fbthrift_field_listField), __isset.at(2), __isset.bit(2)};
  }

  template <typename..., typename T = ::std::map<::std::string, ::std::int32_t>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> mapField_ref() const& {
    return {this->__fbthrift_field_mapField, __isset.at(3), __isset.bit(3)};
  }

  template <typename..., typename T = ::std::map<::std::string, ::std::int32_t>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> mapField_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_mapField), __isset.at(3), __isset.bit(3)};
  }

  template <typename..., typename T = ::std::map<::std::string, ::std::int32_t>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> mapField_ref() & {
    return {this->__fbthrift_field_mapField, __isset.at(3), __isset.bit(3)};
  }

  template <typename..., typename T = ::std::map<::std::string, ::std::int32_t>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> mapField_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_mapField), __isset.at(3), __isset.bit(3)};
  }

  template <typename..., typename T = ::std::map<::std::string, ::std::int32_t>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> mapField() const& {
    return {this->__fbthrift_field_mapField, __isset.at(3), __isset.bit(3)};
  }

  template <typename..., typename T = ::std::map<::std::string, ::std::int32_t>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> mapField() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_mapField), __isset.at(3), __isset.bit(3)};
  }

  template <typename..., typename T = ::std::map<::std::string, ::std::int32_t>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> mapField() & {
    return {this->__fbthrift_field_mapField, __isset.at(3), __isset.bit(3)};
  }

  template <typename..., typename T = ::std::map<::std::string, ::std::int32_t>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> mapField() && {
    return {static_cast<T&&>(this->__fbthrift_field_mapField), __isset.at(3), __isset.bit(3)};
  }

  template <typename..., typename T = ::some::ns::IncludedA>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> inclAField_ref() const& {
    return {this->__fbthrift_field_inclAField, __isset.at(4), __isset.bit(4)};
  }

  template <typename..., typename T = ::some::ns::IncludedA>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> inclAField_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_inclAField), __isset.at(4), __isset.bit(4)};
  }

  template <typename..., typename T = ::some::ns::IncludedA>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> inclAField_ref() & {
    return {this->__fbthrift_field_inclAField, __isset.at(4), __isset.bit(4)};
  }

  template <typename..., typename T = ::some::ns::IncludedA>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> inclAField_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_inclAField), __isset.at(4), __isset.bit(4)};
  }

  template <typename..., typename T = ::some::ns::IncludedA>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> inclAField() const& {
    return {this->__fbthrift_field_inclAField, __isset.at(4), __isset.bit(4)};
  }

  template <typename..., typename T = ::some::ns::IncludedA>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> inclAField() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_inclAField), __isset.at(4), __isset.bit(4)};
  }

  template <typename..., typename T = ::some::ns::IncludedA>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> inclAField() & {
    return {this->__fbthrift_field_inclAField, __isset.at(4), __isset.bit(4)};
  }

  template <typename..., typename T = ::some::ns::IncludedA>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> inclAField() && {
    return {static_cast<T&&>(this->__fbthrift_field_inclAField), __isset.at(4), __isset.bit(4)};
  }

  template <typename..., typename T = ::some::ns::IncludedB>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> inclBField_ref() const& {
    return {this->__fbthrift_field_inclBField, __isset.at(5), __isset.bit(5)};
  }

  template <typename..., typename T = ::some::ns::IncludedB>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> inclBField_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_inclBField), __isset.at(5), __isset.bit(5)};
  }

  template <typename..., typename T = ::some::ns::IncludedB>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> inclBField_ref() & {
    return {this->__fbthrift_field_inclBField, __isset.at(5), __isset.bit(5)};
  }

  template <typename..., typename T = ::some::ns::IncludedB>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> inclBField_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_inclBField), __isset.at(5), __isset.bit(5)};
  }

  template <typename..., typename T = ::some::ns::IncludedB>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> inclBField() const& {
    return {this->__fbthrift_field_inclBField, __isset.at(5), __isset.bit(5)};
  }

  template <typename..., typename T = ::some::ns::IncludedB>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> inclBField() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_inclBField), __isset.at(5), __isset.bit(5)};
  }

  template <typename..., typename T = ::some::ns::IncludedB>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> inclBField() & {
    return {this->__fbthrift_field_inclBField, __isset.at(5), __isset.bit(5)};
  }

  template <typename..., typename T = ::some::ns::IncludedB>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> inclBField() && {
    return {static_cast<T&&>(this->__fbthrift_field_inclBField), __isset.at(5), __isset.bit(5)};
  }

  ::std::int32_t get_i32Field() const {
    return __fbthrift_field_i32Field;
  }

  [[deprecated("Use `FOO.i32Field_ref() = BAR;` instead of `FOO.set_i32Field(BAR);`")]]
  ::std::int32_t& set_i32Field(::std::int32_t i32Field_) {
    i32Field_ref() = i32Field_;
    return __fbthrift_field_i32Field;
  }

  const ::std::string& get_strField() const& {
    return __fbthrift_field_strField;
  }

  ::std::string get_strField() && {
    return std::move(__fbthrift_field_strField);
  }

  template <typename T_ModuleA_strField_struct_setter = ::std::string>
  [[deprecated("Use `FOO.strField_ref() = BAR;` instead of `FOO.set_strField(BAR);`")]]
  ::std::string& set_strField(T_ModuleA_strField_struct_setter&& strField_) {
    strField_ref() = std::forward<T_ModuleA_strField_struct_setter>(strField_);
    return __fbthrift_field_strField;
  }
  const ::std::vector<::std::int16_t>& get_listField() const&;
  ::std::vector<::std::int16_t> get_listField() &&;

  template <typename T_ModuleA_listField_struct_setter = ::std::vector<::std::int16_t>>
  [[deprecated("Use `FOO.listField_ref() = BAR;` instead of `FOO.set_listField(BAR);`")]]
  ::std::vector<::std::int16_t>& set_listField(T_ModuleA_listField_struct_setter&& listField_) {
    listField_ref() = std::forward<T_ModuleA_listField_struct_setter>(listField_);
    return __fbthrift_field_listField;
  }
  const ::std::map<::std::string, ::std::int32_t>& get_mapField() const&;
  ::std::map<::std::string, ::std::int32_t> get_mapField() &&;

  template <typename T_ModuleA_mapField_struct_setter = ::std::map<::std::string, ::std::int32_t>>
  [[deprecated("Use `FOO.mapField_ref() = BAR;` instead of `FOO.set_mapField(BAR);`")]]
  ::std::map<::std::string, ::std::int32_t>& set_mapField(T_ModuleA_mapField_struct_setter&& mapField_) {
    mapField_ref() = std::forward<T_ModuleA_mapField_struct_setter>(mapField_);
    return __fbthrift_field_mapField;
  }
  const ::some::ns::IncludedA& get_inclAField() const&;
  ::some::ns::IncludedA get_inclAField() &&;

  template <typename T_ModuleA_inclAField_struct_setter = ::some::ns::IncludedA>
  [[deprecated("Use `FOO.inclAField_ref() = BAR;` instead of `FOO.set_inclAField(BAR);`")]]
  ::some::ns::IncludedA& set_inclAField(T_ModuleA_inclAField_struct_setter&& inclAField_) {
    inclAField_ref() = std::forward<T_ModuleA_inclAField_struct_setter>(inclAField_);
    return __fbthrift_field_inclAField;
  }
  const ::some::ns::IncludedB& get_inclBField() const&;
  ::some::ns::IncludedB get_inclBField() &&;

  template <typename T_ModuleA_inclBField_struct_setter = ::some::ns::IncludedB>
  [[deprecated("Use `FOO.inclBField_ref() = BAR;` instead of `FOO.set_inclBField(BAR);`")]]
  ::some::ns::IncludedB& set_inclBField(T_ModuleA_inclBField_struct_setter&& inclBField_) {
    inclBField_ref() = std::forward<T_ModuleA_inclBField_struct_setter>(inclBField_);
    return __fbthrift_field_inclBField;
  }

  template <class Protocol_>
  unsigned long read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<ModuleA>;
  friend void swap(ModuleA& a, ModuleA& b);
};

template <class Protocol_>
unsigned long ModuleA::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

}} // some::ns
namespace some { namespace ns {
class ModuleB final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

  void __fbthrift_clear();
  bool __fbthrift_is_empty() const;

 public:
  using __fbthrift_cpp2_type = ModuleB;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  ModuleB() :
      __fbthrift_field_i32Field(),
      __fbthrift_field_inclEnumB() {
  }
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  ModuleB(apache::thrift::FragileConstructor, ::std::int32_t i32Field__arg, ::some::ns::EnumB inclEnumB__arg);

  ModuleB(ModuleB&&) = default;

  ModuleB(const ModuleB&) = default;


  ModuleB& operator=(ModuleB&&) = default;

  ModuleB& operator=(const ModuleB&) = default;
 private:
  ::std::int32_t __fbthrift_field_i32Field;
 private:
  ::some::ns::EnumB __fbthrift_field_inclEnumB;
 private:
  apache::thrift::detail::isset_bitset<2, apache::thrift::detail::IssetBitsetOption::Unpacked> __isset;

 public:

  bool operator==(const ModuleB&) const;
  bool operator<(const ModuleB&) const;

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> i32Field_ref() const& {
    return {this->__fbthrift_field_i32Field, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> i32Field_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_i32Field), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> i32Field_ref() & {
    return {this->__fbthrift_field_i32Field, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> i32Field_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_i32Field), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> i32Field() const& {
    return {this->__fbthrift_field_i32Field, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> i32Field() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_i32Field), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> i32Field() & {
    return {this->__fbthrift_field_i32Field, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> i32Field() && {
    return {static_cast<T&&>(this->__fbthrift_field_i32Field), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::some::ns::EnumB>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> inclEnumB_ref() const& {
    return {this->__fbthrift_field_inclEnumB, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::some::ns::EnumB>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> inclEnumB_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_inclEnumB), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::some::ns::EnumB>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> inclEnumB_ref() & {
    return {this->__fbthrift_field_inclEnumB, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::some::ns::EnumB>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> inclEnumB_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_inclEnumB), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::some::ns::EnumB>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> inclEnumB() const& {
    return {this->__fbthrift_field_inclEnumB, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::some::ns::EnumB>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> inclEnumB() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_inclEnumB), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::some::ns::EnumB>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> inclEnumB() & {
    return {this->__fbthrift_field_inclEnumB, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::some::ns::EnumB>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> inclEnumB() && {
    return {static_cast<T&&>(this->__fbthrift_field_inclEnumB), __isset.at(1), __isset.bit(1)};
  }

  ::std::int32_t get_i32Field() const {
    return __fbthrift_field_i32Field;
  }

  [[deprecated("Use `FOO.i32Field_ref() = BAR;` instead of `FOO.set_i32Field(BAR);`")]]
  ::std::int32_t& set_i32Field(::std::int32_t i32Field_) {
    i32Field_ref() = i32Field_;
    return __fbthrift_field_i32Field;
  }

  ::some::ns::EnumB get_inclEnumB() const {
    return __fbthrift_field_inclEnumB;
  }

  [[deprecated("Use `FOO.inclEnumB_ref() = BAR;` instead of `FOO.set_inclEnumB(BAR);`")]]
  ::some::ns::EnumB& set_inclEnumB(::some::ns::EnumB inclEnumB_) {
    inclEnumB_ref() = inclEnumB_;
    return __fbthrift_field_inclEnumB;
  }

  template <class Protocol_>
  unsigned long read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<ModuleB>;
  friend void swap(ModuleB& a, ModuleB& b);
};

template <class Protocol_>
unsigned long ModuleB::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

}} // some::ns
