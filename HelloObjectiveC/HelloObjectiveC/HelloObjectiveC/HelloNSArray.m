//
//  HelloNSArray.m
//  HelloObjectiveC
//
//  Created by hatlonely on 16/2/5.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#import <Foundation/Foundation.h>

void HelloNSArray() {
    {
        NSArray *names = @[@"小白", @"小璐", @"马青", @"杨重"];
        NSUInteger count = [names count];                   // 4
        NSString  *name1 = [names objectAtIndex:0];         // 小白
        NSUInteger index = [names indexOfObject:@"小白"];     // 0
        NSLog(@"%@ %lu %lu", name1, index, count);
    } {
        NSArray *names = @[@"小白", @"小璐", @"马青", @"杨重"];
        // for
        for (NSUInteger i = 0; i < [names count]; i++) {
            NSLog(@"%@", [names objectAtIndex:i]);
        }
        // for in
        for (NSString *name in names) {
            NSLog(@"%@", name);
        }
        // enumerator
        NSEnumerator *enumerator = [names objectEnumerator];
        id object = nil;
        while (object = [enumerator nextObject]) {
            NSLog(@"%@", object);
        }
        // block
        [names enumerateObjectsUsingBlock:^(id name, NSUInteger i, BOOL *stop) {
            NSLog(@"%lu %@", i, name);
        }];
        // reverse block
        [names enumerateObjectsWithOptions:NSEnumerationReverse
                                usingBlock:^(id name, NSUInteger i, BOOL *stop) {
            NSLog(@"%lu %@", i, name);
        }];
    } {
        // join and split
        NSArray *names = @[@"小白", @"小璐", @"马青", @"杨重"];
        NSString *join = [names componentsJoinedByString:@", "];
        NSArray *split = [join componentsSeparatedByString:@", "];
        NSLog(@"%@", join);
        NSLog(@"%@", split);
    } {
        // sort
        NSArray *nums = @[@4, @6, @1, @3, @2, @5];
        NSArray *sortedNums1 = [nums sortedArrayUsingComparator:(NSComparator)^(id num1, id num2) {
            return [num1 compare:num2];
        }];
        NSLog(@"%@", sortedNums1);
        NSArray *sortedNums2 = [nums sortedArrayUsingSelector:@selector(compare:)];
        NSLog(@"%@", sortedNums2);
    } {
        NSMutableArray *items = [[NSMutableArray alloc] init];
        [items addObject:@"sissie"];
        [items addObject:@"sky"];
        [items addObject:@"playjokes"];
        [items addObject:@"robin"];
        [items addObject:@"hatlonely"];
        [items removeObject:@"hatlonely"];
        [items removeObjectAtIndex:0];
        [items replaceObjectAtIndex:1 withObject:@"sissie"];
        NSLog(@"%@", items);
    } {
        NSMutableArray *nums = [NSMutableArray arrayWithObjects: @4, @6, @1, @3, @2, @5, nil];
        [nums sortUsingSelector:@selector(compare:)];
        NSLog(@"%@", nums);
    }
}
