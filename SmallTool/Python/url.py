import urllib.parse
import os

while 1:
    form = input()
    to = urllib.parse.unquote(form)
    os.rename(form, to)

