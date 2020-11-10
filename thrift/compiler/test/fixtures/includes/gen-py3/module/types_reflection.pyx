#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#


import folly.iobuf as __iobuf

from thrift.py3.reflection cimport (
    NumberType as __NumberType,
    StructType as __StructType,
    Qualifier as __Qualifier,
)

cimport includes.types as _includes_types

cimport module.types as _module_types

from thrift.py3.types cimport (
    constant_shared_ptr,
    default_inst,
)


cdef __StructSpec get_reflection__MyStruct():
    cdef _module_types.MyStruct defaults = _module_types.MyStruct.create(
        constant_shared_ptr[_module_types.cMyStruct](
            default_inst[_module_types.cMyStruct]()
        )
    )
    cdef __StructSpec spec = __StructSpec.create(
        name="MyStruct",
        kind=__StructType.STRUCT,
        annotations={
        },
    )
    spec.add_field(
        __FieldSpec.create(
            id=1,
            name="MyIncludedField",
            type=_includes_types.Included,
            kind=__NumberType.NOT_A_NUMBER,
            qualifier=__Qualifier.UNQUALIFIED,
            default=defaults.MyIncludedField,
            annotations={
            },
        ),
    )
    spec.add_field(
        __FieldSpec.create(
            id=2,
            name="MyOtherIncludedField",
            type=_includes_types.Included,
            kind=__NumberType.NOT_A_NUMBER,
            qualifier=__Qualifier.UNQUALIFIED,
            default=None,
            annotations={
            },
        ),
    )
    spec.add_field(
        __FieldSpec.create(
            id=3,
            name="MyIncludedInt",
            type=int,
            kind=__NumberType.I64,
            qualifier=__Qualifier.UNQUALIFIED,
            default=defaults.MyIncludedInt,
            annotations={
            },
        ),
    )
    return spec
