'''
@Copyright	    Human
@Author		    ASC_8384
@Mail		    ASC_8384@foxmail.com
@Website		http://ASC8384.top
@FileName	    save_answer_all_images.py
@Description	保存知乎某个问题下所有未折叠答案的图片
@HomepageURL	https://github.com/ASC8384/MyCodeSnippets
@License		CC0
@Time	        2018-07-18
'''
from zhihu_oauth import ZhihuClient
import re
import os
import time
import requests

client = ZhihuClient()
# 登录
client.load_token('token.pkl')
# 加载token文件

id = 48464011
# https://www.zhihu.com/question/48464011(有哪些能体现宇宙之大人类之渺小的图片？)

question = client.question(id)
print(u"问题名称:", question.title)
total = question.answer_count
print(u"回答数量:", total)

path = question.title + "(图片)"
try:
    os.mkdir(path)
    # 建立存放图片的文件夹
    print(u"目录建立成功", end = "\n\n")
except FileExistsError:
    print(u"目录已存在，目测下次重构时就可以支持断点续传了", end = "\n\n")

headers = {'User-Agent': "Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36" +\
    "(KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36"}
# U-A 标识


index = 1
# 图片序号, 断点last + 1
number = 1
# 答案序号, 断点between


for answer in question.answers.jump(number - 1):
    print(u"第%d个回答，还剩%d个回答" % (number, total - number))

    content = answer.content
    # 回答内容
    re_compile = re.compile(r'data-original="(https://pic\d\.zhimg\.com/.*?\.(jpg|png|gif|jpeg))".*?')
    #  使用正则，下次重构考虑soup
    #  获取原始图片，而非缩略图

    img_lists = re.findall(re_compile,content)
    if(img_lists):
    # 是否存在图片
        for img in img_lists:
            img_url = img[0]
            # 图片url
            split = img_url.split('.')
            fail = split.pop()
            # 保证图片格式，不过目测没软用

            filename = u"/%d-%s-%d.%s" % (number, index, answer.id, fail)

            response = requests.get(img_url, headers=headers)
            with open(path+filename, 'wb') as f:
                f.write(response.content)
                # 保存图片

            index += 1
            time.sleep(0.3)

        print(u"成功在封号或封IP前保存第%d张图片" % index)

    time.sleep(2)
    number += 1
    # 最简单的防ban 方式


print(u"\n\n可喜可贺! %d 都被你爬下来了！" % index)

tmptmp = input('换行结束：')
