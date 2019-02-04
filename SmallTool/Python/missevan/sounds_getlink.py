###############################################################################
#                                sounds_getlink.py                            #
# Copyright     Human
# Author		ASC_8384
# Mail			ASC_8384@foxmail.com
# Website		http://ASC8384.top
# FileName		sounds_getlink.py
# Description	获取音频链接
# HomepageURL	https://github.com/ASC8384/MyCodeSnippets
# License		CC0
# Time			2019-2-4 23:03:44
###############################################################################

import os
import time
import requests
# import chardet
from bs4 import BeautifulSoup
import pandas as pd


def runing_time(func):
    def wrapper(*args, **kwargs):
        print("{:<15}'s args len is {}".format(func.__name__, len(args)))
        stt = time.time()
        ret = func(*args, **kwargs)
        edt = time.time()
        print(edt - stt)
        return ret

    return wrapper


# def get_data(url, retries=5):
def get_data(url):
    # """默认重试5次"""
    mycookie = (
        "自己填写"
    )
    headers = {
        'User-Agent':
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:64.0) Gecko/20100101 Firefox/64.0",
        'Host':
        "www.missevan.com",
        'Referer':
        "https://www.missevan.com/sound/m/71",
        'Cookie':
        mycookie
    }

    try:
        data = requests.get(url, headers=headers, timeout=8)
        # print(data.status_code)
    except requests.exceptions.ConnectionError as identifier:
        print("请求错误：", url)
        print("错误详情：", identifier)
        data = None

    if (data is not None) and (500 <= data.status_code < 600):
        # if (retries > 0):
        print("服务器错误")
        # print("第{}遍重试".format(6 - retries))
        time.sleep(1)
        # retries -= 1
        # get_data(url, retries)

    return data


# def save_data(titles, soundurls, longs, viewcnts, comments):
def save_data(titles, soundurls, longs):
    result = pd.DataFrame()
    result["titles"] = titles
    result["soundurls"] = soundurls
    result["longs"] = longs
    # result["viewcnts"] = viewcnts
    # result["comments"] = comments
    result.to_csv(
        "missevan_url.csv",
        index=None,
        encoding="utf-8",
        mode="a",
        header=False
    )


# def parse_data(data, titles, soundurls, longs, viewcnts, comments):
def parse_data(data, titles, soundurls, longs):

    classes = [
        "vw-subcatalog-contant fc-leftcontent-block floatleft",
        "vw-frontsound-container fc-hoverheight-container floatleft",
        "vw-frontsound-image floatleft"
        # class_3 = "vw-frontsound-info fc-hoverheight-music_0_objects_point1"
        # class_4 = "vw-frontsound-viewcount floatleft"
        # class_5 = "vw-frontsound-commentcount floatleft"
    ]

    # charset = chardet.detect(data.content)
    # data.encoding = charset["encoding"]
    data.encoding = 'UTF-8'

    soup = BeautifulSoup(data.text, "lxml")
    sounds = soup.find("div", {"class": classes[0]})
    sounds = sounds.find_all("div", {"class": classes[1]})
    for sound in sounds:
        sound = sound.find("a")
        title = sound.get("title")
        titles.append(title.strip())
        soundurl = sound.get("href")
        soundurls.append("https://www.missevan.com" + soundurl.strip())
        # try:
        long = sound.find("div", {"class": classes[2]})
        long = long.find("div").get_text()
        longs.append(long.strip())

        # sound = sound.find("div", {"class": class_3})
        # viewcnt = sound.find("div", {"class": class_4}).get_text()
        # viewcnts.append(viewcnt.strip())
        # comment = sound.find("div", {"class": class_5}).get_text()
        # comments.append(comment.strip())

    #  save_data(titles, soundurls, longs, viewcnts, comments)
    # return titles, soundurls, longs, viewcnts, comments
    return titles, soundurls, longs


def set_cwd():
    path = os.getcwd() + "/missevan"
    if not os.path.isdir(path):
        os.mkdir(path)
    os.chdir(path)


if __name__ == "__main__":
    # ID = 71
    ori = "https://www.missevan.com/sound/m?id=71&order=0&p="
    # set_cwd()
    # print(os.getcwd())

    # 1 -> 266页

    for i in range(1, 266):
        titles = []
        soundurls = []
        longs = []
        # viewcnts = []
        # comments = []
        url = ori + str(i)
        # url = "https://www.missevan.com/sound/m/71/"
        data = get_data(url)
        # print(data.text)
        # titles, soundurls, longs, viewcnts, comments =\
        #     parse_data(data, titles, soundurls, longs, viewcnts, comments)
        # save_data(titles, soundurls, longs, viewcnts, comments)
        titles, soundurls, longs = parse_data(data, titles, soundurls, longs)
        time.sleep(3)
        save_data(titles, soundurls, longs)
