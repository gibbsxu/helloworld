#!/usr/bin/env python3
# coding utf-8

import datetime
import time

# 获取当前时间
def __1():
    now = datetime.datetime.now()
    print(now)
    print(now.strftime('%Y-%m-%d %H:%M:%S'))
    print(now.microsecond)
    print(now.year)
    print(now.month)
    print(now.day)
    print('这是一年中的第{0}天'.format(now.strftime('%j')))
    print(now.weekday())    # Monday is 0


# 创建时间
def __2():
    dt = datetime.datetime.strptime("2016-01-10 12:25:12", "%Y-%m-%d %H:%M:%S")
    print(dt)


# 时间计算
def __3():
    now = datetime.datetime.now()
    delta = datetime.timedelta(days=5)
    delta = datetime.timedelta(seconds=5 * 3600 * 24)
    delta = datetime.timedelta(microseconds=5 * 3600 * 24 * 1000000)
    day5 = now + delta
    print('5天后的时间{0}'.format(day5))
    delta = day5 - now
    print(delta.days)
    print(delta.seconds)
    print(delta.microseconds)


# unixtime
def __4():
    print(time.time())
    print(time.mktime(time.strptime('2016-01-10 12:25:12', '%Y-%m-%d %H:%M:%S')))
    print(time.strptime('2016-01-10 12:25:12', '%Y-%m-%d %H:%M:%S'))

def main():
    __1()
    __2()
    __3()
    __4()
    pass


if __name__ == '__main__':
    main()
