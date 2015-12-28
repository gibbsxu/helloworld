#!/usr/bin/env python3
# coding utf-8

"""
@Author hatlonely
@Date 2015/12/23
@See http://redis.io/topics/mass-insert
@Description redis数据导入协议,将[ key | value ]格式的转换成redis协议格式
    用法: python3 redis_mass_insert.py <filename> <output>
"""


import sys


def gen_redis_proto(*args) -> str:
    """
    由命令生成redis协议格式

    :param args: 命令字符串,如: SET key value
    :return: 该命令对应的redis协议
    """
    proto = ''
    proto += '*{0}\r\n'.format(len(args))
    for arg in args:
        proto += '${0}\r\n'.format(len(arg))
        proto += '{0}\r\n'.format(arg)
    return proto


def mass_insert(input=None, output=None) -> None:
    """
    输入\t分割的文本文件,文件格式[ key | value ]
    输出redis协议文件,redis协议文件见:http://redis.io/topics/mass-insert

    :param input: 输入文件名,为空将读入标准输入
    :param output: 输出文件名,为空将输出标准输出
    """
    try:
        fout = open(output, 'w') if output else sys.stdout
        fin  = open(input, 'r')  if input  else sys.stdin

        linenum = 0
        for line in fin:
            linenum += 1
            kv = line.strip("\r\n").split("\t")
            if len(kv) == 2:
                fout.write(gen_redis_proto("SET", kv[0], kv[1]))
            else:
                print('parse line failed at line[{0}]. expect [key | value] format.'.format(linenum))
        fout.flush()
        fout.close()
    except Exception as e:
        print(e)


def usage():
    print('{0} [input] [output]'.format(sys.argv[0]))
    print('    -input    输入文件,为空将从标准输入读取')
    print('    -output   输出文件,为空将输出到标准输出')
    print('eg: {0} kv.txt redis.rb'.format(sys.argv[0]))


def main():
    if len(sys.argv) == 2 and (sys.argv[1] == '-h' or sys.argv[1] == '--help'):
        usage()
        return

    input  = sys.argv[1] if len(sys.argv) >= 2 else None
    output = sys.argv[2] if len(sys.argv) >= 3 else None
    mass_insert(input, output)


if __name__ == '__main__':
    main()
