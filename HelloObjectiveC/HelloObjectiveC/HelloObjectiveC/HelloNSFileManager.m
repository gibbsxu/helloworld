//
//  HelloNSFileManager.m
//  HelloObjectiveC
//
//  Created by hatlonely on 16/2/6.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma clang diagnostic ignored "-Wunused-variable"

void HelloNSFileManager() {
    {
        NSString *username = NSUserName();
        NSString *fulluser = NSFullUserName();
        NSString *homedir  = NSHomeDirectory();
        NSString *tempdir  = NSTemporaryDirectory();
        NSLog(@"%@, %@, %@, %@", username, fulluser, homedir, tempdir);
    } {
        NSFileManager *fileManager = [[NSFileManager alloc] init];
        NSString *currpath         = [fileManager currentDirectoryPath];
        NSString *fullpath         = [currpath stringByAppendingPathComponent:@"text.txt"];
        NSString *extension        = [fullpath pathExtension];  // txt
        NSArray *component         = [fullpath pathComponents];
        NSLog(@"%@", component);
    } {
        NSFileManager *fileManager = [[NSFileManager alloc] init];
        [fileManager fileExistsAtPath:@"./text.txt"];
        [fileManager copyItemAtPath:@"text.txt" toPath:@"text.txt.bk" error:nil];
        [fileManager moveItemAtPath:@"text.txt.bk" toPath:@"text.txt" error:nil];
        [fileManager linkItemAtPath:@"text.txt" toPath:@"text.txt.bk" error:nil];
        [fileManager removeItemAtPath:@"text.txt" error:nil];
    }
}
