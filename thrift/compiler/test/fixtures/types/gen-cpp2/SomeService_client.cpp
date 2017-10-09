/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#include "src/gen-cpp2/SomeServiceAsyncClient.h"

#include <folly/io/IOBuf.h>
#include <folly/io/IOBufQueue.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp/transport/THeader.h>
#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
#include <thrift/lib/cpp2/GeneratedCodeHelper.h>
#include <thrift/lib/cpp2/GeneratedSerializationCodeHelper.h>

namespace apache { namespace thrift { namespace fixtures { namespace types {
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_MAP,  ::apache::thrift::fixtures::types::SomeMap*>> SomeService_bounce_map_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_MAP,  ::apache::thrift::fixtures::types::SomeMap*>> SomeService_bounce_map_presult;

const char* SomeServiceAsyncClient::getServiceName() {
  return "SomeService";
}

template <typename Protocol_>
void SomeServiceAsyncClient::bounce_mapT(Protocol_* prot, bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(getChannel()->getProtocolId());
  header->setHeaders(rpcOptions.releaseWriteHeaders());
  connectionContext_->setRequestHeader(header.get());
  std::unique_ptr<apache::thrift::ContextStack> ctx = this->getContextStack(this->getServiceName(), "SomeService.bounce_map", connectionContext_.get());
  SomeService_bounce_map_pargs args;
  args.get<0>().value = const_cast< ::apache::thrift::fixtures::types::SomeMap*>(&m);
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<Protocol_>(prot, rpcOptions, std::move(callback), std::move(ctx), header, channel_.get(), "bounce_map", writer, sizer, false, useSync);
  connectionContext_->setRequestHeader(nullptr);
}

template <typename Protocol_>
folly::exception_wrapper SomeServiceAsyncClient::recv_wrapped_bounce_mapT(Protocol_* prot,  ::apache::thrift::fixtures::types::SomeMap& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  prot->setInput(state.buf());
  auto guard = folly::makeGuard([&] {prot->setInput(nullptr);});
  apache::thrift::ContextStack* ctx = state.ctx();
  std::string _fname;
  int32_t protoSeqId = 0;
  apache::thrift::MessageType mtype;
  ctx->preRead();
  folly::exception_wrapper interior_ew;
  auto caught_ew = folly::try_and_catch<std::exception, apache::thrift::TException, apache::thrift::protocol::TProtocolException>([&]() {
    prot->readMessageBegin(_fname, mtype, protoSeqId);
    if (mtype == apache::thrift::T_EXCEPTION) {
      apache::thrift::TApplicationException x;
      x.read(prot);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(x);
      return; // from try_and_catch
    }
    if (mtype != apache::thrift::T_REPLY) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::INVALID_MESSAGE_TYPE);
      return; // from try_and_catch
    }
    if (_fname.compare("bounce_map") != 0) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::WRONG_METHOD_NAME);
      return; // from try_and_catch
    }
    ::apache::thrift::SerializedMessage smsg;
    smsg.protocolType = prot->protocolType();
    smsg.buffer = state.buf();
    ctx->onReadData(smsg);
    SomeService_bounce_map_presult result;
    result.get<0>().value = &_return;
    ::apache::thrift::detail::deserializeRequestBody(prot, &result);
    prot->readMessageEnd();
    ctx->postRead(state.header(), state.buf()->length());
    if (result.getIsSet(0)) {
      // _return pointer has been filled
      return; // from try_and_catch
    }
    else {
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::MISSING_RESULT, "failed: unknown result");
      return; // from try_and_catch
    }
  }
  );
  auto ew = interior_ew ? std::move(interior_ew) : std::move(caught_ew);
  if (ew) {
    ctx->handlerErrorWrapped(ew);
  }
  return ew;
}

template <typename Protocol_>
void SomeServiceAsyncClient::recv_bounce_mapT(Protocol_* prot,  ::apache::thrift::fixtures::types::SomeMap& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_bounce_mapT(prot, _return, state);
  if (ew) {
    ew.throw_exception();
  }
}



void SomeServiceAsyncClient::bounce_map(std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  ::apache::thrift::RpcOptions rpcOptions;
  bounce_mapImpl(false, rpcOptions, std::move(callback), m);
}

void SomeServiceAsyncClient::bounce_map(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  bounce_mapImpl(false, rpcOptions, std::move(callback), m);
}

void SomeServiceAsyncClient::bounce_mapImpl(bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      bounce_mapT(&writer, useSync, rpcOptions, std::move(callback), m);
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      bounce_mapT(&writer, useSync, rpcOptions, std::move(callback), m);
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

void SomeServiceAsyncClient::sync_bounce_map( ::apache::thrift::fixtures::types::SomeMap& _return, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_bounce_map(rpcOptions, _return, m);
}

void SomeServiceAsyncClient::sync_bounce_map(apache::thrift::RpcOptions& rpcOptions,  ::apache::thrift::fixtures::types::SomeMap& _return, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback = std::make_unique<apache::thrift::ClientSyncCallback>(&_returnState, false);
  bounce_mapImpl(true, rpcOptions, std::move(callback), m);
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(_returnState.exception());
    _returnState.exception().throw_exception();
  }
  recv_bounce_map(_return, _returnState);
}

folly::Future< ::apache::thrift::fixtures::types::SomeMap> SomeServiceAsyncClient::future_bounce_map(const  ::apache::thrift::fixtures::types::SomeMap& m) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_bounce_map(rpcOptions, m);
}

folly::Future< ::apache::thrift::fixtures::types::SomeMap> SomeServiceAsyncClient::future_bounce_map(apache::thrift::RpcOptions& rpcOptions, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  folly::Promise< ::apache::thrift::fixtures::types::SomeMap> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback< ::apache::thrift::fixtures::types::SomeMap>>(std::move(_promise), recv_wrapped_bounce_map, channel_);
  bounce_map(rpcOptions, std::move(callback), m);
  return _future;
}

folly::Future<std::pair< ::apache::thrift::fixtures::types::SomeMap, std::unique_ptr<apache::thrift::transport::THeader>>> SomeServiceAsyncClient::header_future_bounce_map(apache::thrift::RpcOptions& rpcOptions, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  folly::Promise<std::pair< ::apache::thrift::fixtures::types::SomeMap, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback< ::apache::thrift::fixtures::types::SomeMap>>(std::move(_promise), recv_wrapped_bounce_map, channel_);
  bounce_map(rpcOptions, std::move(callback), m);
  return _future;
}

void SomeServiceAsyncClient::bounce_map(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, const  ::apache::thrift::fixtures::types::SomeMap& m) {
  bounce_map(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), m);
}

folly::exception_wrapper SomeServiceAsyncClient::recv_wrapped_bounce_map( ::apache::thrift::fixtures::types::SomeMap& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }
  switch(state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return recv_wrapped_bounce_mapT(&reader, _return, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return recv_wrapped_bounce_mapT(&reader, _return, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void SomeServiceAsyncClient::recv_bounce_map( ::apache::thrift::fixtures::types::SomeMap& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_bounce_map(_return, state);
  if (ew) {
    ew.throw_exception();
  }
}

void SomeServiceAsyncClient::recv_instance_bounce_map( ::apache::thrift::fixtures::types::SomeMap& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_bounce_map(_return, state);
}

folly::exception_wrapper SomeServiceAsyncClient::recv_instance_wrapped_bounce_map( ::apache::thrift::fixtures::types::SomeMap& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_bounce_map(_return, state);
}

}}}} // apache::thrift::fixtures::types
namespace apache { namespace thrift {

}} // apache::thrift
