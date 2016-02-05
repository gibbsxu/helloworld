//
//  HelloNSDate.m
//  HelloObjectiveC
//
//  Created by hatlonely on 16/2/5.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma clang diagnostic ignored "-Wunused-variable"

void HelloNSDate() {
    {
        // 创建日期
        NSDate *date1 = [NSDate date];
        NSDate *date2 = [NSDate dateWithTimeIntervalSinceNow:60];
        NSDate *date3 = [NSDate dateWithTimeIntervalSince1970:60];
        NSDate *date4 = [date1 dateByAddingTimeInterval:24 * 60 * 60];
        NSTimeInterval seconds1 = [date1 timeIntervalSinceNow];
        NSTimeInterval seconds2 = [date1 timeIntervalSince1970];
        NSLog(@"%@", date1);
    } {
        // 格式化日期
        NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
        [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
        dateFormatter.timeZone = [NSTimeZone timeZoneWithAbbreviation:@"GMT+0800"];
        NSString *dateString = [dateFormatter stringFromDate:[NSDate date]];
        NSLog(@"%@", dateString);
    } {
        NSCalendar *calendar1 = [NSCalendar currentCalendar];
        NSCalendar *calendar2 = [[NSCalendar alloc]
                                 initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
        NSCalendar *calendar3 = [[NSCalendar alloc]
                                 initWithCalendarIdentifier:NSCalendarIdentifierChinese];
        
    } {
        // 计算日期
        NSUInteger dayOfMonth = [[NSCalendar currentCalendar] ordinalityOfUnit:NSCalendarUnitDay
                                                                        inUnit:NSCalendarUnitMonth
                                                                       forDate:[NSDate date]];
        NSDate *date1 = [NSDate date];
        NSDate *date2 = [NSDate dateWithTimeIntervalSinceNow:6 * 24 * 60 * 60];
        NSDateComponents *dateComponents = [[NSCalendar currentCalendar] components:NSCalendarUnitDay
                                                                           fromDate:date1
                                                                             toDate:date2
                                                                            options:0];
        NSLog(@"%ld", (long)[dateComponents day]);
    }
}
