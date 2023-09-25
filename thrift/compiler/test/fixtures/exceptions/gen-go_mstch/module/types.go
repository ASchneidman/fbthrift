// @generated by Thrift for [[[ program path ]]]
// This file is probably not the place you want to edit!

package module // [[[ program thrift source path ]]]

import (
    "fmt"
    "strings"

    thrift "github.com/facebook/fbthrift/thrift/lib/go/thrift"
)

// (needed to ensure safety because of naive import list construction)
var _ = fmt.Printf
var _ = thrift.ZERO
var _ = strings.Split


type Fiery struct {
    Message string `thrift:"message,1,required" json:"message" db:"message"`
}
// Compile time interface enforcer
var _ thrift.Struct = &Fiery{}

func NewFiery() *Fiery {
    return (&Fiery{}).
        SetMessageNonCompat("")
}

func (x *Fiery) GetMessageNonCompat() string {
    return x.Message
}

func (x *Fiery) GetMessage() string {
    return x.Message
}

func (x *Fiery) SetMessageNonCompat(value string) *Fiery {
    x.Message = value
    return x
}

func (x *Fiery) SetMessage(value string) *Fiery {
    x.Message = value
    return x
}

func (x *Fiery) writeField1(p thrift.Protocol) error {  // Message
    if err := p.WriteFieldBegin("message", thrift.STRING, 1); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.GetMessageNonCompat()
    if err := p.WriteString(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *Fiery) readField1(p thrift.Protocol) error {  // Message
    result, err := p.ReadString()
if err != nil {
    return err
}

    x.SetMessageNonCompat(result)
    return nil
}

func (x *Fiery) toString1() string {  // Message
    return fmt.Sprintf("%v", x.GetMessageNonCompat())
}


// Deprecated: Use Fiery.Set* methods instead or set the fields directly.
type FieryBuilder struct {
    obj *Fiery
}

func NewFieryBuilder() *FieryBuilder {
    return &FieryBuilder{
        obj: NewFiery(),
    }
}

func (x *FieryBuilder) Message(value string) *FieryBuilder {
    x.obj.Message = value
    return x
}

func (x *FieryBuilder) Emit() *Fiery {
    var objCopy Fiery = *x.obj
    return &objCopy
}

func (x *Fiery) Write(p thrift.Protocol) error {
    if err := p.WriteStructBegin("Fiery"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField1(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *Fiery) Read(p thrift.Protocol) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        switch id {
        case 1:  // message
            expectedType := thrift.Type(thrift.STRING)
            if wireType == expectedType {
                if err := x.readField1(p); err != nil {
                   return err
                }
            } else {
                if err := p.Skip(wireType); err != nil {
                    return err
                }
            }
        default:
            if err := p.Skip(wireType); err != nil {
                return err
            }
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *Fiery) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("Fiery({")
    sb.WriteString(fmt.Sprintf("Message:%s", x.toString1()))
    sb.WriteString("})")

    return sb.String()
}
func (x *Fiery) Error() string {
    return x.String()
}

type Serious struct {
    Sonnet *string `thrift:"sonnet,1,optional" json:"sonnet,omitempty" db:"sonnet"`
}
// Compile time interface enforcer
var _ thrift.Struct = &Serious{}

func NewSerious() *Serious {
    return (&Serious{})
}

func (x *Serious) GetSonnetNonCompat() *string {
    return x.Sonnet
}

func (x *Serious) GetSonnet() string {
    if !x.IsSetSonnet() {
        return ""
    }

    return *x.Sonnet
}

func (x *Serious) SetSonnetNonCompat(value string) *Serious {
    x.Sonnet = &value
    return x
}

func (x *Serious) SetSonnet(value *string) *Serious {
    x.Sonnet = value
    return x
}

func (x *Serious) IsSetSonnet() bool {
    return x != nil && x.Sonnet != nil
}

func (x *Serious) writeField1(p thrift.Protocol) error {  // Sonnet
    if !x.IsSetSonnet() {
        return nil
    }

    if err := p.WriteFieldBegin("sonnet", thrift.STRING, 1); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := *x.GetSonnetNonCompat()
    if err := p.WriteString(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *Serious) readField1(p thrift.Protocol) error {  // Sonnet
    result, err := p.ReadString()
if err != nil {
    return err
}

    x.SetSonnetNonCompat(result)
    return nil
}

func (x *Serious) toString1() string {  // Sonnet
    if x.IsSetSonnet() {
        return fmt.Sprintf("%v", *x.GetSonnetNonCompat())
    }
    return fmt.Sprintf("%v", x.GetSonnetNonCompat())
}

// Deprecated: Use NewSerious().GetSonnet() instead.
var Serious_Sonnet_DEFAULT = NewSerious().GetSonnet()


// Deprecated: Use Serious.Set* methods instead or set the fields directly.
type SeriousBuilder struct {
    obj *Serious
}

func NewSeriousBuilder() *SeriousBuilder {
    return &SeriousBuilder{
        obj: NewSerious(),
    }
}

func (x *SeriousBuilder) Sonnet(value *string) *SeriousBuilder {
    x.obj.Sonnet = value
    return x
}

func (x *SeriousBuilder) Emit() *Serious {
    var objCopy Serious = *x.obj
    return &objCopy
}

func (x *Serious) Write(p thrift.Protocol) error {
    if err := p.WriteStructBegin("Serious"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField1(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *Serious) Read(p thrift.Protocol) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        switch id {
        case 1:  // sonnet
            expectedType := thrift.Type(thrift.STRING)
            if wireType == expectedType {
                if err := x.readField1(p); err != nil {
                   return err
                }
            } else {
                if err := p.Skip(wireType); err != nil {
                    return err
                }
            }
        default:
            if err := p.Skip(wireType); err != nil {
                return err
            }
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *Serious) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("Serious({")
    sb.WriteString(fmt.Sprintf("Sonnet:%s", x.toString1()))
    sb.WriteString("})")

    return sb.String()
}
func (x *Serious) Error() string {
    return x.String()
}

type ComplexFieldNames struct {
    ErrorMessage string `thrift:"error_message,1" json:"error_message" db:"error_message"`
    InternalErrorMessage string `thrift:"internal_error_message,2" json:"internal_error_message" db:"internal_error_message"`
}
// Compile time interface enforcer
var _ thrift.Struct = &ComplexFieldNames{}

func NewComplexFieldNames() *ComplexFieldNames {
    return (&ComplexFieldNames{}).
        SetErrorMessageNonCompat("").
        SetInternalErrorMessageNonCompat("")
}

func (x *ComplexFieldNames) GetErrorMessageNonCompat() string {
    return x.ErrorMessage
}

func (x *ComplexFieldNames) GetErrorMessage() string {
    return x.ErrorMessage
}

func (x *ComplexFieldNames) GetInternalErrorMessageNonCompat() string {
    return x.InternalErrorMessage
}

func (x *ComplexFieldNames) GetInternalErrorMessage() string {
    return x.InternalErrorMessage
}

func (x *ComplexFieldNames) SetErrorMessageNonCompat(value string) *ComplexFieldNames {
    x.ErrorMessage = value
    return x
}

func (x *ComplexFieldNames) SetErrorMessage(value string) *ComplexFieldNames {
    x.ErrorMessage = value
    return x
}

func (x *ComplexFieldNames) SetInternalErrorMessageNonCompat(value string) *ComplexFieldNames {
    x.InternalErrorMessage = value
    return x
}

func (x *ComplexFieldNames) SetInternalErrorMessage(value string) *ComplexFieldNames {
    x.InternalErrorMessage = value
    return x
}

func (x *ComplexFieldNames) writeField1(p thrift.Protocol) error {  // ErrorMessage
    if err := p.WriteFieldBegin("error_message", thrift.STRING, 1); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.GetErrorMessageNonCompat()
    if err := p.WriteString(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *ComplexFieldNames) writeField2(p thrift.Protocol) error {  // InternalErrorMessage
    if err := p.WriteFieldBegin("internal_error_message", thrift.STRING, 2); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.GetInternalErrorMessageNonCompat()
    if err := p.WriteString(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *ComplexFieldNames) readField1(p thrift.Protocol) error {  // ErrorMessage
    result, err := p.ReadString()
if err != nil {
    return err
}

    x.SetErrorMessageNonCompat(result)
    return nil
}

func (x *ComplexFieldNames) readField2(p thrift.Protocol) error {  // InternalErrorMessage
    result, err := p.ReadString()
if err != nil {
    return err
}

    x.SetInternalErrorMessageNonCompat(result)
    return nil
}

func (x *ComplexFieldNames) toString1() string {  // ErrorMessage
    return fmt.Sprintf("%v", x.GetErrorMessageNonCompat())
}

func (x *ComplexFieldNames) toString2() string {  // InternalErrorMessage
    return fmt.Sprintf("%v", x.GetInternalErrorMessageNonCompat())
}


// Deprecated: Use ComplexFieldNames.Set* methods instead or set the fields directly.
type ComplexFieldNamesBuilder struct {
    obj *ComplexFieldNames
}

func NewComplexFieldNamesBuilder() *ComplexFieldNamesBuilder {
    return &ComplexFieldNamesBuilder{
        obj: NewComplexFieldNames(),
    }
}

func (x *ComplexFieldNamesBuilder) ErrorMessage(value string) *ComplexFieldNamesBuilder {
    x.obj.ErrorMessage = value
    return x
}

func (x *ComplexFieldNamesBuilder) InternalErrorMessage(value string) *ComplexFieldNamesBuilder {
    x.obj.InternalErrorMessage = value
    return x
}

func (x *ComplexFieldNamesBuilder) Emit() *ComplexFieldNames {
    var objCopy ComplexFieldNames = *x.obj
    return &objCopy
}

func (x *ComplexFieldNames) Write(p thrift.Protocol) error {
    if err := p.WriteStructBegin("ComplexFieldNames"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField1(p); err != nil {
        return err
    }

    if err := x.writeField2(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *ComplexFieldNames) Read(p thrift.Protocol) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        switch id {
        case 1:  // error_message
            expectedType := thrift.Type(thrift.STRING)
            if wireType == expectedType {
                if err := x.readField1(p); err != nil {
                   return err
                }
            } else {
                if err := p.Skip(wireType); err != nil {
                    return err
                }
            }
        case 2:  // internal_error_message
            expectedType := thrift.Type(thrift.STRING)
            if wireType == expectedType {
                if err := x.readField2(p); err != nil {
                   return err
                }
            } else {
                if err := p.Skip(wireType); err != nil {
                    return err
                }
            }
        default:
            if err := p.Skip(wireType); err != nil {
                return err
            }
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *ComplexFieldNames) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("ComplexFieldNames({")
    sb.WriteString(fmt.Sprintf("ErrorMessage:%s ", x.toString1()))
    sb.WriteString(fmt.Sprintf("InternalErrorMessage:%s", x.toString2()))
    sb.WriteString("})")

    return sb.String()
}
func (x *ComplexFieldNames) Error() string {
    return x.String()
}

type CustomFieldNames struct {
    ErrorMessage string `thrift:"error_message,1" json:"error_message" db:"error_message"`
    InternalErrorMessage string `thrift:"internal_error_message,2" json:"internal_error_message" db:"internal_error_message"`
}
// Compile time interface enforcer
var _ thrift.Struct = &CustomFieldNames{}

func NewCustomFieldNames() *CustomFieldNames {
    return (&CustomFieldNames{}).
        SetErrorMessageNonCompat("").
        SetInternalErrorMessageNonCompat("")
}

func (x *CustomFieldNames) GetErrorMessageNonCompat() string {
    return x.ErrorMessage
}

func (x *CustomFieldNames) GetErrorMessage() string {
    return x.ErrorMessage
}

func (x *CustomFieldNames) GetInternalErrorMessageNonCompat() string {
    return x.InternalErrorMessage
}

func (x *CustomFieldNames) GetInternalErrorMessage() string {
    return x.InternalErrorMessage
}

func (x *CustomFieldNames) SetErrorMessageNonCompat(value string) *CustomFieldNames {
    x.ErrorMessage = value
    return x
}

func (x *CustomFieldNames) SetErrorMessage(value string) *CustomFieldNames {
    x.ErrorMessage = value
    return x
}

func (x *CustomFieldNames) SetInternalErrorMessageNonCompat(value string) *CustomFieldNames {
    x.InternalErrorMessage = value
    return x
}

func (x *CustomFieldNames) SetInternalErrorMessage(value string) *CustomFieldNames {
    x.InternalErrorMessage = value
    return x
}

func (x *CustomFieldNames) writeField1(p thrift.Protocol) error {  // ErrorMessage
    if err := p.WriteFieldBegin("error_message", thrift.STRING, 1); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.GetErrorMessageNonCompat()
    if err := p.WriteString(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *CustomFieldNames) writeField2(p thrift.Protocol) error {  // InternalErrorMessage
    if err := p.WriteFieldBegin("internal_error_message", thrift.STRING, 2); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.GetInternalErrorMessageNonCompat()
    if err := p.WriteString(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *CustomFieldNames) readField1(p thrift.Protocol) error {  // ErrorMessage
    result, err := p.ReadString()
if err != nil {
    return err
}

    x.SetErrorMessageNonCompat(result)
    return nil
}

func (x *CustomFieldNames) readField2(p thrift.Protocol) error {  // InternalErrorMessage
    result, err := p.ReadString()
if err != nil {
    return err
}

    x.SetInternalErrorMessageNonCompat(result)
    return nil
}

func (x *CustomFieldNames) toString1() string {  // ErrorMessage
    return fmt.Sprintf("%v", x.GetErrorMessageNonCompat())
}

func (x *CustomFieldNames) toString2() string {  // InternalErrorMessage
    return fmt.Sprintf("%v", x.GetInternalErrorMessageNonCompat())
}


// Deprecated: Use CustomFieldNames.Set* methods instead or set the fields directly.
type CustomFieldNamesBuilder struct {
    obj *CustomFieldNames
}

func NewCustomFieldNamesBuilder() *CustomFieldNamesBuilder {
    return &CustomFieldNamesBuilder{
        obj: NewCustomFieldNames(),
    }
}

func (x *CustomFieldNamesBuilder) ErrorMessage(value string) *CustomFieldNamesBuilder {
    x.obj.ErrorMessage = value
    return x
}

func (x *CustomFieldNamesBuilder) InternalErrorMessage(value string) *CustomFieldNamesBuilder {
    x.obj.InternalErrorMessage = value
    return x
}

func (x *CustomFieldNamesBuilder) Emit() *CustomFieldNames {
    var objCopy CustomFieldNames = *x.obj
    return &objCopy
}

func (x *CustomFieldNames) Write(p thrift.Protocol) error {
    if err := p.WriteStructBegin("CustomFieldNames"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField1(p); err != nil {
        return err
    }

    if err := x.writeField2(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *CustomFieldNames) Read(p thrift.Protocol) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        switch id {
        case 1:  // error_message
            expectedType := thrift.Type(thrift.STRING)
            if wireType == expectedType {
                if err := x.readField1(p); err != nil {
                   return err
                }
            } else {
                if err := p.Skip(wireType); err != nil {
                    return err
                }
            }
        case 2:  // internal_error_message
            expectedType := thrift.Type(thrift.STRING)
            if wireType == expectedType {
                if err := x.readField2(p); err != nil {
                   return err
                }
            } else {
                if err := p.Skip(wireType); err != nil {
                    return err
                }
            }
        default:
            if err := p.Skip(wireType); err != nil {
                return err
            }
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *CustomFieldNames) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("CustomFieldNames({")
    sb.WriteString(fmt.Sprintf("ErrorMessage:%s ", x.toString1()))
    sb.WriteString(fmt.Sprintf("InternalErrorMessage:%s", x.toString2()))
    sb.WriteString("})")

    return sb.String()
}
func (x *CustomFieldNames) Error() string {
    return x.String()
}

type ExceptionWithPrimitiveField struct {
    Message string `thrift:"message,1" json:"message" db:"message"`
    ErrorCode int32 `thrift:"error_code,2" json:"error_code" db:"error_code"`
}
// Compile time interface enforcer
var _ thrift.Struct = &ExceptionWithPrimitiveField{}

func NewExceptionWithPrimitiveField() *ExceptionWithPrimitiveField {
    return (&ExceptionWithPrimitiveField{}).
        SetMessageNonCompat("").
        SetErrorCodeNonCompat(0)
}

func (x *ExceptionWithPrimitiveField) GetMessageNonCompat() string {
    return x.Message
}

func (x *ExceptionWithPrimitiveField) GetMessage() string {
    return x.Message
}

func (x *ExceptionWithPrimitiveField) GetErrorCodeNonCompat() int32 {
    return x.ErrorCode
}

func (x *ExceptionWithPrimitiveField) GetErrorCode() int32 {
    return x.ErrorCode
}

func (x *ExceptionWithPrimitiveField) SetMessageNonCompat(value string) *ExceptionWithPrimitiveField {
    x.Message = value
    return x
}

func (x *ExceptionWithPrimitiveField) SetMessage(value string) *ExceptionWithPrimitiveField {
    x.Message = value
    return x
}

func (x *ExceptionWithPrimitiveField) SetErrorCodeNonCompat(value int32) *ExceptionWithPrimitiveField {
    x.ErrorCode = value
    return x
}

func (x *ExceptionWithPrimitiveField) SetErrorCode(value int32) *ExceptionWithPrimitiveField {
    x.ErrorCode = value
    return x
}

func (x *ExceptionWithPrimitiveField) writeField1(p thrift.Protocol) error {  // Message
    if err := p.WriteFieldBegin("message", thrift.STRING, 1); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.GetMessageNonCompat()
    if err := p.WriteString(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *ExceptionWithPrimitiveField) writeField2(p thrift.Protocol) error {  // ErrorCode
    if err := p.WriteFieldBegin("error_code", thrift.I32, 2); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.GetErrorCodeNonCompat()
    if err := p.WriteI32(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *ExceptionWithPrimitiveField) readField1(p thrift.Protocol) error {  // Message
    result, err := p.ReadString()
if err != nil {
    return err
}

    x.SetMessageNonCompat(result)
    return nil
}

func (x *ExceptionWithPrimitiveField) readField2(p thrift.Protocol) error {  // ErrorCode
    result, err := p.ReadI32()
if err != nil {
    return err
}

    x.SetErrorCodeNonCompat(result)
    return nil
}

func (x *ExceptionWithPrimitiveField) toString1() string {  // Message
    return fmt.Sprintf("%v", x.GetMessageNonCompat())
}

func (x *ExceptionWithPrimitiveField) toString2() string {  // ErrorCode
    return fmt.Sprintf("%v", x.GetErrorCodeNonCompat())
}


// Deprecated: Use ExceptionWithPrimitiveField.Set* methods instead or set the fields directly.
type ExceptionWithPrimitiveFieldBuilder struct {
    obj *ExceptionWithPrimitiveField
}

func NewExceptionWithPrimitiveFieldBuilder() *ExceptionWithPrimitiveFieldBuilder {
    return &ExceptionWithPrimitiveFieldBuilder{
        obj: NewExceptionWithPrimitiveField(),
    }
}

func (x *ExceptionWithPrimitiveFieldBuilder) Message(value string) *ExceptionWithPrimitiveFieldBuilder {
    x.obj.Message = value
    return x
}

func (x *ExceptionWithPrimitiveFieldBuilder) ErrorCode(value int32) *ExceptionWithPrimitiveFieldBuilder {
    x.obj.ErrorCode = value
    return x
}

func (x *ExceptionWithPrimitiveFieldBuilder) Emit() *ExceptionWithPrimitiveField {
    var objCopy ExceptionWithPrimitiveField = *x.obj
    return &objCopy
}

func (x *ExceptionWithPrimitiveField) Write(p thrift.Protocol) error {
    if err := p.WriteStructBegin("ExceptionWithPrimitiveField"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField1(p); err != nil {
        return err
    }

    if err := x.writeField2(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *ExceptionWithPrimitiveField) Read(p thrift.Protocol) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        switch id {
        case 1:  // message
            expectedType := thrift.Type(thrift.STRING)
            if wireType == expectedType {
                if err := x.readField1(p); err != nil {
                   return err
                }
            } else {
                if err := p.Skip(wireType); err != nil {
                    return err
                }
            }
        case 2:  // error_code
            expectedType := thrift.Type(thrift.I32)
            if wireType == expectedType {
                if err := x.readField2(p); err != nil {
                   return err
                }
            } else {
                if err := p.Skip(wireType); err != nil {
                    return err
                }
            }
        default:
            if err := p.Skip(wireType); err != nil {
                return err
            }
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *ExceptionWithPrimitiveField) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("ExceptionWithPrimitiveField({")
    sb.WriteString(fmt.Sprintf("Message:%s ", x.toString1()))
    sb.WriteString(fmt.Sprintf("ErrorCode:%s", x.toString2()))
    sb.WriteString("})")

    return sb.String()
}
func (x *ExceptionWithPrimitiveField) Error() string {
    return x.String()
}

type ExceptionWithStructuredAnnotation struct {
    MessageField string `thrift:"message_field,1" json:"message_field" db:"message_field"`
    ErrorCode int32 `thrift:"error_code,2" json:"error_code" db:"error_code"`
}
// Compile time interface enforcer
var _ thrift.Struct = &ExceptionWithStructuredAnnotation{}

func NewExceptionWithStructuredAnnotation() *ExceptionWithStructuredAnnotation {
    return (&ExceptionWithStructuredAnnotation{}).
        SetMessageFieldNonCompat("").
        SetErrorCodeNonCompat(0)
}

func (x *ExceptionWithStructuredAnnotation) GetMessageFieldNonCompat() string {
    return x.MessageField
}

func (x *ExceptionWithStructuredAnnotation) GetMessageField() string {
    return x.MessageField
}

func (x *ExceptionWithStructuredAnnotation) GetErrorCodeNonCompat() int32 {
    return x.ErrorCode
}

func (x *ExceptionWithStructuredAnnotation) GetErrorCode() int32 {
    return x.ErrorCode
}

func (x *ExceptionWithStructuredAnnotation) SetMessageFieldNonCompat(value string) *ExceptionWithStructuredAnnotation {
    x.MessageField = value
    return x
}

func (x *ExceptionWithStructuredAnnotation) SetMessageField(value string) *ExceptionWithStructuredAnnotation {
    x.MessageField = value
    return x
}

func (x *ExceptionWithStructuredAnnotation) SetErrorCodeNonCompat(value int32) *ExceptionWithStructuredAnnotation {
    x.ErrorCode = value
    return x
}

func (x *ExceptionWithStructuredAnnotation) SetErrorCode(value int32) *ExceptionWithStructuredAnnotation {
    x.ErrorCode = value
    return x
}

func (x *ExceptionWithStructuredAnnotation) writeField1(p thrift.Protocol) error {  // MessageField
    if err := p.WriteFieldBegin("message_field", thrift.STRING, 1); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.GetMessageFieldNonCompat()
    if err := p.WriteString(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *ExceptionWithStructuredAnnotation) writeField2(p thrift.Protocol) error {  // ErrorCode
    if err := p.WriteFieldBegin("error_code", thrift.I32, 2); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field begin error: ", x), err)
    }

    item := x.GetErrorCodeNonCompat()
    if err := p.WriteI32(item); err != nil {
    return err
}

    if err := p.WriteFieldEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field end error: ", x), err)
    }
    return nil
}

func (x *ExceptionWithStructuredAnnotation) readField1(p thrift.Protocol) error {  // MessageField
    result, err := p.ReadString()
if err != nil {
    return err
}

    x.SetMessageFieldNonCompat(result)
    return nil
}

func (x *ExceptionWithStructuredAnnotation) readField2(p thrift.Protocol) error {  // ErrorCode
    result, err := p.ReadI32()
if err != nil {
    return err
}

    x.SetErrorCodeNonCompat(result)
    return nil
}

func (x *ExceptionWithStructuredAnnotation) toString1() string {  // MessageField
    return fmt.Sprintf("%v", x.GetMessageFieldNonCompat())
}

func (x *ExceptionWithStructuredAnnotation) toString2() string {  // ErrorCode
    return fmt.Sprintf("%v", x.GetErrorCodeNonCompat())
}


// Deprecated: Use ExceptionWithStructuredAnnotation.Set* methods instead or set the fields directly.
type ExceptionWithStructuredAnnotationBuilder struct {
    obj *ExceptionWithStructuredAnnotation
}

func NewExceptionWithStructuredAnnotationBuilder() *ExceptionWithStructuredAnnotationBuilder {
    return &ExceptionWithStructuredAnnotationBuilder{
        obj: NewExceptionWithStructuredAnnotation(),
    }
}

func (x *ExceptionWithStructuredAnnotationBuilder) MessageField(value string) *ExceptionWithStructuredAnnotationBuilder {
    x.obj.MessageField = value
    return x
}

func (x *ExceptionWithStructuredAnnotationBuilder) ErrorCode(value int32) *ExceptionWithStructuredAnnotationBuilder {
    x.obj.ErrorCode = value
    return x
}

func (x *ExceptionWithStructuredAnnotationBuilder) Emit() *ExceptionWithStructuredAnnotation {
    var objCopy ExceptionWithStructuredAnnotation = *x.obj
    return &objCopy
}

func (x *ExceptionWithStructuredAnnotation) Write(p thrift.Protocol) error {
    if err := p.WriteStructBegin("ExceptionWithStructuredAnnotation"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := x.writeField1(p); err != nil {
        return err
    }

    if err := x.writeField2(p); err != nil {
        return err
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *ExceptionWithStructuredAnnotation) Read(p thrift.Protocol) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        switch id {
        case 1:  // message_field
            expectedType := thrift.Type(thrift.STRING)
            if wireType == expectedType {
                if err := x.readField1(p); err != nil {
                   return err
                }
            } else {
                if err := p.Skip(wireType); err != nil {
                    return err
                }
            }
        case 2:  // error_code
            expectedType := thrift.Type(thrift.I32)
            if wireType == expectedType {
                if err := x.readField2(p); err != nil {
                   return err
                }
            } else {
                if err := p.Skip(wireType); err != nil {
                    return err
                }
            }
        default:
            if err := p.Skip(wireType); err != nil {
                return err
            }
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *ExceptionWithStructuredAnnotation) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("ExceptionWithStructuredAnnotation({")
    sb.WriteString(fmt.Sprintf("MessageField:%s ", x.toString1()))
    sb.WriteString(fmt.Sprintf("ErrorCode:%s", x.toString2()))
    sb.WriteString("})")

    return sb.String()
}
func (x *ExceptionWithStructuredAnnotation) Error() string {
    return x.String()
}

type Banal struct {
}
// Compile time interface enforcer
var _ thrift.Struct = &Banal{}

func NewBanal() *Banal {
    return (&Banal{})
}


// Deprecated: Use Banal.Set* methods instead or set the fields directly.
type BanalBuilder struct {
    obj *Banal
}

func NewBanalBuilder() *BanalBuilder {
    return &BanalBuilder{
        obj: NewBanal(),
    }
}

func (x *BanalBuilder) Emit() *Banal {
    var objCopy Banal = *x.obj
    return &objCopy
}

func (x *Banal) Write(p thrift.Protocol) error {
    if err := p.WriteStructBegin("Banal"); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", x), err)
    }

    if err := p.WriteFieldStop(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write field stop error: ", x), err)
    }

    if err := p.WriteStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T write struct end error: ", x), err)
    }
    return nil
}

func (x *Banal) Read(p thrift.Protocol) error {
    if _, err := p.ReadStructBegin(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read error: ", x), err)
    }

    for {
        _, wireType, id, err := p.ReadFieldBegin()
        if err != nil {
            return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", x, id), err)
        }

        if wireType == thrift.STOP {
            break;
        }

        switch id {
        default:
            if err := p.Skip(wireType); err != nil {
                return err
            }
        }

        if err := p.ReadFieldEnd(); err != nil {
            return err
        }
    }

    if err := p.ReadStructEnd(); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", x), err)
    }

    return nil
}

func (x *Banal) String() string {
    if x == nil {
        return "<nil>"
    }

    var sb strings.Builder

    sb.WriteString("Banal({")
    sb.WriteString("})")

    return sb.String()
}
func (x *Banal) Error() string {
    return x.String()
}

// RegisterTypes registers types found in this file that have a thrift_uri with the passed in registry.
func RegisterTypes(registry interface {
	  RegisterType(name string, initializer func() any)
}) {

}
