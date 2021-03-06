//
//  ObjectivePGP.h
//  ObjectivePGP
//
//  Created by Marcin Krzyzanowski on 03/05/14.
//  Copyright (c) 2014 Marcin Krzyżanowski. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PGPTypes.h"
#import "PGPKey.h"
#import "PGPUser.h"

@interface ObjectivePGP : NSObject

/**
 *  Array of PGPKey
 */
@property (strong, nonatomic) NSArray<PGPKey *> *keys;

// Import keys
- (NSArray * __nullable) importKeysFromFile:(NSString * __nonnull)path allowDuplicates:(BOOL)duplicates;
- (NSArray * __nullable) importKeysFromData:(NSData * __nonnull)data allowDuplicates:(BOOL)duplicates;
- (BOOL) importKey:(NSString *)shortKeyStringIdentifier fromFile:(NSString *)path;

// Read keys
- (NSArray<PGPKey *> * __nullable) keysFromData:(NSData * __nonnull)fileData;
- (NSArray<PGPKey *> * __nullable) keysFromFile:(NSString * __nonnull)path;

// Export keys
- (BOOL) exportKeysOfType:(PGPKeyType)type toFile:(NSString *)path error:(NSError * __autoreleasing *)error;
- (BOOL) exportKeys:(NSArray *)keys toFile:(NSString *)path error:(NSError * __autoreleasing *)error;
- (NSData *) exportKey:(PGPKey *)key armored:(BOOL)armored;

- (PGPKey *) getKeyForIdentifier:(NSString *)keyIdentifier type:(PGPKeyType)keyType;
- (PGPKey *) getKeyForKeyID:(PGPKeyID *)searchKeyID type:(PGPKeyType)keyType;
- (NSArray<PGPKey *> * __nonnull) getKeysForUserID:(NSString * __nonnull)userID;
- (NSArray<PGPKey *> * __nonnull) getKeysOfType:(PGPKeyType)keyType;

- (NSData *) signData:(NSData *)dataToSign usingSecretKey:(PGPKey *)secretKey passphrase:(NSString *)passphrase  error:(NSError * __autoreleasing *)error;
- (NSData *) signData:(NSData *)dataToSign usingSecretKey:(PGPKey *)secretKey passphrase:(NSString *)passphrase detached:(BOOL)detached  error:(NSError * __autoreleasing *)error;
- (NSData *) signData:(NSData *)dataToSign withKeyForUserID:(NSString *)userID passphrase:(NSString *)passphrase error:(NSError * __autoreleasing *)error;
- (NSData *) signData:(NSData *)dataToSign withKeyForUserID:(NSString *)userID passphrase:(NSString *)passphrase detached:(BOOL)detached error:(NSError * __autoreleasing *)error;

- (BOOL) verifyData:(NSData *)signedDataPackets error:(NSError * __autoreleasing *)error;
- (BOOL) verifyData:(NSData *)signedData withSignature:(NSData *)signatureData error:(NSError * __autoreleasing *)error;
- (BOOL) verifyData:(NSData *)signedData withSignature:(NSData *)signatureData usingKey:(PGPKey *)publicKey error:(NSError * __autoreleasing *)error;

- (NSData *) encryptData:(NSData *)dataToEncrypt usingPublicKey:(PGPKey *)publicKey armored:(BOOL)armored error:(NSError * __autoreleasing *)error;
- (NSData *) encryptData:(NSData *)dataToEncrypt usingPublicKeys:(NSArray *)publicKeys armored:(BOOL)armored error:(NSError * __autoreleasing *)error;
- (NSData *) encryptData:(NSData *)dataToEncrypt usingPublicKeys:(NSArray *)publicKeys signWithSecretKey:(PGPKey *)secretKey passphrase:(NSString *)passphrase armored:(BOOL)armored error:(NSError * __autoreleasing *)error;
- (NSData *) decryptData:(NSData *)messageDataToDecrypt passphrase:(NSString *)passphrase error:(NSError * __autoreleasing *)error;
- (NSData *) decryptData:(NSData *)messageDataToDecrypt passphrase:(NSString *)passphrase verifyWithPublicKey:(PGPKey *)publicKey signed:(BOOL*)isSigned valid:(BOOL*)isValid integrityProtected:(BOOL*)isIntegrityProtected error:(NSError * __autoreleasing *)error;

@end
