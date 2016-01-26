#!/usr/bin/env python3
# coding utf-8

import re


def re_match():
    # 精确匹配,头部
    pattern = re.compile(r'(\w+)@(\w+)\.com$')
    match = pattern.match('hatlonely@foxmail.com')
    print(match.group())  # hatlonely@foxmail.com
    print(match.groups())  # ('hatlonely', 'foxmail')


def re_search():
    # 部分匹配
    pattern = re.compile(r'(\w+)@(\w+)\.com')
    match = pattern.search('contact hatlonely@foxmail.com xx')
    print(match.group())  # hatlonely@foxmail.com
    print(match.groups())  # ('hatlonely', 'foxmail')


def re_sub():
    # 正则替换
    pattern = re.compile(r'(\w+)@(\w+)\.com')
    result = pattern.sub(r'server:\2 user:\1', 'hatlonely@foxmail.com')
    print(result)  # server:foxmail user:hatlonely

    result = re.sub(r'(\w+)@(\w+)\.com', r'server:\2 user:\1', 'hatlonely@foxmail.com')
    print(result)  # server:foxmail user:hatlonely


def re_findall():
    pattern = re.compile(r'\d+')
    result = pattern.findall('one1two2three3four4')
    print(result)  # ['1', '2', '3', '4']

    result = re.findall(r'\d+', 'one1two2three3four4')
    print(result)  # ['1', '2', '3', '4']


def main():
    re_match()
    re_search()
    re_sub()
    re_findall()


if __name__ == '__main__':
    main()
