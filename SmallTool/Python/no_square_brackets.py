import os
import re

while 1:
    form = input()
    to = re.sub('(【.*】)', '', form)
    to = re.sub('(\[.*\])', '', to)
    print (to)
    os.rename(form,to)
