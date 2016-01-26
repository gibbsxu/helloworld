#!/usr/bin/env python3
# coding utf-8

import httplib2


def main():
    http = httplib2.Http('.cache')
    response, content = http.request('http://www.baidu.com')
    print(response)
    print(content)


if __name__ == '__main__':
    main()
