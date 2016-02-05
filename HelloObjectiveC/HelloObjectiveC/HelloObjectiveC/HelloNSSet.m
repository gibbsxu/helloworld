//
//  HelloNSSet.m
//  HelloObjectiveC
//
//  Created by hatlonely on 16/2/5.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma clang diagnostic ignored "-Wunused-variable"

void HelloNSSet() {
    {
        NSSet *set1 = [NSSet setWithObjects:@1, @2, @3, nil];
        NSSet *set2 = [NSSet setWithArray:@[@2, @3, @4]];
        BOOL subset = [set1 isSubsetOfSet:set2];    // set2 是否是 set1 的子集
        BOOL result = [set1 intersectsSet:set2];    // set1 与 set2 的交集是否为空，true
        BOOL contain = [set1 containsObject:@1];    // 是否包含
        for (id i in set1) {
            NSLog(@"%@", i);
        }
        [set1 enumerateObjectsUsingBlock:^(id i, BOOL *stop) {
            NSLog(@"%@", i);
        }];
    } {
        NSMutableSet *set = [[NSMutableSet alloc] init];
        [set addObject:@1];
        [set removeObject:@1];
    } {
        NSMutableSet *set1 = [NSMutableSet setWithObjects:@1, @2, @3, nil];
        NSMutableSet *set2 = [NSMutableSet setWithObjects:@2, @3, @4, nil];
        [set1 intersectSet:set2];   // 交集   set1 = set1 ∩ set2
        [set1 minusSet:set2];       // 差集   set1 = set1 - set2
        [set1 unionSet:set2];       // 并集   set1 = set1 ∪ set2
    } {
        NSIndexSet *indexSet = [NSIndexSet indexSetWithIndexesInRange:NSMakeRange(0, 9)];
        BOOL contain = [indexSet containsIndex:8];
    } {
        NSMutableIndexSet *indexSet = [NSMutableIndexSet indexSetWithIndexesInRange:NSMakeRange(0, 9)];
        [indexSet addIndex:9];
        [indexSet removeIndex:5];
        NSLog(@"%@, %lu", indexSet, [indexSet count]);
    }
}
