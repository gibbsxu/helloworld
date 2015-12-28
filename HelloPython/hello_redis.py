#!/usr/env/bin python3
# coding utf-8

import redis


def getting_started():
    r = redis.StrictRedis(host='localhost', port=6379, db=0)
    r.set('foo', 'bar')
    r.get('foo')


def connection_pool():
    pool = redis.ConnectionPool(host='localhost', port=6379, db=0)
    r = redis.Redis(connection_pool=pool)
    r.set('foo', 'bar')
    r.get('foo')


def pipelines():
    r = redis.StrictRedis(host='localhost', port=6379, db=0)
    pipe = r.pipeline()
    pipe.set('foo', 'bar')
    pipe.get('foo')
    for result in pipe.execute():
        print(result)


def main():
    getting_started()
    connection_pool()
    pipelines()


if __name__ == '__main__':
    main()
