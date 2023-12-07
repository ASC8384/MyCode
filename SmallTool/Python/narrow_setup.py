# Original author: muzhan
# Modifier: ASC_8384
# GPU 排队脚本
import os
import sys
import time
import argparse


def gpu_info(gpu_index=0):
    info = os.popen("nvidia-smi|grep %").read().split("\n")[gpu_index].split("|")
    power = int(info[1].split()[-3][:-1])
    memory = int(info[2].split("/")[0].strip()[:-3])
    return power, memory


def narrow_setup(interval=2, gpu_index=0):
    gpu_power, gpu_memory = gpu_info(gpu_index)
    i = 0
    while gpu_memory > 5000 or gpu_power > 60:  # set waiting condition
        gpu_power, gpu_memory = gpu_info(gpu_index)
        i = i % 5
        symbol = "monitoring: " + ">" * i + " " * (10 - i - 1) + "|"
        gpu_power_str = "gpu power:%d W |" % gpu_power
        gpu_memory_str = "gpu memory:%d MiB |" % gpu_memory
        sys.stdout.write("\r" + gpu_memory_str + " " + gpu_power_str + " " + symbol)
        sys.stdout.flush()
        time.sleep(interval)
        i += 1

    cmd = (
        "CUDA_VISIBLE_DEVICES="
        + str(gpu_index)
        + """
        启动脚本"""
    )
    print("\n" + cmd)
    os.system(cmd)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--gpu", default=0, type=int, help="单卡")
    narrow_setup(gpu_index=parser.parse_args().gpu)
