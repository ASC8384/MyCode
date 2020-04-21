'''
@Author       : ASC_8384
@License      : CC0
@Website      : http://www.ASC8384.top
@Date         : 2020-04-01 22:17:30
@LastEditTime : 2020-04-06 20:40:16
@Description  : win 下去除剪切板中的[]、【】符号，转为两个空格
'''

import pyperclip
import re


###
# @description: 去除[]、【】符号，转为两个空格
# @param string
# @return: string
###
def no_square_brackets(source):
    #  source = re.sub('(【.*】)', "  ", source)
    source = re.sub('(\[.*\])', '  ', source)
    return source


if __name__ == "__main__":
    flag_value = ""
    while True:
        try:
            recent_value = pyperclip.paste()
            if flag_value != recent_value:
                recent_value = no_square_brackets(recent_value)
                pyperclip.copy(recent_value)
                print("Value changed: %s" % str(recent_value))
                print("Now paste value: %s" % str(pyperclip.paste()))
                flag_value = recent_value
        except KeyboardInterrupt:
            break
