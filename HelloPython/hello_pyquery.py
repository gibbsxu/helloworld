#!/usr/bin/env python3
# coding utf-8

import pyquery


def main():
    html = '<div id="pyquery">pyquery allows you to make jquery queries on xml documents</div>'
    d = pyquery.PyQuery(html)
    d('#pyquery').html('The API is as much as possible the similar to jquery')
    print(d.text())  # The API is as much as possible the similar to jquery

    html = '<div><li>apple</li><li>banana</li><li>orange</li><div>'
    d = pyquery.PyQuery(html)
    index = 1
    for li in d('li').items(''):
        li.html(str(index) + '.' + li.text())
        index += 1
    print(d)  # <div><li>1.apple</li><li>2.banana</li><li>3.orange</li></div>


if __name__ == '__main__':
    main()
