from zhihu_oauth import ZhihuClient
from zhihu_oauth.exception import NeedCaptchaException
client = ZhihuClient()
user = '+862333333333'
pwd = '6666666'
try:
    client.login_in_terminal(user, pwd)
    print(u"登陆成功!")
except NeedCaptchaException: # 处理要验证码的情况
    # 保存验证码并提示输入，重新登录
    with open('a.gif', 'wb') as f:
        f.write(client.get_captcha())
    captcha = input('please input captcha:')
    client.login_in_terminal(user, pwd, captcha)
    print(u"登陆成功!")

client.save_token('token.pkl') # 保存token
# 必须在 client 已经处于登录状态时才能使用
#有了token之后，下次登录就可以直接加载token文件了
# client.load_token('filename')
# client.login_in_terminal() # or ('email@example.com', 'password')
