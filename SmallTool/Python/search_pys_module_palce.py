###############################################################################
#                         search_pys_module_palce.py                          #
# Copyright	    Human
# Author		ASC_8384
# Mail			ASC_8384@foxmail.com
# Website		http://ASC8384.top
# FileName		search_pys_module_palce.py
# Description	输出Py 查找包的路径
# HomepageURL	https://github.com/ASC8384/MyCodeSnippets
# License		CC0
# Time			2018-07-15
###############################################################################

import sys


if __name__ == "__main__":
    for place in sys.path:
        print(place)
