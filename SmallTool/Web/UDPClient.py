from socket import *
import time

serverName = '127.0.0.1'
serverPort = 12345
clientSocket = socket(AF_INET, SOCK_DGRAM)

now = 0
while(1):
    message = input('Input lowercase sentence>\n')
    message = message.encode('utf-8')
    clientSocket.sendto(message, (serverName, serverPort))
    modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
    sec = time.time_ns()
    now += 1
    print('Time(ns): {}'.format(sec))
    print('No.{} is {}'.format(now, modifiedMessage.decode()), end = "\n\n")
