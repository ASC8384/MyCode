import csv
import json
import os
from time import sleep
import random
from get_sound_detail import get_sound_detail
# from cheat_capcha import cheat_captcha


def set_cwd():
    path = os.getcwd() + "/detail_json"
    if not os.path.isdir(path):
        os.mkdir(path)
    os.chdir(path)


def get_id(str):
    return str.split("/")[-1]


if __name__ == '__main__':
    set_cwd()

    with open("../missevan/missevan_url.csv", "r",
              encoding="utf-8") as csv_file:
        reader = csv.reader(csv_file)
        row = next(reader)
        # for item in range(1, 4988):
        # row = next(reader)
        for item in range(1, 5198):
            sleep(random.uniform(0.5, 11.5))
            row = next(reader)
            detail_json = get_sound_detail(get_id(row[1]))
            # try:
            if detail_json["success"] is True:
                with open(str(item) + ".json", "w", encoding="utf-8") as file:
                    file.write(
                        json.dumps(detail_json, indent=4, ensure_ascii=False))
            else:
                with open("remembered.txt", "a", encoding="utf-8") as file:
                    file.write(str(item) + ",")
            print(str(item) + "-" + row[0] + ":" + str(detail_json["success"]))
            # except TypeError:
            #     cheat_captcha()
