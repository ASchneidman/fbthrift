/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.includes;

import java.util.*;
import org.apache.thrift.protocol.*;
import com.facebook.swift.transport.client.ResponseWrapper;

public class MyServiceReactiveClient 
  implements MyService.Reactive {
  private final org.apache.thrift.ProtocolId _protocolId;
  private final reactor.core.publisher.Mono<? extends com.facebook.swift.transport.client.RpcClient> _rpcClient;
  private final Map<String, String> _headers;
  private final Map<String, String> _persistentHeaders;

  private static final TField _query_S_FIELD_DESC = new TField("s", TType.STRUCT, (short)1);
  private static final TField _query_I_FIELD_DESC = new TField("i", TType.STRUCT, (short)2);
  private static final java.util.Map<Short, com.facebook.swift.transport.payload.Reader> _query_EXCEPTION_READERS = java.util.Collections.emptyMap();
  private static final TField _hasArgDocs_S_FIELD_DESC = new TField("s", TType.STRUCT, (short)1);
  private static final TField _hasArgDocs_I_FIELD_DESC = new TField("i", TType.STRUCT, (short)2);
  private static final java.util.Map<Short, com.facebook.swift.transport.payload.Reader> _hasArgDocs_EXCEPTION_READERS = java.util.Collections.emptyMap();

  static {
  }

  public MyServiceReactiveClient(org.apache.thrift.ProtocolId _protocolId, reactor.core.publisher.Mono<? extends com.facebook.swift.transport.client.RpcClient> _rpcClient) {
    
    this._protocolId = _protocolId;
    this._rpcClient = _rpcClient;
    this._headers = java.util.Collections.emptyMap();
    this._persistentHeaders = java.util.Collections.emptyMap();
  }

  public MyServiceReactiveClient(org.apache.thrift.ProtocolId _protocolId, reactor.core.publisher.Mono<? extends com.facebook.swift.transport.client.RpcClient> _rpcClient, Map<String, String> _headers, Map<String, String> _persistentHeaders) {
    
    this._protocolId = _protocolId;
    this._rpcClient = _rpcClient;
    this._headers = _headers;
    this._persistentHeaders = _persistentHeaders;
  }

  @java.lang.Override
  public void close() {}

  private com.facebook.swift.transport.payload.Writer _createqueryWriter(final test.fixtures.includes.MyStruct s, final test.fixtures.includes.includes.Included i) {
    return oprot -> {
      try {
        {
          oprot.writeFieldBegin(_query_S_FIELD_DESC);

          test.fixtures.includes.MyStruct _iter0 = s;

          _iter0.write0(oprot);
          oprot.writeFieldEnd();
        }

        {
          oprot.writeFieldBegin(_query_I_FIELD_DESC);

          test.fixtures.includes.includes.Included _iter0 = i;

          _iter0.write0(oprot);
          oprot.writeFieldEnd();
        }


      } catch (Throwable _e) {
        throw reactor.core.Exceptions.propagate(_e);
      }
    };
  }

  private static final com.facebook.swift.transport.payload.Reader _query_READER =
    oprot -> {
              try {

                return null;

              } catch (Throwable _e) {
                throw reactor.core.Exceptions.propagate(_e);
              }
            };


  @java.lang.Override
  public reactor.core.publisher.Mono<com.facebook.swift.transport.client.ResponseWrapper<Void>> queryWrapper(final test.fixtures.includes.MyStruct s, final test.fixtures.includes.includes.Included i,  final com.facebook.swift.transport.client.RpcOptions rpcOptions) {
    return _rpcClient
      .flatMap(_rpc -> {
        org.apache.thrift.RequestRpcMetadata _metadata = new org.apache.thrift.RequestRpcMetadata.Builder()
                .setName("query")
                .setKind(org.apache.thrift.RpcKind.SINGLE_REQUEST_SINGLE_RESPONSE)
                .setOtherMetadata(getHeaders(rpcOptions))
                .setProtocol(_protocolId)
                .build();

            com.facebook.swift.transport.payload.ClientRequestPayload<Void> _crp =
                com.facebook.swift.transport.payload.ClientRequestPayload.create(
                    _createqueryWriter(s, i),
                    _query_READER,
                    _query_EXCEPTION_READERS,
                    _metadata,
                    java.util.Collections.emptyMap());

            return _rpc
                .singleRequestSingleResponse(_crp, rpcOptions).doOnNext(_p -> {if(_p.getException() != null) throw reactor.core.Exceptions.propagate(_p.getException());});
      });
  }

  @java.lang.Override
  public reactor.core.publisher.Mono<Void> query(final test.fixtures.includes.MyStruct s, final test.fixtures.includes.includes.Included i,  final com.facebook.swift.transport.client.RpcOptions rpcOptions) {
    return queryWrapper(s, i,  rpcOptions).map(_p -> _p.getData());
  }

  @java.lang.Override
  public reactor.core.publisher.Mono<Void> query(final test.fixtures.includes.MyStruct s, final test.fixtures.includes.includes.Included i) {
    return query(s, i,  com.facebook.swift.transport.client.RpcOptions.EMPTY);
  }

  private com.facebook.swift.transport.payload.Writer _createhasArgDocsWriter(final test.fixtures.includes.MyStruct s, final test.fixtures.includes.includes.Included i) {
    return oprot -> {
      try {
        {
          oprot.writeFieldBegin(_hasArgDocs_S_FIELD_DESC);

          test.fixtures.includes.MyStruct _iter0 = s;

          _iter0.write0(oprot);
          oprot.writeFieldEnd();
        }

        {
          oprot.writeFieldBegin(_hasArgDocs_I_FIELD_DESC);

          test.fixtures.includes.includes.Included _iter0 = i;

          _iter0.write0(oprot);
          oprot.writeFieldEnd();
        }


      } catch (Throwable _e) {
        throw reactor.core.Exceptions.propagate(_e);
      }
    };
  }

  private static final com.facebook.swift.transport.payload.Reader _hasArgDocs_READER =
    oprot -> {
              try {

                return null;

              } catch (Throwable _e) {
                throw reactor.core.Exceptions.propagate(_e);
              }
            };


  @java.lang.Override
  public reactor.core.publisher.Mono<com.facebook.swift.transport.client.ResponseWrapper<Void>> hasArgDocsWrapper(final test.fixtures.includes.MyStruct s, final test.fixtures.includes.includes.Included i,  final com.facebook.swift.transport.client.RpcOptions rpcOptions) {
    return _rpcClient
      .flatMap(_rpc -> {
        org.apache.thrift.RequestRpcMetadata _metadata = new org.apache.thrift.RequestRpcMetadata.Builder()
                .setName("hasArgDocs")
                .setKind(org.apache.thrift.RpcKind.SINGLE_REQUEST_SINGLE_RESPONSE)
                .setOtherMetadata(getHeaders(rpcOptions))
                .setProtocol(_protocolId)
                .build();

            com.facebook.swift.transport.payload.ClientRequestPayload<Void> _crp =
                com.facebook.swift.transport.payload.ClientRequestPayload.create(
                    _createhasArgDocsWriter(s, i),
                    _hasArgDocs_READER,
                    _hasArgDocs_EXCEPTION_READERS,
                    _metadata,
                    java.util.Collections.emptyMap());

            return _rpc
                .singleRequestSingleResponse(_crp, rpcOptions).doOnNext(_p -> {if(_p.getException() != null) throw reactor.core.Exceptions.propagate(_p.getException());});
      });
  }

  @java.lang.Override
  public reactor.core.publisher.Mono<Void> hasArgDocs(final test.fixtures.includes.MyStruct s, final test.fixtures.includes.includes.Included i,  final com.facebook.swift.transport.client.RpcOptions rpcOptions) {
    return hasArgDocsWrapper(s, i,  rpcOptions).map(_p -> _p.getData());
  }

  @java.lang.Override
  public reactor.core.publisher.Mono<Void> hasArgDocs(final test.fixtures.includes.MyStruct s, final test.fixtures.includes.includes.Included i) {
    return hasArgDocs(s, i,  com.facebook.swift.transport.client.RpcOptions.EMPTY);
  }


  private Map<String, String> getHeaders(com.facebook.swift.transport.client.RpcOptions rpcOptions) {
      Map<String, String> headers = new HashMap<>();
      if (rpcOptions.getRequestHeaders() != null && !rpcOptions.getRequestHeaders().isEmpty()) {
          headers.putAll(rpcOptions.getRequestHeaders());
      }
      if (_headers != null && !_headers.isEmpty()) {
          headers.putAll(_headers);
      }
      if (_persistentHeaders != null && !_persistentHeaders.isEmpty()) {
          headers.putAll(_persistentHeaders);
      }
      return headers;
  }
}
