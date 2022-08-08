<?hh
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

namespace fixtures\basic;

/**
 * Original thrift service:-
 * FB303Service
 */
<<\ThriftTypeInfo(shape('uri' => 'test.dev/fixtures/basic/FB303Service'))>>
interface FB303ServiceAsyncIf extends \IThriftAsyncIf {
  /**
   * Original thrift definition:-
   * ReservedKeyword
   *   renamed_rpc(1: i32 int_parameter);
   */
  public function renamed_rpc(int $renamed_parameter): Awaitable<\fixtures\basic\MyRenamedStruct>;
}

/**
 * Original thrift service:-
 * FB303Service
 */
<<\ThriftTypeInfo(shape('uri' => 'test.dev/fixtures/basic/FB303Service'))>>
interface FB303ServiceIf extends \IThriftSyncIf {
  /**
   * Original thrift definition:-
   * ReservedKeyword
   *   renamed_rpc(1: i32 int_parameter);
   */
  public function renamed_rpc(int $renamed_parameter): \fixtures\basic\MyRenamedStruct;
}

/**
 * Original thrift service:-
 * FB303Service
 */
<<\ThriftTypeInfo(shape('uri' => 'test.dev/fixtures/basic/FB303Service'))>>
interface FB303ServiceAsyncClientIf extends FB303ServiceAsyncIf {
}

/**
 * Original thrift service:-
 * FB303Service
 */
<<\ThriftTypeInfo(shape('uri' => 'test.dev/fixtures/basic/FB303Service'))>>
interface FB303ServiceClientIf extends \IThriftSyncIf {
  /**
   * Original thrift definition:-
   * ReservedKeyword
   *   renamed_rpc(1: i32 int_parameter);
   */
  public function renamed_rpc(int $renamed_parameter): Awaitable<\fixtures\basic\MyRenamedStruct>;
}

/**
 * Original thrift service:-
 * FB303Service
 */
trait FB303ServiceClientBase {
  require extends \ThriftClientBase;

}

class FB303ServiceAsyncClient extends \ThriftClientBase implements FB303ServiceAsyncClientIf {
  use FB303ServiceClientBase;

  /**
   * Original thrift definition:-
   * ReservedKeyword
   *   renamed_rpc(1: i32 int_parameter);
   */
  public async function renamed_rpc(int $renamed_parameter): Awaitable<\fixtures\basic\MyRenamedStruct> {
    $hh_frame_metadata = $this->getHHFrameMetadata();
    if ($hh_frame_metadata !== null) {
      \HH\set_frame_metadata($hh_frame_metadata);
    }
    $rpc_options = $this->getAndResetOptions() ?? \ThriftClientBase::defaultOptions();
    $args = \fixtures\basic\FB303Service_renamed_rpc_args::fromShape(shape(
      'int_parameter' => $int_parameter,
    ));
    await $this->asyncHandler_->genBefore("FB303Service", "renamed_rpc", $args);
    $currentseqid = $this->sendImplHelper($args, "renamed_rpc", false);
    return await $this->genAwaitResponse(\fixtures\basic\FB303Service_renamed_rpc_result::class, "simple_rpc", false, $currentseqid, $rpc_options);
  }

}

class FB303ServiceClient extends \ThriftClientBase implements FB303ServiceClientIf {
  use FB303ServiceClientBase;

  /**
   * Original thrift definition:-
   * ReservedKeyword
   *   renamed_rpc(1: i32 int_parameter);
   */
  public async function renamed_rpc(int $renamed_parameter): Awaitable<\fixtures\basic\MyRenamedStruct> {
    $hh_frame_metadata = $this->getHHFrameMetadata();
    if ($hh_frame_metadata !== null) {
      \HH\set_frame_metadata($hh_frame_metadata);
    }
    $rpc_options = $this->getAndResetOptions() ?? \ThriftClientBase::defaultOptions();
    $args = \fixtures\basic\FB303Service_renamed_rpc_args::fromShape(shape(
      'int_parameter' => $int_parameter,
    ));
    await $this->asyncHandler_->genBefore("FB303Service", "renamed_rpc", $args);
    $currentseqid = $this->sendImplHelper($args, "renamed_rpc", false);
    return await $this->genAwaitResponse(\fixtures\basic\FB303Service_renamed_rpc_result::class, "simple_rpc", false, $currentseqid, $rpc_options);
  }

