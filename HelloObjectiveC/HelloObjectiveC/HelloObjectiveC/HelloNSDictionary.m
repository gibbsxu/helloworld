//
//  HelloNSDictionary.m
//  HelloObjectiveC
//
//  Created by hatlonely on 16/2/5.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma clang diagnostic ignored "-Wunused-variable"

void HelloNSDictionary() {
    {
        NSDictionary *dict = @{
            @"key1": @"value1",
            @"key2": @"value2",
            @"key3": @"value3"
        };
        NSString *value = [dict objectForKey:@"key1"];
    } {
        NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
        [dict setValuesForKeysWithDictionary:@{
           @"key1": @"value1",
           @"key2": @"value2"
        }];
        [dict setObject:@"value3" forKey:@"key3"];
        [dict removeObjectForKey:@"key1"];
        NSLog(@"%@", dict);
    } {
        NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
        [dict setValuesForKeysWithDictionary:@{
           @"key4": @"value4",
           @"key2": @"value2",
           @"key3": @"value3",
           @"key1": @"value1",
           @"key5": @"value5",
        }];
        
        // 遍历
        for (id key in dict) {
            NSLog(@"%@ => %@", key, [dict valueForKey:key]);
        }

        // 排序遍历
        NSMutableArray *keys = [NSMutableArray arrayWithArray:[dict allKeys]];
        [keys sortUsingSelector:@selector(compare:)];
        for (id key in keys) {
            NSLog(@"%@ => %@", key, [dict valueForKey:key]);
        }
    }
}
