import requests

headers = {
    "Host": "www.missevan.com",
    "User-Agent":
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:71.0) Gecko/20100101 Firefox/71.0",
    "Accept": "application/json, text/javascript, */*; q=0.01",
    'Accept-Encoding': 'gzip, deflate, br',
    "Accept-Language": "zh-CN",
    "X-Requested-With": "XMLHttpRequest",
    "DNT": "1",
    # "Referer": "https://www.missevan.com/sound/player?id=56620",
    # "Cookie":
}
prv1 = "https://www.missevan.com/sound/getsound?soundid="
prv2 = "https://www.missevan.com/sound/player?id="


def get_sound_detail(id):

    headers["Referer"] = prv2 + str(id)
    try:
        response = requests.get(prv1 + str(id), headers=headers)
        if response.status_code == 200:
            return response.json()
    except requests.ConnectionError as e:
        print(str(id) + ":", end='')
        print('Error', e.args)
