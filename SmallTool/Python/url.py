###############################################################################
#                                   url.py                                    #
# Copyright		Human
# Author		ASC_8384
# Mail			ASC_8384@foxmail.com
# Website		http://ASC8384.top
# FileName		url.py
# Description	编码转换: 把某些网站上的乱码转为我的人所可理解的文字
# HomepageURL	https://github.com/ASC8384/MyCodeSnippets
# License		CC0
# Time			2018-07-15
###############################################################################

import urllib.parse
import os

def change(sourse, charset):
    if charset == True:
        ret = urllib.parse.unquote(sourse, 'utf-8')
    else:
        ret = urllib.parse.unquote(sourse, 'gbk')
    return ret

def init():
    name = input()
    if name == "q" or name == "Q":
        return 0
    elif name == "g" or name == "G":
        return 8
    elif name == 'u' or name == 't' or name == 'f':
        return 7
    elif name == "z" or name == "Z" or name == 'b' or name == 'B':
        return 6
    else:
        return name


if __name__ == "__main__":
    active = True
    char = True
    backupa = ''
    backupb = ''

    while (active):
        putin = init()
        if putin == 0:
            active = False
        elif putin == 8:
            char = False
        elif putin == 7:
            char = True
        elif putin == 6:
            os.rename(backupa, backupb)
            print ('撤消成功！')
        else:
            backupb = putin[:]
            backupa = change(putin, char)
            os.rename(putin, backupa)
            print (backupa)

