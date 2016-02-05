//
//  main.m
//  HelloObjectiveC
//
//  Created by hatlonely on 16/2/5.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#import <Foundation/Foundation.h>

void HelloNSNumber();
void HelloNSString();
void HelloNSArray();
void HelloNSDictionary();
void HelloNSDate();

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        HelloNSNumber();
        HelloNSString();
        HelloNSArray();
        HelloNSDictionary();
        HelloNSDate();
    }
    return 0;
}
