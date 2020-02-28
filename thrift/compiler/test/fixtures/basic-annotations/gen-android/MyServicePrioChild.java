/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;
import java.util.BitSet;
import java.util.Arrays;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.facebook.thrift.*;
import com.facebook.thrift.async.*;
import com.facebook.thrift.meta_data.*;
import com.facebook.thrift.server.*;
import com.facebook.thrift.transport.*;
import com.facebook.thrift.protocol.*;

@SuppressWarnings({ "unused", "serial" })
public class MyServicePrioChild {

  public interface Iface extends MyServicePrioParent.Iface {

    public void pang() throws TException;

  }

  public interface AsyncIface extends MyServicePrioParent.AsyncIface {

    public void pang(AsyncMethodCallback resultHandler) throws TException;

  }

  public static class Client extends MyServicePrioParent.Client implements Iface, TClientIf {
    public Client(TProtocol prot)
    {
      this(prot, prot);
    }

    public Client(TProtocol iprot, TProtocol oprot)
    {
      super(iprot, oprot);
    }

    public void pang() throws TException
    {
      ContextStack ctx = getContextStack("MyServicePrioChild.pang", null);
      this.setContextStack(ctx);
      send_pang();
      recv_pang();
    }

    public void send_pang() throws TException
    {
      ContextStack ctx = this.getContextStack();
      super.preWrite(ctx, "MyServicePrioChild.pang", null);
      oprot_.writeMessageBegin(new TMessage("pang", TMessageType.CALL, seqid_));
      pang_args args = new pang_args();
      args.write(oprot_);
      oprot_.writeMessageEnd();
      oprot_.getTransport().flush();
      super.postWrite(ctx, "MyServicePrioChild.pang", args);
      return;
    }

    public void recv_pang() throws TException
    {
      ContextStack ctx = super.getContextStack();
      long bytes;
      TMessageType mtype;
      super.preRead(ctx, "MyServicePrioChild.pang");
      TMessage msg = iprot_.readMessageBegin();
      if (msg.type == TMessageType.EXCEPTION) {
        TApplicationException x = TApplicationException.read(iprot_);
        iprot_.readMessageEnd();
        throw x;
      }
      pang_result result = new pang_result();
      result.read(iprot_);
      iprot_.readMessageEnd();
      super.postRead(ctx, "MyServicePrioChild.pang", result);

      return;
    }

  }
  public static class AsyncClient extends MyServicePrioParent.AsyncClient implements AsyncIface {
    public static class Factory implements TAsyncClientFactory<AsyncClient> {
      private TAsyncClientManager clientManager;
      private TProtocolFactory protocolFactory;
      public Factory(TAsyncClientManager clientManager, TProtocolFactory protocolFactory) {
        this.clientManager = clientManager;
        this.protocolFactory = protocolFactory;
      }
      public AsyncClient getAsyncClient(TNonblockingTransport transport) {
        return new AsyncClient(protocolFactory, clientManager, transport);
      }
    }

    public AsyncClient(TProtocolFactory protocolFactory, TAsyncClientManager clientManager, TNonblockingTransport transport) {
      super(protocolFactory, clientManager, transport);
    }

    public void pang(AsyncMethodCallback resultHandler58) throws TException {
      checkReady();
      pang_call method_call = new pang_call(resultHandler58, this, ___protocolFactory, ___transport);
      this.___currentMethod = method_call;
      ___manager.call(method_call);
    }

    public static class pang_call extends TAsyncMethodCall {
      public pang_call(AsyncMethodCallback resultHandler59, TAsyncClient client55, TProtocolFactory protocolFactory56, TNonblockingTransport transport57) throws TException {
        super(client55, protocolFactory56, transport57, resultHandler59, false);
      }

      public void write_args(TProtocol prot) throws TException {
        prot.writeMessageBegin(new TMessage("pang", TMessageType.CALL, 0));
        pang_args args = new pang_args();
        args.write(prot);
        prot.writeMessageEnd();
      }

      public void getResult() throws TException {
        if (getState() != State.RESPONSE_READ) {
          throw new IllegalStateException("Method call not finished!");
        }
        TMemoryInputTransport memoryTransport = new TMemoryInputTransport(getFrameBuffer().array());
        TProtocol prot = super.client.getProtocolFactory().getProtocol(memoryTransport);
        (new Client(prot)).recv_pang();
      }
    }

  }

  public static class Processor extends MyServicePrioParent.Processor implements TProcessor {
    private static final Logger LOGGER = LoggerFactory.getLogger(Processor.class.getName());
    public Processor(Iface iface)
    {
      super(iface);
      iface_ = iface;
      processMap_.put("pang", new pang());
    }

    private Iface iface_;

    public boolean process(TProtocol iprot, TProtocol oprot, TConnectionContext server_ctx) throws TException
    {
      TMessage msg = iprot.readMessageBegin();
      ProcessFunction fn = processMap_.get(msg.name);
      if (fn == null) {
        TProtocolUtil.skip(iprot, TType.STRUCT);
        iprot.readMessageEnd();
        TApplicationException x = new TApplicationException(TApplicationException.UNKNOWN_METHOD, "Invalid method name: '"+msg.name+"'");
        oprot.writeMessageBegin(new TMessage(msg.name, TMessageType.EXCEPTION, msg.seqid));
        x.write(oprot);
        oprot.writeMessageEnd();
        oprot.getTransport().flush();
        return true;
      }
      fn.process(msg.seqid, iprot, oprot, server_ctx);
      return true;
    }