  /* send and recv functions */
  public function send_renamed_rpc(int $renamed_parameter): int {
    $args = \fixtures\basic\FB303Service_renamed_rpc_args::fromShape(shape(
      'int_parameter' => $int_parameter,
    ));
    return $this->sendImplHelper($args, "renamed_rpc", false);
  }
  public function recv_renamed_rpc(?int $expectedsequenceid = null): \fixtures\basic\MyRenamedStruct {
    return $this->recvImplHelper(\fixtures\basic\FB303Service_renamed_rpc_result::class, "renamed_rpc", false, $expectedsequenceid);
  }
}

abstract class FB303ServiceAsyncProcessorBase extends \ThriftAsyncProcessor {
  abstract const type TThriftIf as FB303ServiceAsyncIf;
  const classname<\IThriftServiceStaticMetadata> SERVICE_METADATA_CLASS = FB303ServiceStaticMetadata::class;

  protected async function process_renamed_rpc(int $seqid, \TProtocol $input, \TProtocol $output): Awaitable<void> {
    $handler_ctx = $this->eventHandler_->getHandlerContext('renamed_rpc');
    $reply_type = \TMessageType::REPLY;

    $this->eventHandler_->preRead($handler_ctx, 'renamed_rpc', dict[]);

    if ($input is \TBinaryProtocolAccelerated) {
      $args = \thrift_protocol_read_binary_struct($input, '\fixtures\basic\FB303Service_renamed_rpc_args');
    } else if ($input is \TCompactProtocolAccelerated) {
      $args = \thrift_protocol_read_compact_struct($input, '\fixtures\basic\FB303Service_renamed_rpc_args');
    } else {
      $args = \fixtures\basic\FB303Service_renamed_rpc_args::withDefaultValues();
      $args->read($input);
    }
    $input->readMessageEnd();
    $this->eventHandler_->postRead($handler_ctx, 'renamed_rpc', $args);
    $result = \fixtures\basic\FB303Service_renamed_rpc_result::withDefaultValues();
    try {
      $this->eventHandler_->preExec($handler_ctx, '\fixtures\basic\FB303Service', 'renamed_rpc', $args);
      $result->success = await $this->handler->renamed_rpc($args->int_parameter);
      $this->eventHandler_->postExec($handler_ctx, 'renamed_rpc', $result);
    } catch (\Exception $ex) {
      $reply_type = \TMessageType::EXCEPTION;
      $this->eventHandler_->handlerError($handler_ctx, 'renamed_rpc', $ex);
      $result = new \TApplicationException($ex->getMessage()."\n".$ex->getTraceAsString());
    }
    $this->eventHandler_->preWrite($handler_ctx, 'renamed_rpc', $result);
    if ($output is \TBinaryProtocolAccelerated)
    {
      \thrift_protocol_write_binary($output, 'renamed_rpc', $reply_type, $result, $seqid, $output->isStrictWrite());
    }
    else if ($output is \TCompactProtocolAccelerated)
    {
      \thrift_protocol_write_compact($output, 'renamed_rpc', $reply_type, $result, $seqid);
    }
    else
    {
      $output->writeMessageBegin("renamed_rpc", $reply_type, $seqid);
      $result->write($output);
      $output->writeMessageEnd();
      $output->getTransport()->flush();
    }
    $this->eventHandler_->postWrite($handler_ctx, 'renamed_rpc', $result);
  }
  protected async function process_getThriftServiceMetadata(int $seqid, \TProtocol $input, \TProtocol $output): Awaitable<void> {
    $reply_type = \TMessageType::REPLY;

    if ($input is \TBinaryProtocolAccelerated) {
      $args = \thrift_protocol_read_binary_struct($input, '\tmeta_ThriftMetadataService_getThriftServiceMetadata_args');
    } else if ($input is \TCompactProtocolAccelerated) {
      $args = \thrift_protocol_read_compact_struct($input, '\tmeta_ThriftMetadataService_getThriftServiceMetadata_args');
    } else {
      $args = \tmeta_ThriftMetadataService_getThriftServiceMetadata_args::withDefaultValues();
      $args->read($input);
    }
    $input->readMessageEnd();
    $result = \tmeta_ThriftMetadataService_getThriftServiceMetadata_result::withDefaultValues();
    try {
      $result->success = FB303ServiceStaticMetadata::getServiceMetadataResponse();
    } catch (\Exception $ex) {
      $reply_type = \TMessageType::EXCEPTION;
      $result = new \TApplicationException($ex->getMessage()."\n".$ex->getTraceAsString());
    }
    if ($output is \TBinaryProtocolAccelerated)
    {
      \thrift_protocol_write_binary($output, 'getThriftServiceMetadata', $reply_type, $result, $seqid, $output->isStrictWrite());
    }
    else if ($output is \TCompactProtocolAccelerated)
    {
      \thrift_protocol_write_compact($output, 'getThriftServiceMetadata', $reply_type, $result, $seqid);
    }
    else
    {
      $output->writeMessageBegin("getThriftServiceMetadata", $reply_type, $seqid);
      $result->write($output);
      $output->writeMessageEnd();
      $output->getTransport()->flush();
    }
  }
}
class FB303ServiceAsyncProcessor extends FB303ServiceAsyncProcessorBase {
  const type TThriftIf = FB303ServiceAsyncIf;
}

