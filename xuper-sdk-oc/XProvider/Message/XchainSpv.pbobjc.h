// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: xchain_spv.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/GPBProtocolBuffers.h>
#else
 #import "GPBProtocolBuffers.h"
#endif

#if GOOGLE_PROTOBUF_OBJC_VERSION < 30002
#error This file was generated by a newer version of protoc which is incompatible with your Protocol Buffer library sources.
#endif
#if 30002 < GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION
#error This file was generated by an older version of protoc which is incompatible with your Protocol Buffer library sources.
#endif

// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

CF_EXTERN_C_BEGIN

@class TxInput;
@class TxOutput;
@class UTXO;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Enum ReturnCode

/** ReturnCode is the code for client */
typedef GPB_ENUM(ReturnCode) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  ReturnCode_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  /** Operation success */
  ReturnCode_Returnsuccess = 0,

  /** Err about Account */
  ReturnCode_Internalerr = 101000,
  ReturnCode_Filenotexist = 101002,
  ReturnCode_Paramerr = 101003,
  ReturnCode_Httprequertfail = 101004,
  ReturnCode_Httpresponsefail = 101005,
  ReturnCode_Accountnotexist = 101008,
  ReturnCode_Pwnotexist = 101009,
  ReturnCode_Pwexist = 101010,
  ReturnCode_Notlogin = 101012,

  /** Err about Transaction */
  ReturnCode_Connectnodefail = 102001,
  ReturnCode_Utxonotenough = 102002,
  ReturnCode_Addressinvalid = 102003,
  ReturnCode_Feeinvalid = 102004,
  ReturnCode_Connectrefused = 102005,
  ReturnCode_Utxoencrypterr = 102006,
  ReturnCode_Feenotenougn = 102007,
  ReturnCode_Paramsinvalid = 102008,
  ReturnCode_Txsignerr = 102009,
  ReturnCode_Reposttxerr = 102010,
  ReturnCode_Blockchainnotexist = 102011,
  ReturnCode_Servererr = 102012,
};

GPBEnumDescriptor *ReturnCode_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL ReturnCode_IsValidValue(int32_t value);

#pragma mark - XchainSpvRoot

/**
 * Exposes the extension registry for this file.
 *
 * The base class provides:
 * @code
 *   + (GPBExtensionRegistry *)extensionRegistry;
 * @endcode
 * which is a @c GPBExtensionRegistry that includes all the extensions defined by
 * this file and all files that it depends on.
 **/
@interface XchainSpvRoot : GPBRootObject
@end

#pragma mark - ECDSAAccount

typedef GPB_ENUM(ECDSAAccount_FieldNumber) {
  ECDSAAccount_FieldNumber_EntropyByte = 1,
  ECDSAAccount_FieldNumber_Mnemonic = 2,
  ECDSAAccount_FieldNumber_JsonPrivateKey = 3,
  ECDSAAccount_FieldNumber_JsonPublicKey = 4,
  ECDSAAccount_FieldNumber_Address = 5,
};

/**
 * 助记词、私钥的json、公钥的json、钱包地址
 **/
@interface ECDSAAccount : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSData *entropyByte;

@property(nonatomic, readwrite, copy, null_resettable) NSString *mnemonic;

@property(nonatomic, readwrite, copy, null_resettable) NSString *jsonPrivateKey;

@property(nonatomic, readwrite, copy, null_resettable) NSString *jsonPublicKey;

@property(nonatomic, readwrite, copy, null_resettable) NSString *address;

@end

#pragma mark - ECDSAInfo

typedef GPB_ENUM(ECDSAInfo_FieldNumber) {
  ECDSAInfo_FieldNumber_EntropyByte = 1,
  ECDSAInfo_FieldNumber_Mnemonic = 2,
  ECDSAInfo_FieldNumber_Address = 3,
};

/**
 * 助记词、随机字节数组、钱包地址
 **/
@interface ECDSAInfo : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSData *entropyByte;

@property(nonatomic, readwrite, copy, null_resettable) NSString *mnemonic;

@property(nonatomic, readwrite, copy, null_resettable) NSString *address;

@end

#pragma mark - ECDSAAccountFromCloud

