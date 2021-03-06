//
//  XTransactionACL.m
//  xuper-sdk-oc-iOS
//
//  Created by apple on 2019/12/7.
//  Copyright © 2019 Martin.Ren. All rights reserved.
//

#import "XTransactionACL.h"

@implementation XTransactionPM

- (instancetype _Nonnull) init {
    
    self = [super init];
    
    self.rule = XTransactionPMRuleDefault;
    self.acceptValue = 1.0f;
    
    return self;
}

@end

@implementation XTransactionACL

+ (instancetype _Nonnull) simpleACLWithAddress:(XAddress _Nonnull)address {
    
    XTransactionACL *simpleACL = [[XTransactionACL alloc] init];
    
    simpleACL.aksWeight[address] = @(1.0f);
    
    return simpleACL;
}

- (BOOL) isEqual:(id)object {
    
    ///指针相同直接返回true
    if ( self == object ) {
        return true;
    }
    
    ///对象不同直接返回false
    if ( ![object isKindOfClass:[self class]] ) {
        return false;
    }
    
    ///匹配所有的值
    XTransactionACL *b = (XTransactionACL*)object;
    if (
        self.pm.acceptValue == b.pm.acceptValue &&
        self.pm.rule == b.pm.rule &&
        [self.aksWeight isEqualToDictionary:b.aksWeight]
        ) {
        
        return true;
        
    } else {
        return false;
    }
}

- (instancetype _Nonnull) init {
    
    self = [super init];
    
    self.pm = [[XTransactionPM alloc] init];
    
    self.aksWeight = [[XTransactionAKSWeight alloc] init];
    
    return self;
}

- (instancetype _Nonnull) initWithPBACL:(Acl* _Nonnull)acl {
    
    self = [self init];
    
    self.pm.rule = acl.pm.rule;
    self.pm.acceptValue = acl.pm.acceptValue;
    
    [acl.aksWeight enumerateKeysAndDoublesUsingBlock:^(NSString * _Nonnull key, double value, BOOL * _Nonnull stop) {
        self.aksWeight[key] = @(value);
    }];
    
    return self;
}


/*
{
    "pm": {
        "rule": 1,
        "acceptValue": 0.6
    },
    "aksWeight": {
        "dpzuVdosQrF2kmzumhVeFQZa1aYcdgFpN": 0.5,
        "eqMvtH1MQSejd4nzxDy21W1GW12cocrPF": 0.5
    }
}
*/
- (id _Nullable) encodeToJsonObjectWithError:(NSError * _Nonnull * _Nullable)error {
    
    NSMutableDictionary *jobject = [[NSMutableDictionary alloc] init];
    
    [jobject setObject:@{
        @"rule": @(self.pm.rule),
        @"acceptValue": @(self.pm.acceptValue),
    } forKey:@"pm"];
    
    [jobject setObject:self.aksWeight forKey:@"aksWeight"];
    
    NSData *jdata = [NSJSONSerialization dataWithJSONObject:jobject options:NSJSONWritingSortedKeys error:error];
    
    if (error) {
        return nil;
    }
    
    return [[NSString alloc] initWithData:jdata encoding:NSUTF8StringEncoding];
}

- (NSString * _Nullable) aclAuthRequireString {
    return [self encodeToJsonObjectWithError:nil];
}

@end
