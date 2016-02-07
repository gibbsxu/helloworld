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
void HelloNSSet();
void HelloNSFileManager();

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        HelloNSNumber();
        HelloNSString();
        HelloNSArray();
        HelloNSDictionary();
        HelloNSDate();
        HelloNSSet();
        HelloNSFileManager();
    }
    return 0;
}
