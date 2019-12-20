###############################################################################
#                                 data_cleaning.py                            #
# Copyright     Human
# Author		ASC_8384
# Mail			ASC_8384@foxmail.com
# Website		http://ASC8384.top
# FileName		data_cleaning.py
# Description	音频链接数据清洗
# HomepageURL	https://github.com/ASC8384/MyCodeSnippets
# License		CC0
# Time			2019-2-4 23:04:49
###############################################################################

import pandas as pd

data = pd.read_csv('./missevan_url.csv')

data = data.drop_duplicates(keep='first')

data.to_csv(
    './missevan_url.csv',
    index=None,
    encoding="utf-8",
)
