//
//  HelloNSNumber.m
//  HelloObjectiveC
//
//  Created by hatlonely on 16/2/5.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma clang diagnostic ignored "-Wunused-variable"

void HelloNSNumber() {
    {
        NSInteger num1 = 10;
        NSInteger num2 = 20;
        NSInteger num3 = num1 + num2;
        
        NSLog(@"%li", num3);
    } {
        NSNumber *numi = @10;
        NSNumber *numf = @10.0;
        NSNumber *numc = @'C';
        NSNumber *numa = @10;
        
        NSLog(@"%li", (NSInteger)[numi integerValue]);
    } {
        NSNumber *num1 = @10;
        NSNumber *num2 = @20;
        NSNumber *num3 = @([num1 longValue] + [num2 longValue]);
        
        NSLog(@"%@", num3);
    }
}