abstract class FB303ServiceSyncProcessorBase extends \ThriftSyncProcessor {
  abstract const type TThriftIf as FB303ServiceIf;
  const classname<\IThriftServiceStaticMetadata> SERVICE_METADATA_CLASS = FB303ServiceStaticMetadata::class;

  protected function process_renamed_rpc(int $seqid, \TProtocol $input, \TProtocol $output): void {
    $handler_ctx = $this->eventHandler_->getHandlerContext('renamed_rpc');
    $reply_type = \TMessageType::REPLY;

    $this->eventHandler_->preRead($handler_ctx, 'renamed_rpc', dict[]);

    if ($input is \TBinaryProtocolAccelerated) {
      $args = \thrift_protocol_read_binary_struct($input, '\fixtures\basic\FB303Service_renamed_rpc_args');
    } else if ($input is \TCompactProtocolAccelerated) {
      $args = \thrift_protocol_read_compact_struct($input, '\fixtures\basic\FB303Service_renamed_rpc_args');
    } else {
      $args = \fixtures\basic\FB303Service_renamed_rpc_args::withDefaultValues();
      $args->read($input);
    }
    $input->readMessageEnd();
    $this->eventHandler_->postRead($handler_ctx, 'renamed_rpc', $args);
    $result = \fixtures\basic\FB303Service_renamed_rpc_result::withDefaultValues();
    try {
      $this->eventHandler_->preExec($handler_ctx, '\fixtures\basic\FB303Service', 'renamed_rpc', $args);
      $result->success = $this->handler->renamed_rpc($args->int_parameter);
      $this->eventHandler_->postExec($handler_ctx, 'renamed_rpc', $result);
    } catch (\Exception $ex) {
      $reply_type = \TMessageType::EXCEPTION;
      $this->eventHandler_->handlerError($handler_ctx, 'renamed_rpc', $ex);
      $result = new \TApplicationException($ex->getMessage()."\n".$ex->getTraceAsString());
    }
    $this->eventHandler_->preWrite($handler_ctx, 'renamed_rpc', $result);
    if ($output is \TBinaryProtocolAccelerated)
    {
      \thrift_protocol_write_binary($output, 'renamed_rpc', $reply_type, $result, $seqid, $output->isStrictWrite());
    }
    else if ($output is \TCompactProtocolAccelerated)
    {
      \thrift_protocol_write_compact($output, 'renamed_rpc', $reply_type, $result, $seqid);
    }
    else
    {
      $output->writeMessageBegin("renamed_rpc", $reply_type, $seqid);
      $result->write($output);
      $output->writeMessageEnd();
      $output->getTransport()->flush();
    }
    $this->eventHandler_->postWrite($handler_ctx, 'renamed_rpc', $result);
  }
  protected function process_getThriftServiceMetadata(int $seqid, \TProtocol $input, \TProtocol $output): void {
    $reply_type = \TMessageType::REPLY;

    if ($input is \TBinaryProtocolAccelerated) {
      $args = \thrift_protocol_read_binary_struct($input, '\tmeta_ThriftMetadataService_getThriftServiceMetadata_args');
    } else if ($input is \TCompactProtocolAccelerated) {
      $args = \thrift_protocol_read_compact_struct($input, '\tmeta_ThriftMetadataService_getThriftServiceMetadata_args');
    } else {
      $args = \tmeta_ThriftMetadataService_getThriftServiceMetadata_args::withDefaultValues();
      $args->read($input);
    }
    $input->readMessageEnd();
    $result = \tmeta_ThriftMetadataService_getThriftServiceMetadata_result::withDefaultValues();
    try {
      $result->success = FB303ServiceStaticMetadata::getServiceMetadataResponse();
    } catch (\Exception $ex) {
      $reply_type = \TMessageType::EXCEPTION;
      $result = new \TApplicationException($ex->getMessage()."\n".$ex->getTraceAsString());
    }
    if ($output is \TBinaryProtocolAccelerated)
    {
      \thrift_protocol_write_binary($output, 'getThriftServiceMetadata', $reply_type, $result, $seqid, $output->isStrictWrite());
    }
    else if ($output is \TCompactProtocolAccelerated)
    {
      \thrift_protocol_write_compact($output, 'getThriftServiceMetadata', $reply_type, $result, $seqid);
    }
    else
    {
      $output->writeMessageBegin("getThriftServiceMetadata", $reply_type, $seqid);
      $result->write($output);
      $output->writeMessageEnd();
      $output->getTransport()->flush();
    }
  }
}
class FB303ServiceSyncProcessor extends FB303ServiceSyncProcessorBase {
  const type TThriftIf = FB303ServiceIf;
}
// For backwards compatibility
class FB303ServiceProcessor extends FB303ServiceSyncProcessor {}

