###############################################################################
#                            no_square_brackets.py                            #
# Copyright     Human
# Author		ASC_8384
# Mail			ASC_8384@foxmail.com
# Website		http://ASC8384.top
# FileName		no_square_brackets.py
# Description	去除文件名中的[]、【】符号
# HomepageURL	https://github.com/ASC8384/MyCodeSnippets
# License		CC0
# Time			2018-07-15
###############################################################################

import os
import re

def no_square_brackets(source):
    """
    去除文件名中的[]、【】符号
    """
    change = re.sub('(【.*】)', '', source)
    change = re.sub('(\[.*\])', '', change)
    print (change)
    os.rename(source, change)


if __name__ == "__main__":
    active = True
    while (active):
        filename = input()
        if filename == "q" or filename == "Q":
            active = False
        else:
            no_square_brackets(filename)
