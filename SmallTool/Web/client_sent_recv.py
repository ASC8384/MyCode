import socket
import sys
import threading

serverName = 'localhost'
serverPort = 21128

clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientSocket.connect((serverName, serverPort))
print('连接服务器成功')

def runn():
    while True:
        sentence = input('')
        clientSocket.send(sentence.encode("utf-8"))

background_thread = threading.Thread(target=runn)
background_thread.daemon = True
background_thread.start()

while True:
    try:
        message = clientSocket.recv(1024)
        if not message:
            print("End\n")
            clientSocket.close()
            sys.exit()
        else:
            print('From server: ' + message.decode('utf-8'), end='')
    except KeyboardInterrupt:
        print('Bye Server')
        sys.exit()

