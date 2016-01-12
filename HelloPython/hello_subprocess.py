#!/usr/bin/env python3
# coding utf-8

import subprocess

def main():
    output = subprocess.getoutput('ls')
    print(output)

    (status, output) = subprocess.getstatusoutput('pwd')
    if status == 0:
        print(output)


if __name__ == '__main__':
    main()
