#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

cimport cython
from cpython.version cimport PY_VERSION_HEX
from libc.stdint cimport (
    int8_t as cint8_t,
    int16_t as cint16_t,
    int32_t as cint32_t,
    int64_t as cint64_t,
)
from libcpp.memory cimport shared_ptr, make_shared, unique_ptr, make_unique
from libcpp.string cimport string
from libcpp cimport bool as cbool
from cpython cimport bool as pbool
from libcpp.vector cimport vector
from libcpp.set cimport set as cset
from libcpp.map cimport map as cmap
from libcpp.utility cimport move as cmove
from cython.operator cimport dereference as deref
from cpython.ref cimport PyObject
from thrift.py3.exceptions cimport (
    cTApplicationException,
    ApplicationError as __ApplicationError,
    cTApplicationExceptionType__UNKNOWN)
from thrift.py3.server cimport ServiceInterface, RequestContext, Cpp2RequestContext
from thrift.py3.server import RequestContext, pass_context
from folly cimport (
  cFollyPromise,
  cFollyUnit,
  c_unit,

)

if PY_VERSION_HEX >= 0x030702F0:  # 3.7.2 Final
    from thrift.py3.server cimport THRIFT_REQUEST_CONTEXT as __THRIFT_REQUEST_CONTEXT

cimport folly.futures
from folly.executor cimport get_executor
cimport folly.iobuf as __iobuf
import folly.iobuf as __iobuf
from folly.iobuf cimport move as move_iobuf
from folly.memory cimport to_shared_ptr as __to_shared_ptr

cimport my.namespacing.test.module.module.types as _my_namespacing_test_module_module_types
import my.namespacing.test.module.module.types as _my_namespacing_test_module_module_types

cimport my.namespacing.test.module.module.services_reflection as _services_reflection

import asyncio
import functools
import sys
import traceback
import types as _py_types

from my.namespacing.test.module.module.services_wrapper cimport cTestServiceInterface



@cython.auto_pickle(False)
cdef class Promise_cint64_t:
    cdef cFollyPromise[cint64_t] cPromise

    @staticmethod
    cdef create(cFollyPromise[cint64_t] cPromise):
        inst = <Promise_cint64_t>Promise_cint64_t.__new__(Promise_cint64_t)
        inst.cPromise = cmove(cPromise)
        return inst

cdef object _TestService_annotations = _py_types.MappingProxyType({
})


@cython.auto_pickle(False)
cdef class TestServiceInterface(
    ServiceInterface
):
    annotations = _TestService_annotations

    def __cinit__(self):
        self._cpp_obj = cTestServiceInterface(
            <PyObject *> self,
            get_executor()
        )

    @staticmethod
    def pass_context_init(fn):
        return pass_context(fn)

    async def init(
            self,
            int1):
        raise NotImplementedError("async def init is not implemented")

    @classmethod
    def __get_reflection__(cls):
        return _services_reflection.get_reflection__TestService(for_clients=False)



cdef api void call_cy_TestService_init(
    object self,
    Cpp2RequestContext* ctx,
    cFollyPromise[cint64_t] cPromise,
    cint64_t int1
):
    __promise = Promise_cint64_t.create(cmove(cPromise))
    arg_int1 = int1
    __context = RequestContext.create(ctx)
    if PY_VERSION_HEX >= 0x030702F0:  # 3.7.2 Final
        __context_token = __THRIFT_REQUEST_CONTEXT.set(__context)
        __context = None
    asyncio.get_event_loop().create_task(
        TestService_init_coro(
            self,
            __context,
            __promise,
            arg_int1
        )
    )
    if PY_VERSION_HEX >= 0x030702F0:  # 3.7.2 Final
        __THRIFT_REQUEST_CONTEXT.reset(__context_token)

async def TestService_init_coro(
    object self,
    object ctx,
    Promise_cint64_t promise,
    int1
):
    try:
        if ctx and getattr(self.init, "pass_context", False):
            result = await self.init(ctx,
                      int1)
        else:
            result = await self.init(
                      int1)
    except __ApplicationError as ex:
        # If the handler raised an ApplicationError convert it to a C++ one
        promise.cPromise.setException(cTApplicationException(
            ex.type.value, ex.message.encode('UTF-8')
        ))
    except Exception as ex:
        print(
            "Unexpected error in service handler init:",
            file=sys.stderr)
        traceback.print_exc()
        promise.cPromise.setException(cTApplicationException(
            cTApplicationExceptionType__UNKNOWN, repr(ex).encode('UTF-8')
        ))
    else:
        promise.cPromise.setValue(<cint64_t> result)

