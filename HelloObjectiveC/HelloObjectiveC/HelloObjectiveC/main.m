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

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        HelloNSNumber();
        HelloNSString();
        HelloNSArray();
        HelloNSDictionary();
    }
    return 0;
}
