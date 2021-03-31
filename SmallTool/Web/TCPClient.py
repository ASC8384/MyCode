import socket

serverName = 'localhost'
serverPort = 12000

clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientSocket.connect((serverName, serverPort))

sentence = input('Input lowercase sentence:\n')
clientSocket.send(sentence.encode("utf-8"))

modifiedMessage = clientSocket.recv(1024)
print('From server:\n' + modifiedMessage.decode('utf-8'))

clientSocket.close()
