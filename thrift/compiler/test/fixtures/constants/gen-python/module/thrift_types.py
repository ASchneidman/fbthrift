#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#

from __future__ import annotations

import enum

import folly.iobuf as _fbthrift_iobuf
import thrift.python.types as _fbthrift_python_types
import thrift.python.exceptions as _fbthrift_python_exceptions



class Internship(metaclass=_fbthrift_python_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "weeks",  # name
            _fbthrift_python_types.typeinfo_i32,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            2,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "title",  # name
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            3,  # id
            _fbthrift_python_types.FieldQualifier.Optional, # qualifier
            "employer",  # name
            lambda: _fbthrift_python_types.EnumTypeInfo(Company),  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            4,  # id
            _fbthrift_python_types.FieldQualifier.Optional, # qualifier
            "compensation",  # name
            _fbthrift_python_types.typeinfo_double,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            5,  # id
            _fbthrift_python_types.FieldQualifier.Optional, # qualifier
            "school",  # name
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.Internship"

    @staticmethod
    def __get_thrift_uri__():
        return None

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_Internship()

    def _to_python(self):
        return self

    def _to_py3(self):
        import importlib
        py3_types = importlib.import_module("module.types")
        import thrift.py3.converter
        return thrift.py3.converter.to_py3_struct(py3_types.Internship, self)

    def _to_py_deprecated(self):
        import importlib
        py_deprecated_types = importlib.import_module("module.ttypes")
        import thrift.util.converter
        return thrift.util.converter.to_py_struct(py_deprecated_types.Internship, self)


class Range(metaclass=_fbthrift_python_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "min",  # name
            _fbthrift_python_types.typeinfo_i32,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            2,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "max",  # name
            _fbthrift_python_types.typeinfo_i32,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.Range"

    @staticmethod
    def __get_thrift_uri__():
        return None

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_Range()

    def _to_python(self):
        return self

    def _to_py3(self):
        import importlib
        py3_types = importlib.import_module("module.types")
        import thrift.py3.converter
        return thrift.py3.converter.to_py3_struct(py3_types.Range, self)

    def _to_py_deprecated(self):
        import importlib
        py_deprecated_types = importlib.import_module("module.ttypes")
        import thrift.util.converter
        return thrift.util.converter.to_py_struct(py_deprecated_types.Range, self)


class struct1(metaclass=_fbthrift_python_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "a",  # name
            _fbthrift_python_types.typeinfo_i32,  # typeinfo
            1234567,  # default value
            None,  # adapter class
        ),
        (
            2,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "b",  # name
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            "<uninitialized>",  # default value
            None,  # adapter class
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.struct1"

    @staticmethod
    def __get_thrift_uri__():
        return None

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_struct1()

    def _to_python(self):
        return self

    def _to_py3(self):
        import importlib
        py3_types = importlib.import_module("module.types")
        import thrift.py3.converter
        return thrift.py3.converter.to_py3_struct(py3_types.struct1, self)

    def _to_py_deprecated(self):
        import importlib
        py_deprecated_types = importlib.import_module("module.ttypes")
        import thrift.util.converter
        return thrift.util.converter.to_py_struct(py_deprecated_types.struct1, self)


class struct2(metaclass=_fbthrift_python_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "a",  # name
            _fbthrift_python_types.typeinfo_i32,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            2,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "b",  # name
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            3,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "c",  # name
            lambda: _fbthrift_python_types.StructTypeInfo(struct1),  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            4,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "d",  # name
            lambda: _fbthrift_python_types.ListTypeInfo(_fbthrift_python_types.typeinfo_i32),  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.struct2"

    @staticmethod
    def __get_thrift_uri__():
        return None

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_struct2()

    def _to_python(self):
        return self

    def _to_py3(self):
        import importlib
        py3_types = importlib.import_module("module.types")
        import thrift.py3.converter
        return thrift.py3.converter.to_py3_struct(py3_types.struct2, self)

    def _to_py_deprecated(self):
        import importlib
        py_deprecated_types = importlib.import_module("module.ttypes")
        import thrift.util.converter
        return thrift.util.converter.to_py_struct(py_deprecated_types.struct2, self)


class struct3(metaclass=_fbthrift_python_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "a",  # name
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            2,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "b",  # name
            _fbthrift_python_types.typeinfo_i32,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            3,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "c",  # name
            lambda: _fbthrift_python_types.StructTypeInfo(struct2),  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.struct3"

    @staticmethod
    def __get_thrift_uri__():
        return None

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_struct3()

    def _to_python(self):
        return self

    def _to_py3(self):
        import importlib
        py3_types = importlib.import_module("module.types")
        import thrift.py3.converter
        return thrift.py3.converter.to_py3_struct(py3_types.struct3, self)

    def _to_py_deprecated(self):
        import importlib
        py_deprecated_types = importlib.import_module("module.ttypes")
        import thrift.util.converter
        return thrift.util.converter.to_py_struct(py_deprecated_types.struct3, self)


class struct4(metaclass=_fbthrift_python_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "a",  # name
            _fbthrift_python_types.typeinfo_i32,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            2,  # id
            _fbthrift_python_types.FieldQualifier.Optional, # qualifier
            "b",  # name
            _fbthrift_python_types.typeinfo_double,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            3,  # id
            _fbthrift_python_types.FieldQualifier.Optional, # qualifier
            "c",  # name
            _fbthrift_python_types.typeinfo_byte,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.struct4"

    @staticmethod
    def __get_thrift_uri__():
        return None

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_struct4()

    def _to_python(self):
        return self

    def _to_py3(self):
        import importlib
        py3_types = importlib.import_module("module.types")
        import thrift.py3.converter
        return thrift.py3.converter.to_py3_struct(py3_types.struct4, self)

    def _to_py_deprecated(self):
        import importlib
        py_deprecated_types = importlib.import_module("module.ttypes")
        import thrift.util.converter
        return thrift.util.converter.to_py_struct(py_deprecated_types.struct4, self)


class union1(metaclass=_fbthrift_python_types.UnionMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "i",  # name
            _fbthrift_python_types.typeinfo_i32,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            2,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "d",  # name
            _fbthrift_python_types.typeinfo_double,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.union1"

    @staticmethod
    def __get_thrift_uri__():
        return None

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_union1()

    def _to_python(self):
        return self

    def _to_py3(self):
        import importlib
        py3_types = importlib.import_module("module.types")
        import thrift.py3.converter
        return thrift.py3.converter.to_py3_struct(py3_types.union1, self)

    def _to_py_deprecated(self):
        import importlib
        py_deprecated_types = importlib.import_module("module.ttypes")
        import thrift.util.converter
        return thrift.util.converter.to_py_struct(py_deprecated_types.union1, self)


class union2(metaclass=_fbthrift_python_types.UnionMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "i",  # name
            _fbthrift_python_types.typeinfo_i32,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            2,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "d",  # name
            _fbthrift_python_types.typeinfo_double,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            3,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "s",  # name
            lambda: _fbthrift_python_types.StructTypeInfo(struct1),  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            4,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "u",  # name
            lambda: _fbthrift_python_types.StructTypeInfo(union1),  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.union2"

    @staticmethod
    def __get_thrift_uri__():
        return None

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_union2()

    def _to_python(self):
        return self

    def _to_py3(self):
        import importlib
        py3_types = importlib.import_module("module.types")
        import thrift.py3.converter
        return thrift.py3.converter.to_py3_struct(py3_types.union2, self)

    def _to_py_deprecated(self):
        import importlib
        py_deprecated_types = importlib.import_module("module.ttypes")
        import thrift.util.converter
        return thrift.util.converter.to_py_struct(py_deprecated_types.union2, self)

# This unfortunately has to be down here to prevent circular imports
import module.thrift_metadata

class EmptyEnum(_fbthrift_python_types.Enum, enum.Enum):
    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.EmptyEnum"

    @staticmethod
    def __get_metadata__():
        return module.thrift_metadata.gen_metadata_enum_EmptyEnum()
class City(_fbthrift_python_types.Enum, enum.Enum):
    NYC = 0
    MPK = 1
    SEA = 2
    LON = 3
    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.City"

    @staticmethod
    def __get_metadata__():
        return module.thrift_metadata.gen_metadata_enum_City()
class Company(_fbthrift_python_types.Enum, enum.Enum):
    FACEBOOK = 0
    WHATSAPP = 1
    OCULUS = 2
    INSTAGRAM = 3
    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.Company"

    @staticmethod
    def __get_metadata__():
        return module.thrift_metadata.gen_metadata_enum_Company()

def _fbthrift_metadata__struct_Internship():
    return module.thrift_metadata.gen_metadata_struct_Internship()
def _fbthrift_metadata__struct_Range():
    return module.thrift_metadata.gen_metadata_struct_Range()
def _fbthrift_metadata__struct_struct1():
    return module.thrift_metadata.gen_metadata_struct_struct1()
def _fbthrift_metadata__struct_struct2():
    return module.thrift_metadata.gen_metadata_struct_struct2()
def _fbthrift_metadata__struct_struct3():
    return module.thrift_metadata.gen_metadata_struct_struct3()
def _fbthrift_metadata__struct_struct4():
    return module.thrift_metadata.gen_metadata_struct_struct4()
def _fbthrift_metadata__struct_union1():
    return module.thrift_metadata.gen_metadata_struct_union1()
def _fbthrift_metadata__struct_union2():
    return module.thrift_metadata.gen_metadata_struct_union2()

_fbthrift_all_structs = [
    Internship,
    Range,
    struct1,
    struct2,
    struct3,
    struct4,
    union1,
    union2,
]
_fbthrift_python_types.fill_specs(*_fbthrift_all_structs)


myInt = 1337

name = "Mark Zuckerberg"

multi_line_string = """This
is a
multi line string.
"""

states = _fbthrift_python_types.List(_fbthrift_python_types.MapTypeInfo(_fbthrift_python_types.typeinfo_string, _fbthrift_python_types.typeinfo_i32), (_fbthrift_python_types.Map(_fbthrift_python_types.typeinfo_string, _fbthrift_python_types.typeinfo_i32, {"San Diego": 3211000, "Sacramento": 479600, "SF": 837400}), _fbthrift_python_types.Map(_fbthrift_python_types.typeinfo_string, _fbthrift_python_types.typeinfo_i32, {"New York": 8406000, "Albany": 98400}), ))

x = float(1)

y = 1000000.0

z = float(1000000000)

zeroDoubleValue = float(0)

longDoubleValue = float(2.59961000990301e-05)

my_company = Company.FACEBOOK

foo = "foo"

bar = 42

mymap = _fbthrift_python_types.Map(_fbthrift_python_types.typeinfo_string, _fbthrift_python_types.typeinfo_string, {"keys": "values"})

instagram = Internship(weeks=12, title="Software Engineer", employer=Company.INSTAGRAM, compensation=float(1200), school="Monters University")

partial_const = Internship(weeks=8, title="Some Job")

kRanges = _fbthrift_python_types.List(_fbthrift_python_types.StructTypeInfo(Range), (Range(min=1, max=2), Range(min=5, max=6), ))

internList = _fbthrift_python_types.List(_fbthrift_python_types.StructTypeInfo(Internship), (Internship(weeks=12, title="Software Engineer", employer=Company.INSTAGRAM, compensation=float(1200), school="Monters University"), Internship(weeks=10, title="Sales Intern", employer=Company.FACEBOOK, compensation=float(1000)), ))

pod_0 = struct1()

pod_s_0 = struct1()

pod_1 = struct1(a=10, b="foo")

pod_s_1 = struct1(a=10, b="foo")

pod_2 = struct2(a=98, b="gaz", c=struct1(a=12, b="bar"), d=_fbthrift_python_types.List(_fbthrift_python_types.typeinfo_i32, (11, 22, 33, )))

pod_trailing_commas = struct2(a=98, b="gaz", c=struct1(a=12, b="bar"), d=_fbthrift_python_types.List(_fbthrift_python_types.typeinfo_i32, (11, 22, 33, )))

pod_s_2 = struct2(a=98, b="gaz", c=struct1(a=12, b="bar"), d=_fbthrift_python_types.List(_fbthrift_python_types.typeinfo_i32, (11, 22, 33, )))

pod_3 = struct3(a="abc", b=456, c=struct2(a=888, c=struct1(b="gaz"), d=_fbthrift_python_types.List(_fbthrift_python_types.typeinfo_i32, (1, 2, 3, ))))

pod_s_3 = struct3(a="abc", b=456, c=struct2(a=888, c=struct1(b="gaz"), d=_fbthrift_python_types.List(_fbthrift_python_types.typeinfo_i32, (1, 2, 3, ))))

pod_4 = struct4(a=1234, b=float(0.333), c=25)

u_1_1 = union1(i=97)

u_1_2 = union1(d=float(5.6))

u_1_3 = union1()

u_2_1 = union2(i=51)

u_2_2 = union2(d=float(6.7))

u_2_3 = union2(s=struct1(a=8, b="abacabb"))

u_2_4 = union2(u=union1(i=43))

u_2_5 = union2(u=union1(d=float(9.8)))

u_2_6 = union2(u=union1())

apostrophe = "'"

tripleApostrophe = "'''"

quotationMark = '"'

backslash = "\\"

escaped_a = "\x61"

char2ascii = _fbthrift_python_types.Map(_fbthrift_python_types.typeinfo_string, _fbthrift_python_types.typeinfo_i32, {"'": 39, '"': 34, "\\": 92, "\x61": 97})

escaped_strings = _fbthrift_python_types.List(_fbthrift_python_types.typeinfo_string, ("\x61", "\xab", "\x6a", "\xa6", "\x61yyy", "\xabyyy", "\x6ayyy", "\xa6yyy", "zzz\x61", "zzz\xab", "zzz\x6a", "zzz\xa6", "zzz\x61yyy", "zzz\xabyyy", "zzz\x6ayyy", "zzz\xa6yyy", ))

false_c = False

true_c = True

zero_byte = 0

zero16 = 0

zero32 = 0

zero64 = 0

zero_dot_zero = float(0)

empty_string = ""

empty_int_list = _fbthrift_python_types.List(_fbthrift_python_types.typeinfo_i32, ())

empty_string_list = _fbthrift_python_types.List(_fbthrift_python_types.typeinfo_string, ())

empty_int_set = _fbthrift_python_types.Set(_fbthrift_python_types.typeinfo_i32, ())

empty_string_set = _fbthrift_python_types.Set(_fbthrift_python_types.typeinfo_string, ())

empty_int_int_map = _fbthrift_python_types.Map(_fbthrift_python_types.typeinfo_i32, _fbthrift_python_types.typeinfo_i32, {})

empty_int_string_map = _fbthrift_python_types.Map(_fbthrift_python_types.typeinfo_i32, _fbthrift_python_types.typeinfo_string, {})

empty_string_int_map = _fbthrift_python_types.Map(_fbthrift_python_types.typeinfo_string, _fbthrift_python_types.typeinfo_i32, {})

empty_string_string_map = _fbthrift_python_types.Map(_fbthrift_python_types.typeinfo_string, _fbthrift_python_types.typeinfo_string, {})

maxIntDec = 9223372036854775807

maxIntOct = 9223372036854775807

maxIntHex = 9223372036854775807

maxIntBin = 9223372036854775807

maxDub = float(1.7976931348623157e+308)

minDub = float(2.2250738585072014e-308)

minSDub = float(5e-324)

maxPIntDec = 9223372036854775807

maxPIntOct = 9223372036854775807

maxPIntHex = 9223372036854775807

maxPIntBin = 9223372036854775807

maxPDub = float(1.7976931348623157e+308)

minPDub = float(2.2250738585072014e-308)

minPSDub = float(5e-324)

minIntDec = -9223372036854775808

minIntOct = -9223372036854775808

minIntHex = -9223372036854775808

minIntBin = -9223372036854775808

maxNDub = float(-1.7976931348623157e+308)

minNDub = float(-2.2250738585072014e-308)

minNSDub = float(-5e-324)

MyCompany = Company
MyStringIdentifier = str
MyIntIdentifier = int
MyMapIdentifier = _fbthrift_python_types.MapTypeFactory(_fbthrift_python_types.typeinfo_string, _fbthrift_python_types.typeinfo_string)
