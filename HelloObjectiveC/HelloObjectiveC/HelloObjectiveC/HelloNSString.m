//
//  HelloNSString.m
//  HelloObjectiveC
//
//  Created by hatlonely on 16/2/5.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#import <Foundation/Foundation.h>

void HelloNSString() {
    {
        NSString *str1 = @"阳光，我是来像你道歉的";
        NSString *str2 = [NSString stringWithUTF8String:"虽然我们之间间隔着厚厚的霾"];
        NSString *str3 = [NSString stringWithFormat:@"%@", @"但我还是想对你说，你是公平的"];
        NSString *str4 = [NSString stringWithCString:"是我们犯了错，让自己陷进了深深的混沌里"
                                            encoding:NSUTF8StringEncoding];
        NSLog(@"%@, %@, %@, %@", str1, str2, str3, str4);
    } {
        NSString *str1 = @"我该怎么向你道歉";
        NSString *str2 = @"我该怎么向你道歉";
        [str1 isEqualToString:str2];
        [str1 compare:str2] == NSOrderedSame;                   // true
        [str1 compare:str2] == NSOrderedAscending;              // false
        [str1 caseInsensitiveCompare:str2] == NSOrderedSame;    // true
        [str1 hasPrefix:@"我"];      // true
        [str1 hasSuffix:@"道歉"];    // true
    } {
        NSString *str1 = @"abcdefghijklmnopqrstuvwxyz";
        NSString *str2 = [str1 uppercaseString];                // ABCDEFGHIJKLMNOPQRSTUVWXYZ
        NSString *str3 = [str1 capitalizedString];              // Abcdefghijklmnopqrstuvwxyz
        NSLog(@"%@", str1);
        NSLog(@"%@", str2);
        NSLog(@"%@", str3);
    } {
        NSString *str1 = @"abcdefghijklmnopqrstuvwxyz";
        NSRange range  = [str1 rangeOfString:@"hijk"];          // (7, 4)
        NSLog(@"(%lu, %lu)", (unsigned long)range.location, (unsigned long)range.length);
    } {
        NSString *str1 = @"天空是蓝蓝的，空气是清新的，阳光是明媚的";
        NSString *sub1 = [str1 substringToIndex:7];                     // 天空是蓝蓝的，
        NSString *sub2 = [str1 substringWithRange:NSMakeRange(7, 7)];   // 空气是清新的，
        NSString *sub3 = [str1 substringFromIndex:14];                  // 阳光是明媚的
        
        NSLog(@"%@", sub1);
        NSLog(@"%@", sub2);
        NSLog(@"%@", sub3);
    } {
        NSMutableString *str = [[NSMutableString alloc] initWithString:@"我知道你会说"];
        [str appendFormat:@"，%@", @"你们太贪婪了"];   // 我知道你会说，你们太贪婪了
        [str insertString:@"才能让我们回到童年的记忆中，" atIndex:0];
        NSLog(@"%@", str);
    }
}
