'''
@Copyright  	Human
@Author	    	ASC_8384
@Mail		    ASC_8384@foxmail.com
@Website	    http://ASC8384.top
@FileName	    basic_information.py
@Descriptio 	基础信息
@HomepageURL    https://github.com/ASC8384/MyCodeSnippets
@License	    CC0
@Time	        2018-07-19
'''

from zhihu_oauth import ZhihuClient

client = ZhihuClient()

client.load_token('token.pkl')

me = client.me()

print('昵称：', me.name)
print('一句话介绍：', me.headline)

print('个人简介：', me.description, end="\n\n")

print('关注的话题：', me.following_topic_count)
print('关注了：', me.following_count)
print('关注者：', me.follower_count)
print('关注的专栏', me.following_column_count)

print('获得赞同：', me.voteup_count)
print('获得感谢', me.thanked_count)

print('回答：', me.answer_count)
print('提问：', me.question_count)
print('收藏夹：', me.collection_count)
print('文章', me.articles_count)
