//
//  PGPKeyID.h
//  OpenPGPKeyring
//
//  Created by Marcin Krzyzanowski on 06/05/14.
//  Copyright (c) 2014 Marcin Krzyżanowski. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PGPKeyID : NSObject

@property (readonly, nonatomic) NSData *longKey;
@property (readonly, nonatomic) NSString *longKeyString;
@property (readonly, nonatomic) NSData *shortKey;
@property (readonly, nonatomic) NSString *shortKeyString;

- (instancetype) initWithData:(NSData *)longKeyData;

@end