// HELPER FUNCTIONS AND STRUCTURES

class FB303Service_renamed_rpc implements \IThriftSyncStruct, \IThriftShapishSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'int_parameter',
      'type' => \TType::I32,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'int_parameter' => 1,
  ];

  const type TConstructorShape = shape(
    ?'int_parameter' => ?int,
  );

  const type TShape = shape(
    'int_parameter' => int,
    ...
  );
  const int STRUCTURAL_ID = 3607165688153615571;
  public int $int_parameter;

  public function __construct(?int $int_parameter = null)[] {
    $this->int_parameter = $int_parameter ?? 0;
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'int_parameter'),
    );
  }

  public function getName()[]: string {
    return 'FB303Service_renamed_rpc';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return \tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "module.simple_rpc_args",
        "fields" => vec[
          \tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => \tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => \tmeta_ThriftPrimitiveType::THRIFT_I32_TYPE,
                )
              ),
              "name" => "int_parameter",
            )
          ),
        ],
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
        'int_parameter' => shape(
          'field' => dict[
            '\thrift\annotation\hack\Name' => \thrift\annotation\hack\Name::fromShape(
              shape(
                "name" => "renamed_parameter",
              )
            ),
          ],
          'type' => dict[],
        ),
      ],
    );
  }

  public static function __fromShape(self::TShape $shape)[]: this {
    return new static(
      $shape['int_parameter'],
    );
  }

  public function __toShape()[]: self::TShape {
    return shape(
      'int_parameter' => $this->int_parameter,
    );
  }
  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

  public function readFromJson(string $jsonText): void {
    $parsed = json_decode($jsonText, true);

    if ($parsed === null || !($parsed is KeyedContainer<_, _>)) {
      throw new \TProtocolException("Cannot parse the given json string.");
    }

    if (idx($parsed, 'int_parameter') !== null) {
      $_tmp0 = (int)HH\FIXME\UNSAFE_CAST<mixed, int>($parsed['int_parameter']);
      if ($_tmp0 > 0x7fffffff) {
        throw new \TProtocolException("number exceeds limit in field");
      } else {
        $this->int_parameter = (int)$_tmp0;
      }
    }
  }

}

class FB303Service_renamed_rpc_result extends \ThriftSyncStructWithResult {
  use \ThriftSerializationTrait;

  const type TResult = \fixtures\basic\MyRenamedStruct;

