from socket import *
import time

serverPort = 12345 # 端口
serverSocket = socket(AF_INET, SOCK_DGRAM) # 创造套接字，第一个参数指示使用 IPv4，第二个参数指示使用 UDP 套接字
serverSocket.bind(('', serverPort)) # 将端口与服务器绑定在一起

print ('The server is ready to receive', end='\n\n')

now = 0
while(1):
    message, clientAddress = serverSocket.recvfrom(2048) # 接收信息，第一个保存数据，第二个保存地址，2048 为缓存长度
    modifiedMessage = message.upper() # 转大写
    serverSocket.sendto(modifiedMessage, clientAddress) # 向目标发送分组
    sec = time.time_ns()
    now += 1
    print('Time(ns): {}'.format(sec))
    print('now is {} times'.format(now))
    print(message.decode() + '\n')
    