    private class pang implements ProcessFunction {
      public void process(int seqid, TProtocol iprot, TProtocol oprot, TConnectionContext server_ctx) throws TException
      {
        Object handler_ctx = event_handler_.getContext("MyServicePrioChild.pang", server_ctx);
        pang_args args = new pang_args();
        event_handler_.preRead(handler_ctx, "MyServicePrioChild.pang");
        args.read(iprot);
        iprot.readMessageEnd();
        event_handler_.postRead(handler_ctx, "MyServicePrioChild.pang", args);
        pang_result result = new pang_result();
        iface_.pang();
        event_handler_.preWrite(handler_ctx, "MyServicePrioChild.pang", result);
        oprot.writeMessageBegin(new TMessage("pang", TMessageType.REPLY, seqid));
        result.write(oprot);
        oprot.writeMessageEnd();
        oprot.getTransport().flush();
        event_handler_.postWrite(handler_ctx, "MyServicePrioChild.pang", result);
      }

    }

  }

  public static class pang_args implements TBase, java.io.Serializable, Cloneable   {
    private static final TStruct STRUCT_DESC = new TStruct("pang_args");


    public pang_args() {
    }

    /**
     * Performs a deep copy on <i>other</i>.
     */
    public pang_args(pang_args other) {
    }

    public pang_args deepCopy() {
      return new pang_args(this);
    }

    @Override
    public boolean equals(Object that) {
      if (that == null)
        return false;
      if (that instanceof pang_args)
        return this.equals((pang_args)that);
      return false;
    }

    public boolean equals(pang_args that) {
      if (that == null)
        return false;
      if (this == that)
        return true;

      return true;
    }

    @Override
    public int hashCode() {
      return Arrays.deepHashCode(new Object[] {});
    }

    // This is required to satisfy the TBase interface, but can't be implemented on immutable struture.
    public void read(TProtocol iprot) throws TException {
      throw new TException("unimplemented in android immutable structure");
    }

    public static pang_args deserialize(TProtocol iprot) throws TException {
      TField __field;
      iprot.readStructBegin();
      while (true)
      {
        __field = iprot.readFieldBegin();
        if (__field.type == TType.STOP) { 
          break;
        }
        switch (__field.id)
        {
          default:
            TProtocolUtil.skip(iprot, __field.type);
            break;
        }
        iprot.readFieldEnd();
      }
      iprot.readStructEnd();

      pang_args _that;
      _that = new pang_args(
      );
      _that.validate();
      return _that;
    }

    public void write(TProtocol oprot) throws TException {
      validate();

      oprot.writeStructBegin(STRUCT_DESC);
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }

    @Override
    public String toString() {
      return toString(1, true);
    }

    @Override
    public String toString(int indent, boolean prettyPrint) {
      return TBaseHelper.toStringHelper(this, indent, prettyPrint);
    }

    public void validate() throws TException {
      // check for required fields
    }

  }

  public static class pang_result implements TBase, java.io.Serializable, Cloneable   {
    private static final TStruct STRUCT_DESC = new TStruct("pang_result");


    public pang_result() {
    }

    /**
     * Performs a deep copy on <i>other</i>.
     */
    public pang_result(pang_result other) {
    }

    public pang_result deepCopy() {
      return new pang_result(this);
    }

    @Override
    public boolean equals(Object that) {
      if (that == null)
        return false;
      if (that instanceof pang_result)
        return this.equals((pang_result)that);
      return false;
    }

    public boolean equals(pang_result that) {
      if (that == null)
        return false;
      if (this == that)
        return true;

      return true;
    }

    @Override
    public int hashCode() {
      return Arrays.deepHashCode(new Object[] {});
    }

    // This is required to satisfy the TBase interface, but can't be implemented on immutable struture.
    public void read(TProtocol iprot) throws TException {
      throw new TException("unimplemented in android immutable structure");
    }

    public static pang_result deserialize(TProtocol iprot) throws TException {
      TField __field;
      iprot.readStructBegin();
      while (true)
      {
        __field = iprot.readFieldBegin();
        if (__field.type == TType.STOP) { 
          break;
        }
        switch (__field.id)
        {
          default:
            TProtocolUtil.skip(iprot, __field.type);
            break;
        }
        iprot.readFieldEnd();
      }
      iprot.readStructEnd();

      pang_result _that;
      _that = new pang_result(
      );
      _that.validate();
      return _that;
    }

    public void write(TProtocol oprot) throws TException {
      oprot.writeStructBegin(STRUCT_DESC);

      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }

    @Override
    public String toString() {
      return toString(1, true);
    }

    @Override
    public String toString(int indent, boolean prettyPrint) {
      return TBaseHelper.toStringHelper(this, indent, prettyPrint);
    }

    public void validate() throws TException {
      // check for required fields
    }

  }

}