  const dict<int, this::TFieldSpec> SPEC = dict[
    0 => shape(
      'var' => 'success',
      'type' => \TType::STRUCT,
      'class' => \fixtures\basic\MyRenamedStruct::class,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'success' => 0,
  ];

  const type TConstructorShape = shape(
    ?'success' => ?this::TResult,
  );

  const int STRUCTURAL_ID = 7443966475393398575;
  public ?this::TResult $success;

  public function __construct(?this::TResult $success = null)[] {
    $this->success = $success;
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'success'),
    );
  }

  public function getName()[]: string {
    return 'FB303Service_renamed_rpc_result';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return \tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "module.FB303Service_renamed_rpc_result",
        "fields" => vec[
          \tmeta_ThriftField::fromShape(
            shape(
              "id" => 0,
              "type" => \tmeta_ThriftType::fromShape(
                shape(
                  "t_struct" => \tmeta_ThriftStructType::fromShape(
                    shape(
                      "name" => "module.ReservedKeyword",
                    )
                  ),
                )
              ),
              "name" => "success",
            )
          ),
        ],
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[]: \TStructAnnotations {
    return shape(
      'struct' => dict[],
      'fields' => dict[
        'success' => shape(
          'field' => dict[],
          'type' => dict[
            '\thrift\annotation\hack\Name' => \thrift\annotation\hack\Name::fromShape(
              shape(
                "name" => "MyRenamedStruct",
              )
            ),
          ],
        ),
      ],
    );
  }

  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

  public function readFromJson(string $jsonText): void {
    $parsed = json_decode($jsonText, true);

    if ($parsed === null || !($parsed is KeyedContainer<_, _>)) {
      throw new \TProtocolException("Cannot parse the given json string.");
    }

    if (idx($parsed, 'success') !== null) {
      $_tmp0 = \json_encode(HH\FIXME\UNSAFE_CAST<mixed, \fixtures\basic\MyRenamedStruct>($parsed['success']));
      $_tmp1 = \fixtures\basic\MyRenamedStruct::withDefaultValues();
      $_tmp1->readFromJson($_tmp0);
      $this->success = $_tmp1;
    }
  }

}

class FB303ServiceStaticMetadata implements \IThriftServiceStaticMetadata {
  public static function getServiceMetadata()[]: \tmeta_ThriftService {
    return \tmeta_ThriftService::fromShape(
      shape(
        "name" => "module.FB303Service",
        "functions" => vec[
          \tmeta_ThriftFunction::fromShape(
            shape(
              "name" => "renamed_rpc",
              "return_type" => \tmeta_ThriftType::fromShape(
                shape(
                  "t_struct" => \tmeta_ThriftStructType::fromShape(
                    shape(
                      "name" => "module.ReservedKeyword",
                    )
                  ),
                )
              ),
              "arguments" => vec[
                \tmeta_ThriftField::fromShape(
                  shape(
                    "id" => 1,
                    "type" => \tmeta_ThriftType::fromShape(
                      shape(
                        "t_primitive" => \tmeta_ThriftPrimitiveType::THRIFT_I32_TYPE,
                      )
                    ),
                    "name" => "int_parameter",
                  )
                ),
              ],
            )
          ),
        ],
      )
    );
  }

  public static function getServiceMetadataResponse()[]: \tmeta_ThriftServiceMetadataResponse {
    return \tmeta_ThriftServiceMetadataResponse::fromShape(
      shape(
        'context' => \tmeta_ThriftServiceContext::fromShape(
          shape(
            'service_info' => self::getServiceMetadata(),
            'module' => \tmeta_ThriftModuleContext::fromShape(
              shape(
                'name' => 'module',
              )
            ),
          )
        ),
        'metadata' => \tmeta_ThriftMetadata::fromShape(
          shape(
            'enums' => dict[
            ],
            'structs' => dict[
              'module.ReservedKeyword' => \fixtures\basic\MyRenamedStruct::getStructMetadata(),
            ],
            'exceptions' => dict[
            ],
            'services' => dict[
            ],
          )
        ),
      )
    );
  }

  public static function getAllStructuredAnnotations()[]: \TServiceAnnotations {
    return shape(
      'service' => dict[],
      'functions' => dict[
        'renamed_rpc' => dict[
          '\thrift\annotation\hack\Name' => \thrift\annotation\hack\Name::fromShape(
            shape(
              "name" => "renamed_rpc",
            )
          ),
        ],
      ],
    );
  }
}