typedef GPB_ENUM(ECDSAAccountFromCloud_FieldNumber) {
  ECDSAAccountFromCloud_FieldNumber_Address = 1,
  ECDSAAccountFromCloud_FieldNumber_JsonEncryptedPrivateKey = 2,
  ECDSAAccountFromCloud_FieldNumber_EncryptedMnemonic = 3,
};

/**
 * 钱包地址、被加密后的私钥、被加密后的助记词
 **/
@interface ECDSAAccountFromCloud : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSString *address;

@property(nonatomic, readwrite, copy, null_resettable) NSString *jsonEncryptedPrivateKey;

@property(nonatomic, readwrite, copy, null_resettable) NSString *encryptedMnemonic;

@end

#pragma mark - ECDSAAccountToCloud

typedef GPB_ENUM(ECDSAAccountToCloud_FieldNumber) {
  ECDSAAccountToCloud_FieldNumber_Address = 1,
  ECDSAAccountToCloud_FieldNumber_JsonEncryptedPrivateKey = 2,
  ECDSAAccountToCloud_FieldNumber_EncryptedMnemonic = 3,
  ECDSAAccountToCloud_FieldNumber_Password = 4,
};

/**
 * 钱包地址、被加密后的私钥、被加密后的助记词、支付密码的明文
 **/
@interface ECDSAAccountToCloud : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSString *address;

@property(nonatomic, readwrite, copy, null_resettable) NSString *jsonEncryptedPrivateKey;

@property(nonatomic, readwrite, copy, null_resettable) NSString *encryptedMnemonic;

@property(nonatomic, readwrite, copy, null_resettable) NSString *password;

@end

#pragma mark - Node

typedef GPB_ENUM(Node_FieldNumber) {
  Node_FieldNumber_Host = 1,
  Node_FieldNumber_UtxoQueryURL = 2,
  Node_FieldNumber_TxPostURL = 3,
  Node_FieldNumber_BalanceQueryURL = 4,
};

/**
 * 全节点
 **/
@interface Node : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSData *host;

@property(nonatomic, readwrite, copy, null_resettable) NSData *utxoQueryURL;

@property(nonatomic, readwrite, copy, null_resettable) NSData *txPostURL;

@property(nonatomic, readwrite, copy, null_resettable) NSData *balanceQueryURL;

@end

#pragma mark - TxInputs

typedef GPB_ENUM(TxInputs_FieldNumber) {
  TxInputs_FieldNumber_TxInputListArray = 1,
};

/**
 * 交易输入列表
 **/
@interface TxInputs : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<TxInput*> *txInputListArray;
/** The number of items in @c txInputListArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger txInputListArray_Count;

@end

#pragma mark - TxOutputs

typedef GPB_ENUM(TxOutputs_FieldNumber) {
  TxOutputs_FieldNumber_TxOutputListArray = 1,
};

/**
 * 交易输出列表
 **/
@interface TxOutputs : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<TxOutput*> *txOutputListArray;
/** The number of items in @c txOutputListArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger txOutputListArray_Count;

@end

#pragma mark - UTXOs

typedef GPB_ENUM(UTXOs_FieldNumber) {
  UTXOs_FieldNumber_UTxolistArray = 1,
};

/**
 * 未花费的交易输出列表
 **/
@interface UTXOs : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<UTXO*> *uTxolistArray;
/** The number of items in @c uTxolistArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger uTxolistArray_Count;

@end

#pragma mark - UTXO

typedef GPB_ENUM(UTXO_FieldNumber) {
  UTXO_FieldNumber_Amount = 1,
  UTXO_FieldNumber_ToAddr = 2,
  UTXO_FieldNumber_ToPubkey = 3,
  UTXO_FieldNumber_RefTxid = 4,
  UTXO_FieldNumber_RefOffset = 5,
};

/**
 * 未花费的交易输出
 **/
@interface UTXO : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSData *amount;

@property(nonatomic, readwrite, copy, null_resettable) NSData *toAddr;

@property(nonatomic, readwrite, copy, null_resettable) NSData *toPubkey;

@property(nonatomic, readwrite, copy, null_resettable) NSData *refTxid;

@property(nonatomic, readwrite) int32_t refOffset;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
