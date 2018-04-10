#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time   : 20180410
# @Author : ASC_8384 & Lyrichu
# @Email  : ASC_8384@foxmail.com & 919987476@qq.com
# @File   : save_images.py
'''
@Description:保存知乎某个问题下所有答案的图片
'''
from __future__ import print_function # 使用python3的print方法
from zhihu_oauth import ZhihuClient
import re
import os
import urllib
import urllib3

client = ZhihuClient()
# 登录
client.load_token('token.pkl')
# 加载token文件

id = 48464011
# https://www.zhihu.com/question/48464011(有哪些能体现宇宙之大人类之渺小的图片？)

question = client.question(id)
print(u"问题名称:",question.title)
print(u"回答数量:",question.answer_count)

try:
    os.mkdir(question.title + u"(图片)")
    # 建立存放图片的文件夹
    print(u"目录建立成功", end = "\n\n")
except FileExistsError:
    print(u"目录已存在，但暂不支持断点续传", end = "\n\n")


path = question.title + u"(图片)"

index = 1 # 图片序号
for answer in question.answers:
    content = answer.content # 回答内容
    re_compile = re.compile(r'src="(https://pic\d\.zhimg\.com/.*?\.(jpg|png))".*?')
    # 原句 <img src="(https://pic\d\.zhimg\.com/.*?\.(jpg|png))".*?>
    # 会漏掉一大批图，毕竟有时img 里还会参杂些别的东西
    img_lists = re.findall(re_compile,content)
    if(img_lists):
        for img in img_lists:
            img_url = img[0] # 图片url
            urllib.request.urlretrieve(img_url,path+u"/%d.jpg" % index)
            # 原句 urllib.urlretrieve(img_url,path+u"/%d.jpg" % index)
            # 不过新的python3方法不在原来的路径了
            print(u"成功在封号或封IP前保存第%d张图片" % index)
            index += 1
