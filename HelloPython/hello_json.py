#!/usr/bin/env python3
# coding: utf-8

import json


def main():
    jsonstr = """{
        "name": "hatlonely",
        "email": "hatlonely@gmail.com",
        "age": 9,
        "array": ["a", "b"]
    }"""

    jsonobj = json.loads(jsonstr)

    print(json.dumps(jsonobj))


if __name__ == '__main__':
    main()
