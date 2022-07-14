/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.interactions;

import static com.facebook.swift.service.SwiftConstants.STICKY_HASH_KEY;

import java.util.*;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicLong;
import org.apache.thrift.protocol.*;
import org.apache.thrift.ClientPushMetadata;
import org.apache.thrift.InteractionCreate;
import org.apache.thrift.InteractionTerminate;
import com.facebook.thrift.client.ResponseWrapper;
import com.facebook.thrift.client.RpcOptions;
import com.facebook.thrift.util.Readers;

public class MyServiceReactiveClient 
  implements MyService.Reactive {
  private static final AtomicLong _interactionCounter = new AtomicLong(0);

  protected final org.apache.thrift.ProtocolId _protocolId;
  protected final reactor.core.publisher.Mono<? extends com.facebook.thrift.client.RpcClient> _rpcClient;
  protected final Map<String, String> _headers;
  protected final Map<String, String> _persistentHeaders;
  protected final Set<Long> _activeInteractions;

  private static final java.util.Map<Short, com.facebook.thrift.payload.Reader> _foo_EXCEPTION_READERS = java.util.Collections.emptyMap();
  private static final TField _interact_ARG_FIELD_DESC = new TField("arg", TType.I32, (short)1);
  private static final java.util.Map<Short, com.facebook.thrift.payload.Reader> _interact_EXCEPTION_READERS = java.util.Collections.emptyMap();
  private static final java.util.Map<Short, com.facebook.thrift.payload.Reader> _interactFast_EXCEPTION_READERS = java.util.Collections.emptyMap();
  private static final java.util.Map<Short, com.facebook.thrift.payload.Reader> _serialize_EXCEPTION_READERS = java.util.Collections.emptyMap();
  private static final java.util.Map<Short, com.facebook.thrift.payload.Reader> _serialize_STREAM_EXCEPTION_READERS = java.util.Collections.emptyMap();
  private static final java.util.Map<Short, com.facebook.thrift.payload.Reader> _frobnicate_EXCEPTION_READERS_INT = new HashMap<>();
  private static final com.facebook.thrift.payload.Reader _frobnicate_EXCEPTION_READER_INT0 = Readers.wrap(test.fixtures.interactions.CustomException.asReader());
  private static final java.util.Map<Short, com.facebook.thrift.payload.Reader> _ping_EXCEPTION_READERS_INT = java.util.Collections.emptyMap();
  private static final java.util.Map<Short, com.facebook.thrift.payload.Reader> _truthify_EXCEPTION_READERS_INT = java.util.Collections.emptyMap();
  private static final java.util.Map<Short, com.facebook.thrift.payload.Reader> _truthify_STREAM_EXCEPTION_READERS_INT = java.util.Collections.emptyMap();
  private static final java.util.Map<Short, com.facebook.thrift.payload.Reader> _frobnicate_EXCEPTION_READERS_INT = java.util.Collections.emptyMap();
  private static final java.util.Map<Short, com.facebook.thrift.payload.Reader> _ping_EXCEPTION_READERS_INT = java.util.Collections.emptyMap();
  private static final java.util.Map<Short, com.facebook.thrift.payload.Reader> _truthify_EXCEPTION_READERS_INT = java.util.Collections.emptyMap();
  private static final java.util.Map<Short, com.facebook.thrift.payload.Reader> _truthify_STREAM_EXCEPTION_READERS_INT = java.util.Collections.emptyMap();
  private static final java.util.Map<Short, com.facebook.thrift.payload.Reader> _frobnicate_EXCEPTION_READERS_INT = java.util.Collections.emptyMap();

  static {
  }

  public MyServiceReactiveClient(org.apache.thrift.ProtocolId _protocolId, reactor.core.publisher.Mono<? extends com.facebook.thrift.client.RpcClient> _rpcClient) {
    
    this._protocolId = _protocolId;
    this._rpcClient = _rpcClient;
    this._headers = java.util.Collections.emptyMap();
    this._persistentHeaders = java.util.Collections.emptyMap();
    this._activeInteractions = ConcurrentHashMap.newKeySet();
  }

  public MyServiceReactiveClient(org.apache.thrift.ProtocolId _protocolId, reactor.core.publisher.Mono<? extends com.facebook.thrift.client.RpcClient> _rpcClient, Map<String, String> _headers, Map<String, String> _persistentHeaders) {
    this(_protocolId, _rpcClient, _headers, _persistentHeaders, new AtomicLong(), ConcurrentHashMap.newKeySet());
  }

  public MyServiceReactiveClient(org.apache.thrift.ProtocolId _protocolId, reactor.core.publisher.Mono<? extends com.facebook.thrift.client.RpcClient> _rpcClient, Map<String, String> _headers, Map<String, String> _persistentHeaders, AtomicLong interactionCounter, Set<Long> activeInteractions) {
    
    this._protocolId = _protocolId;
    this._rpcClient = _rpcClient;
    this._headers = _headers;
    this._persistentHeaders = _persistentHeaders;
    this._activeInteractions = activeInteractions;
  }

  @java.lang.Override
  public void dispose() {}

  private com.facebook.thrift.payload.Writer _createfooWriter() {
    return oprot -> {
      try {

      } catch (Throwable _e) {
        throw reactor.core.Exceptions.propagate(_e);
      }
    };
  }

  private static final com.facebook.thrift.payload.Reader _foo_READER = Readers.voidReader();

  @java.lang.Override
  public reactor.core.publisher.Mono<com.facebook.thrift.client.ResponseWrapper<Void>> fooWrapper( final com.facebook.thrift.client.RpcOptions rpcOptions) {
    return _rpcClient
      .flatMap(_rpc -> {
        org.apache.thrift.RequestRpcMetadata _metadata = new org.apache.thrift.RequestRpcMetadata.Builder()
                .setName("foo")
                .setKind(org.apache.thrift.RpcKind.SINGLE_REQUEST_SINGLE_RESPONSE)
                .setOtherMetadata(getHeaders(rpcOptions))
                .setProtocol(_protocolId)
                .build();

            com.facebook.thrift.payload.ClientRequestPayload<Void> _crp =
                com.facebook.thrift.payload.ClientRequestPayload.create(
                    "MyService",
                    _createfooWriter(),
                    _foo_READER,
                    _foo_EXCEPTION_READERS,
                    _metadata,
                    java.util.Collections.emptyMap());

            return _rpc
                .singleRequestSingleResponse(_crp, rpcOptions).doOnNext(_p -> {if(_p.getException() != null) throw com.facebook.thrift.util.ExceptionUtil.propagate(_p);});
      });
  }

  @java.lang.Override
  public reactor.core.publisher.Mono<Void> foo( final com.facebook.thrift.client.RpcOptions rpcOptions) {
    return fooWrapper( rpcOptions).then();
  }

  @java.lang.Override
  public reactor.core.publisher.Mono<Void> foo() {
    return foo( com.facebook.thrift.client.RpcOptions.EMPTY);
  }

  private com.facebook.thrift.payload.Writer _createinteractWriter(final int arg) {
    return oprot -> {
      try {
        {
          oprot.writeFieldBegin(_interact_ARG_FIELD_DESC);

          int _iter0 = arg;

          oprot.writeI32(arg);
          oprot.writeFieldEnd();
        }


      } catch (Throwable _e) {
        throw reactor.core.Exceptions.propagate(_e);
      }
    };
  }

  private static final com.facebook.thrift.payload.Reader _interact_READER = Readers.voidReader();

  @java.lang.Override
  public reactor.core.publisher.Mono<com.facebook.thrift.client.ResponseWrapper<Void>> interactWrapper(final int arg,  final com.facebook.thrift.client.RpcOptions rpcOptions) {
    return _rpcClient
      .flatMap(_rpc -> {
        org.apache.thrift.RequestRpcMetadata _metadata = new org.apache.thrift.RequestRpcMetadata.Builder()
                .setName("interact")
                .setKind(org.apache.thrift.RpcKind.SINGLE_REQUEST_SINGLE_RESPONSE)
                .setOtherMetadata(getHeaders(rpcOptions))
                .setProtocol(_protocolId)
                .build();

            com.facebook.thrift.payload.ClientRequestPayload<Void> _crp =
                com.facebook.thrift.payload.ClientRequestPayload.create(
                    "MyService",
                    _createinteractWriter(arg),
                    _interact_READER,
                    _interact_EXCEPTION_READERS,
                    _metadata,
                    java.util.Collections.emptyMap());

            return _rpc
                .singleRequestSingleResponse(_crp, rpcOptions).doOnNext(_p -> {if(_p.getException() != null) throw com.facebook.thrift.util.ExceptionUtil.propagate(_p);});
      });
  }

  @java.lang.Override
  public reactor.core.publisher.Mono<Void> interact(final int arg,  final com.facebook.thrift.client.RpcOptions rpcOptions) {
    return interactWrapper(arg,  rpcOptions).then();
  }

  @java.lang.Override
  public reactor.core.publisher.Mono<Void> interact(final int arg) {
    return interact(arg,  com.facebook.thrift.client.RpcOptions.EMPTY);
  }

  private com.facebook.thrift.payload.Writer _createinteractFastWriter() {
    return oprot -> {
      try {

      } catch (Throwable _e) {
        throw reactor.core.Exceptions.propagate(_e);
      }
    };
  }

  private static final com.facebook.thrift.payload.Reader _interactFast_READER = Readers.i32Reader();

  @java.lang.Override
  public reactor.core.publisher.Mono<com.facebook.thrift.client.ResponseWrapper<Integer>> interactFastWrapper( final com.facebook.thrift.client.RpcOptions rpcOptions) {
    return _rpcClient
      .flatMap(_rpc -> {
        org.apache.thrift.RequestRpcMetadata _metadata = new org.apache.thrift.RequestRpcMetadata.Builder()
                .setName("interactFast")
                .setKind(org.apache.thrift.RpcKind.SINGLE_REQUEST_SINGLE_RESPONSE)
                .setOtherMetadata(getHeaders(rpcOptions))
                .setProtocol(_protocolId)
                .build();

            com.facebook.thrift.payload.ClientRequestPayload<Integer> _crp =
                com.facebook.thrift.payload.ClientRequestPayload.create(
                    "MyService",
                    _createinteractFastWriter(),
                    _interactFast_READER,
                    _interactFast_EXCEPTION_READERS,
                    _metadata,
                    java.util.Collections.emptyMap());

            return _rpc
                .singleRequestSingleResponse(_crp, rpcOptions).doOnNext(_p -> {if(_p.getException() != null) throw com.facebook.thrift.util.ExceptionUtil.propagate(_p);});
      });
  }

  @java.lang.Override
  public reactor.core.publisher.Mono<Integer> interactFast( final com.facebook.thrift.client.RpcOptions rpcOptions) {
    return interactFastWrapper( rpcOptions).map(_p -> _p.getData());
  }

  @java.lang.Override
  public reactor.core.publisher.Mono<Integer> interactFast() {
    return interactFast( com.facebook.thrift.client.RpcOptions.EMPTY);
  }

  private com.facebook.thrift.payload.Writer _createserializeWriter() {
    return oprot -> {
      try {

      } catch (Throwable _e) {
        throw reactor.core.Exceptions.propagate(_e);
      }
    };
  }

  private static final com.facebook.thrift.payload.Reader _serialize_READER = Readers.i32Reader();

  private static final com.facebook.thrift.payload.Reader _serialize_FIRST_READER = Readers.i32Reader();

  @java.lang.Override
  public reactor.core.publisher.Flux<com.facebook.thrift.client.ResponseWrapper<com.facebook.thrift.model.StreamResponse<Integer,Integer>>> serializeWrapper( final com.facebook.thrift.client.RpcOptions rpcOptions) {
    return _rpcClient
      .flatMapMany(_rpc -> {
        org.apache.thrift.RequestRpcMetadata _metadata = new org.apache.thrift.RequestRpcMetadata.Builder()
                .setName("serialize")
                .setKind(org.apache.thrift.RpcKind.SINGLE_REQUEST_STREAMING_RESPONSE)
                .setOtherMetadata(getHeaders(rpcOptions))
                .setProtocol(_protocolId)
                .build();

            com.facebook.thrift.payload.ClientRequestPayload<Integer> _crp =
                com.facebook.thrift.payload.ClientRequestPayload.create(
                    "MyService",
                    _createserializeWriter(),
                    _serialize_READER,
                    _serialize_FIRST_READER,
                    _serialize_EXCEPTION_READERS,
                    _serialize_STREAM_EXCEPTION_READERS,
                    _metadata,
                    java.util.Collections.emptyMap());

            return _rpc
                .singleRequestStreamingResponse(_crp, rpcOptions)
                .doOnNext(_p -> {if(_p.getException() != null) throw reactor.core.Exceptions.propagate(_p.getException());})
                .map(_p -> ResponseWrapper.create(((com.facebook.thrift.model.StreamResponse<Integer,Integer>)_p.getData()), _p.getHeaders(), _p.getBinaryHeaders()));
      });
  }

  @java.lang.Override
  public reactor.core.publisher.Flux<com.facebook.thrift.model.StreamResponse<Integer,Integer>> serialize( final com.facebook.thrift.client.RpcOptions rpcOptions) {
      return serializeWrapper( rpcOptions).map(_p -> _p.getData());
  }

  @java.lang.Override
  public reactor.core.publisher.Flux<com.facebook.thrift.model.StreamResponse<Integer,Integer>> serialize() {
    return serialize( com.facebook.thrift.client.RpcOptions.EMPTY);
  }


  public class MyInteractionImpl implements MyInteraction {
    private final long interactionId;

    MyInteractionImpl(long interactionId) {
      this.interactionId = interactionId;
      com.facebook.thrift.client.ThriftClientStatsHolder.getThriftClientStats().interactionCreated("MyInteraction");
    }

    private final java.util.Map<Short, com.facebook.thrift.payload.Reader> _frobnicate_EXCEPTION_READERS = new HashMap<>();
    private final com.facebook.thrift.payload.Reader _frobnicate_EXCEPTION_READER_INT0 = Readers.wrap(test.fixtures.interactions.CustomException.asReader());

    private final java.util.Map<Short, com.facebook.thrift.payload.Reader> _ping_EXCEPTION_READERS = java.util.Collections.emptyMap();

    private com.facebook.thrift.payload.Writer _createfrobnicateWriter() {
      return oprot -> {
        try {

        } catch (Throwable _e) {
          throw reactor.core.Exceptions.propagate(_e);
        }
      };
    }

    private final com.facebook.thrift.payload.Reader _frobnicate_READER = Readers.i32Reader();

    public reactor.core.publisher.Mono<Integer> frobnicate() {
      return frobnicateWrapper( com.facebook.thrift.client.RpcOptions.EMPTY).map(_p -> _p.getData());
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<Integer> frobnicate(RpcOptions rpcOptions)  {
      return frobnicateWrapper( rpcOptions).map(_p -> _p.getData());
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<ResponseWrapper<Integer>> frobnicateWrapper(RpcOptions rpcOptions)  {
      return _rpcClient
        .subscriberContext(ctx -> ctx.put(STICKY_HASH_KEY, interactionId))
        .flatMap(_rpc -> {
          String interactionName = "MyInteraction.frobnicate";
          org.apache.thrift.RequestRpcMetadata.Builder _metadataBuilder = new org.apache.thrift.RequestRpcMetadata.Builder()
                  .setName(interactionName)
                  .setKind(org.apache.thrift.RpcKind.SINGLE_REQUEST_SINGLE_RESPONSE)
                  .setOtherMetadata(getHeaders(rpcOptions))
                  .setProtocol(_protocolId);

          if (_activeInteractions.contains(interactionId)) {
            _metadataBuilder.setInteractionId(interactionId);
          } else {
            _metadataBuilder.setInteractionCreate(
              new InteractionCreate.Builder()
                  .setInteractionId(interactionId)
                  .setInteractionName("MyInteraction")
                  .build());
            _metadataBuilder.setInteractionId(0L);
            _activeInteractions.add(interactionId);
          }

          org.apache.thrift.RequestRpcMetadata _metadata = _metadataBuilder.build();

          com.facebook.thrift.payload.ClientRequestPayload<Integer> _crp =
              com.facebook.thrift.payload.ClientRequestPayload.create(
                  "MyInteraction",
                  _createfrobnicateWriter(),
                  _frobnicate_READER,
                  _frobnicate_EXCEPTION_READERS_INT,
                  _metadata,
                  java.util.Collections.emptyMap());

          return _rpc
              .singleRequestSingleResponse(_crp, rpcOptions).doOnNext(_p -> {if(_p.getException() != null) throw com.facebook.thrift.util.ExceptionUtil.propagate(_p);});
        });
    }

    private com.facebook.thrift.payload.Writer _createpingWriter() {
      return oprot -> {
        try {

        } catch (Throwable _e) {
          throw reactor.core.Exceptions.propagate(_e);
        }
      };
    }

    private final com.facebook.thrift.payload.Reader _ping_READER = Readers.voidReader();

    public reactor.core.publisher.Mono<Void> ping() {
      return pingWrapper( com.facebook.thrift.client.RpcOptions.EMPTY).then();
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<Void> ping(RpcOptions rpcOptions)  {
      return pingWrapper( rpcOptions).then();
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<ResponseWrapper<Void>> pingWrapper(RpcOptions rpcOptions)  {
      return _rpcClient
        .subscriberContext(ctx -> ctx.put(STICKY_HASH_KEY, interactionId))
        .flatMap(_rpc -> {
          String interactionName = "MyInteraction.ping";
          org.apache.thrift.RequestRpcMetadata.Builder _metadataBuilder = new org.apache.thrift.RequestRpcMetadata.Builder()
                  .setName(interactionName)
                  .setKind(org.apache.thrift.RpcKind.SINGLE_REQUEST_NO_RESPONSE)
                  .setOtherMetadata(getHeaders(rpcOptions))
                  .setProtocol(_protocolId);

          if (_activeInteractions.contains(interactionId)) {
            _metadataBuilder.setInteractionId(interactionId);
          } else {
            _metadataBuilder.setInteractionCreate(
              new InteractionCreate.Builder()
                  .setInteractionId(interactionId)
                  .setInteractionName("MyInteraction")
                  .build());
            _metadataBuilder.setInteractionId(0L);
            _activeInteractions.add(interactionId);
          }

          org.apache.thrift.RequestRpcMetadata _metadata = _metadataBuilder.build();

          com.facebook.thrift.payload.ClientRequestPayload<Void> _crp =
              com.facebook.thrift.payload.ClientRequestPayload.create(
                  "MyInteraction",
                  _createpingWriter(),
                  _ping_READER,
                  _ping_EXCEPTION_READERS_INT,
                  _metadata,
                  java.util.Collections.emptyMap());

          return _rpc
              .singleRequestNoResponse(_crp, rpcOptions).thenReturn(ResponseWrapper.create(null, java.util.Collections.emptyMap(), java.util.Collections.emptyMap()));
        });
    }

    private com.facebook.thrift.payload.Writer _createtruthifyWriter() {
      return oprot -> {
        try {

        } catch (Throwable _e) {
          throw reactor.core.Exceptions.propagate(_e);
        }
      };
    }

    private final com.facebook.thrift.payload.Reader _truthify_READER = Readers.booleanReader();


    @java.lang.Override
    public reactor.core.publisher.Flux<com.facebook.thrift.client.ResponseWrapper<Boolean>> truthifyWrapper( final com.facebook.thrift.client.RpcOptions rpcOptions) {
      return _rpcClient
        .subscriberContext(ctx -> ctx.put(STICKY_HASH_KEY, interactionId))
        .flatMapMany(_rpc -> {
          String interactionName = "MyInteraction.truthify";
          org.apache.thrift.RequestRpcMetadata.Builder _metadataBuilder = new org.apache.thrift.RequestRpcMetadata.Builder()
                  .setName(interactionName)
                  .setKind(org.apache.thrift.RpcKind.SINGLE_REQUEST_STREAMING_RESPONSE)
                  .setOtherMetadata(getHeaders(rpcOptions))
                  .setProtocol(_protocolId);

          if (_activeInteractions.contains(interactionId)) {
            _metadataBuilder.setInteractionId(interactionId);
          } else {
            _metadataBuilder.setInteractionCreate(
              new InteractionCreate.Builder()
                  .setInteractionId(interactionId)
                  .setInteractionName("MyInteraction")
                  .build());
            _metadataBuilder.setInteractionId(0L);
            _activeInteractions.add(interactionId);
          }


          com.facebook.thrift.payload.ClientRequestPayload<Boolean> _crp =
              com.facebook.thrift.payload.ClientRequestPayload.create(
                  "MyInteraction",
                  _createtruthifyWriter(),
                  _truthify_READER,
                  _truthify_EXCEPTION_READERS_INT,
                  _truthify_STREAM_EXCEPTION_READERS_INT,
                  _metadataBuilder.build(),
                  java.util.Collections.emptyMap());

          return _rpc
              .singleRequestStreamingResponse(_crp, rpcOptions)
              .transform(com.facebook.thrift.util.FluxPublishingTransformer.getInstance())
              .doOnNext(_p -> {if(_p.getException() != null) throw reactor.core.Exceptions.propagate(_p.getException());})
              .filter((_p) -> ((com.facebook.thrift.model.StreamResponse)_p.getData()).isSetData())
              .map(_p -> ResponseWrapper.create(((com.facebook.thrift.model.StreamResponse<Void, Boolean>)_p.getData()).getData(), _p.getHeaders(), _p.getBinaryHeaders()));
        });
    }

    @java.lang.Override
    public reactor.core.publisher.Flux<Boolean> truthify( final com.facebook.thrift.client.RpcOptions rpcOptions) {
        return truthifyWrapper( rpcOptions).map(_p -> _p.getData());
    }

    @java.lang.Override
    public reactor.core.publisher.Flux<Boolean> truthify() {
      return truthify( com.facebook.thrift.client.RpcOptions.EMPTY);
    }

    @java.lang.Override
    public void dispose() {
      com.facebook.thrift.client.ThriftClientStatsHolder.getThriftClientStats().interactionDisposed("MyInteraction");
      _activeInteractions.remove(interactionId);
      _rpcClient
        .subscriberContext(ctx -> ctx.put(STICKY_HASH_KEY, interactionId))
        .flatMap(_rpc -> {
          InteractionTerminate term = new InteractionTerminate.Builder().setInteractionId(interactionId).build();
          ClientPushMetadata metadata = ClientPushMetadata.fromInteractionTerminate(term);
          return _rpc.metadataPush(metadata, com.facebook.thrift.client.RpcOptions.EMPTY);
        }).subscribe();
    }
  }

  public MyInteraction createMyInteraction() {
      return new MyInteractionImpl(_interactionCounter.incrementAndGet());
  }

  public class MyInteractionFastImpl implements MyInteractionFast {
    private final long interactionId;

    MyInteractionFastImpl(long interactionId) {
      this.interactionId = interactionId;
      com.facebook.thrift.client.ThriftClientStatsHolder.getThriftClientStats().interactionCreated("MyInteractionFast");
    }

    private final java.util.Map<Short, com.facebook.thrift.payload.Reader> _frobnicate_EXCEPTION_READERS = java.util.Collections.emptyMap();
    private final java.util.Map<Short, com.facebook.thrift.payload.Reader> _ping_EXCEPTION_READERS = java.util.Collections.emptyMap();

    private com.facebook.thrift.payload.Writer _createfrobnicateWriter() {
      return oprot -> {
        try {

        } catch (Throwable _e) {
          throw reactor.core.Exceptions.propagate(_e);
        }
      };
    }

    private final com.facebook.thrift.payload.Reader _frobnicate_READER = Readers.i32Reader();

    public reactor.core.publisher.Mono<Integer> frobnicate() {
      return frobnicateWrapper( com.facebook.thrift.client.RpcOptions.EMPTY).map(_p -> _p.getData());
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<Integer> frobnicate(RpcOptions rpcOptions)  {
      return frobnicateWrapper( rpcOptions).map(_p -> _p.getData());
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<ResponseWrapper<Integer>> frobnicateWrapper(RpcOptions rpcOptions)  {
      return _rpcClient
        .subscriberContext(ctx -> ctx.put(STICKY_HASH_KEY, interactionId))
        .flatMap(_rpc -> {
          String interactionName = "MyInteractionFast.frobnicate";
          org.apache.thrift.RequestRpcMetadata.Builder _metadataBuilder = new org.apache.thrift.RequestRpcMetadata.Builder()
                  .setName(interactionName)
                  .setKind(org.apache.thrift.RpcKind.SINGLE_REQUEST_SINGLE_RESPONSE)
                  .setOtherMetadata(getHeaders(rpcOptions))
                  .setProtocol(_protocolId);

          if (_activeInteractions.contains(interactionId)) {
            _metadataBuilder.setInteractionId(interactionId);
          } else {
            _metadataBuilder.setInteractionCreate(
              new InteractionCreate.Builder()
                  .setInteractionId(interactionId)
                  .setInteractionName("MyInteractionFast")
                  .build());
            _metadataBuilder.setInteractionId(0L);
            _activeInteractions.add(interactionId);
          }

          org.apache.thrift.RequestRpcMetadata _metadata = _metadataBuilder.build();

          com.facebook.thrift.payload.ClientRequestPayload<Integer> _crp =
              com.facebook.thrift.payload.ClientRequestPayload.create(
                  "MyInteractionFast",
                  _createfrobnicateWriter(),
                  _frobnicate_READER,
                  _frobnicate_EXCEPTION_READERS_INT,
                  _metadata,
                  java.util.Collections.emptyMap());

          return _rpc
              .singleRequestSingleResponse(_crp, rpcOptions).doOnNext(_p -> {if(_p.getException() != null) throw com.facebook.thrift.util.ExceptionUtil.propagate(_p);});
        });
    }

    private com.facebook.thrift.payload.Writer _createpingWriter() {
      return oprot -> {
        try {

        } catch (Throwable _e) {
          throw reactor.core.Exceptions.propagate(_e);
        }
      };
    }

    private final com.facebook.thrift.payload.Reader _ping_READER = Readers.voidReader();

    public reactor.core.publisher.Mono<Void> ping() {
      return pingWrapper( com.facebook.thrift.client.RpcOptions.EMPTY).then();
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<Void> ping(RpcOptions rpcOptions)  {
      return pingWrapper( rpcOptions).then();
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<ResponseWrapper<Void>> pingWrapper(RpcOptions rpcOptions)  {
      return _rpcClient
        .subscriberContext(ctx -> ctx.put(STICKY_HASH_KEY, interactionId))
        .flatMap(_rpc -> {
          String interactionName = "MyInteractionFast.ping";
          org.apache.thrift.RequestRpcMetadata.Builder _metadataBuilder = new org.apache.thrift.RequestRpcMetadata.Builder()
                  .setName(interactionName)
                  .setKind(org.apache.thrift.RpcKind.SINGLE_REQUEST_NO_RESPONSE)
                  .setOtherMetadata(getHeaders(rpcOptions))
                  .setProtocol(_protocolId);

          if (_activeInteractions.contains(interactionId)) {
            _metadataBuilder.setInteractionId(interactionId);
          } else {
            _metadataBuilder.setInteractionCreate(
              new InteractionCreate.Builder()
                  .setInteractionId(interactionId)
                  .setInteractionName("MyInteractionFast")
                  .build());
            _metadataBuilder.setInteractionId(0L);
            _activeInteractions.add(interactionId);
          }

          org.apache.thrift.RequestRpcMetadata _metadata = _metadataBuilder.build();

          com.facebook.thrift.payload.ClientRequestPayload<Void> _crp =
              com.facebook.thrift.payload.ClientRequestPayload.create(
                  "MyInteractionFast",
                  _createpingWriter(),
                  _ping_READER,
                  _ping_EXCEPTION_READERS_INT,
                  _metadata,
                  java.util.Collections.emptyMap());

          return _rpc
              .singleRequestNoResponse(_crp, rpcOptions).thenReturn(ResponseWrapper.create(null, java.util.Collections.emptyMap(), java.util.Collections.emptyMap()));
        });
    }

    private com.facebook.thrift.payload.Writer _createtruthifyWriter() {
      return oprot -> {
        try {

        } catch (Throwable _e) {
          throw reactor.core.Exceptions.propagate(_e);
        }
      };
    }

    private final com.facebook.thrift.payload.Reader _truthify_READER = Readers.booleanReader();


    @java.lang.Override
    public reactor.core.publisher.Flux<com.facebook.thrift.client.ResponseWrapper<Boolean>> truthifyWrapper( final com.facebook.thrift.client.RpcOptions rpcOptions) {
      return _rpcClient
        .subscriberContext(ctx -> ctx.put(STICKY_HASH_KEY, interactionId))
        .flatMapMany(_rpc -> {
          String interactionName = "MyInteractionFast.truthify";
          org.apache.thrift.RequestRpcMetadata.Builder _metadataBuilder = new org.apache.thrift.RequestRpcMetadata.Builder()
                  .setName(interactionName)
                  .setKind(org.apache.thrift.RpcKind.SINGLE_REQUEST_STREAMING_RESPONSE)
                  .setOtherMetadata(getHeaders(rpcOptions))
                  .setProtocol(_protocolId);

          if (_activeInteractions.contains(interactionId)) {
            _metadataBuilder.setInteractionId(interactionId);
          } else {
            _metadataBuilder.setInteractionCreate(
              new InteractionCreate.Builder()
                  .setInteractionId(interactionId)
                  .setInteractionName("MyInteractionFast")
                  .build());
            _metadataBuilder.setInteractionId(0L);
            _activeInteractions.add(interactionId);
          }


          com.facebook.thrift.payload.ClientRequestPayload<Boolean> _crp =
              com.facebook.thrift.payload.ClientRequestPayload.create(
                  "MyInteractionFast",
                  _createtruthifyWriter(),
                  _truthify_READER,
                  _truthify_EXCEPTION_READERS_INT,
                  _truthify_STREAM_EXCEPTION_READERS_INT,
                  _metadataBuilder.build(),
                  java.util.Collections.emptyMap());

          return _rpc
              .singleRequestStreamingResponse(_crp, rpcOptions)
              .transform(com.facebook.thrift.util.FluxPublishingTransformer.getInstance())
              .doOnNext(_p -> {if(_p.getException() != null) throw reactor.core.Exceptions.propagate(_p.getException());})
              .filter((_p) -> ((com.facebook.thrift.model.StreamResponse)_p.getData()).isSetData())
              .map(_p -> ResponseWrapper.create(((com.facebook.thrift.model.StreamResponse<Void, Boolean>)_p.getData()).getData(), _p.getHeaders(), _p.getBinaryHeaders()));
        });
    }

    @java.lang.Override
    public reactor.core.publisher.Flux<Boolean> truthify( final com.facebook.thrift.client.RpcOptions rpcOptions) {
        return truthifyWrapper( rpcOptions).map(_p -> _p.getData());
    }

    @java.lang.Override
    public reactor.core.publisher.Flux<Boolean> truthify() {
      return truthify( com.facebook.thrift.client.RpcOptions.EMPTY);
    }

    @java.lang.Override
    public void dispose() {
      com.facebook.thrift.client.ThriftClientStatsHolder.getThriftClientStats().interactionDisposed("MyInteractionFast");
      _activeInteractions.remove(interactionId);
      _rpcClient
        .subscriberContext(ctx -> ctx.put(STICKY_HASH_KEY, interactionId))
        .flatMap(_rpc -> {
          InteractionTerminate term = new InteractionTerminate.Builder().setInteractionId(interactionId).build();
          ClientPushMetadata metadata = ClientPushMetadata.fromInteractionTerminate(term);
          return _rpc.metadataPush(metadata, com.facebook.thrift.client.RpcOptions.EMPTY);
        }).subscribe();
    }
  }

  public MyInteractionFast createMyInteractionFast() {
      return new MyInteractionFastImpl(_interactionCounter.incrementAndGet());
  }

  public class SerialInteractionImpl implements SerialInteraction {
    private final long interactionId;

    SerialInteractionImpl(long interactionId) {
      this.interactionId = interactionId;
      com.facebook.thrift.client.ThriftClientStatsHolder.getThriftClientStats().interactionCreated("SerialInteraction");
    }

    private final java.util.Map<Short, com.facebook.thrift.payload.Reader> _frobnicate_EXCEPTION_READERS = java.util.Collections.emptyMap();

    private com.facebook.thrift.payload.Writer _createfrobnicateWriter() {
      return oprot -> {
        try {

        } catch (Throwable _e) {
          throw reactor.core.Exceptions.propagate(_e);
        }
      };
    }

    private final com.facebook.thrift.payload.Reader _frobnicate_READER = Readers.voidReader();

    public reactor.core.publisher.Mono<Void> frobnicate() {
      return frobnicateWrapper( com.facebook.thrift.client.RpcOptions.EMPTY).then();
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<Void> frobnicate(RpcOptions rpcOptions)  {
      return frobnicateWrapper( rpcOptions).then();
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<ResponseWrapper<Void>> frobnicateWrapper(RpcOptions rpcOptions)  {
      return _rpcClient
        .subscriberContext(ctx -> ctx.put(STICKY_HASH_KEY, interactionId))
        .flatMap(_rpc -> {
          String interactionName = "SerialInteraction.frobnicate";
          org.apache.thrift.RequestRpcMetadata.Builder _metadataBuilder = new org.apache.thrift.RequestRpcMetadata.Builder()
                  .setName(interactionName)
                  .setKind(org.apache.thrift.RpcKind.SINGLE_REQUEST_SINGLE_RESPONSE)
                  .setOtherMetadata(getHeaders(rpcOptions))
                  .setProtocol(_protocolId);

          if (_activeInteractions.contains(interactionId)) {
            _metadataBuilder.setInteractionId(interactionId);
          } else {
            _metadataBuilder.setInteractionCreate(
              new InteractionCreate.Builder()
                  .setInteractionId(interactionId)
                  .setInteractionName("SerialInteraction")
                  .build());
            _metadataBuilder.setInteractionId(0L);
            _activeInteractions.add(interactionId);
          }

          org.apache.thrift.RequestRpcMetadata _metadata = _metadataBuilder.build();

          com.facebook.thrift.payload.ClientRequestPayload<Void> _crp =
              com.facebook.thrift.payload.ClientRequestPayload.create(
                  "SerialInteraction",
                  _createfrobnicateWriter(),
                  _frobnicate_READER,
                  _frobnicate_EXCEPTION_READERS_INT,
                  _metadata,
                  java.util.Collections.emptyMap());

          return _rpc
              .singleRequestSingleResponse(_crp, rpcOptions).doOnNext(_p -> {if(_p.getException() != null) throw com.facebook.thrift.util.ExceptionUtil.propagate(_p);});
        });
    }

    @java.lang.Override
    public void dispose() {
      com.facebook.thrift.client.ThriftClientStatsHolder.getThriftClientStats().interactionDisposed("SerialInteraction");
      _activeInteractions.remove(interactionId);
      _rpcClient
        .subscriberContext(ctx -> ctx.put(STICKY_HASH_KEY, interactionId))
        .flatMap(_rpc -> {
          InteractionTerminate term = new InteractionTerminate.Builder().setInteractionId(interactionId).build();
          ClientPushMetadata metadata = ClientPushMetadata.fromInteractionTerminate(term);
          return _rpc.metadataPush(metadata, com.facebook.thrift.client.RpcOptions.EMPTY);
        }).subscribe();
    }
  }

  public SerialInteraction createSerialInteraction() {
      return new SerialInteractionImpl(_interactionCounter.incrementAndGet());
  }

  private Map<String, String> getHeaders(com.facebook.thrift.client.RpcOptions rpcOptions) {
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
