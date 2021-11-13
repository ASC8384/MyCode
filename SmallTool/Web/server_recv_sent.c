#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define PORT 21128
#define ADDRESS "127.0.0.1"
#define BACKLOG 5
#define BUFFER_SIZE 1024

void stop(int sig){
    printf("Bye client\n");
    exit(0);
}

void end(int sig){
    printf("End\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //绑定
    struct sockaddr_in serverSocket;
    memset(&serverSocket, 0, sizeof(serverSocket));
    serverSocket.sin_family = AF_INET;
    serverSocket.sin_addr.s_addr = inet_addr(ADDRESS);
    serverSocket.sin_port = htons(PORT);
    bind(serv_sock, (struct sockaddr*)&serverSocket, sizeof(serverSocket));
    //监听
    listen(serv_sock, BACKLOG);
    //接收
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    if(clnt_sock == -1){
        printf("Connection failed\n");
        exit(-1);
    }else{
        printf("Listening\n");
    }

    pid_t pid = fork();
    while(1){
        char sentence[BUFFER_SIZE];
        memset(sentence, 0, sizeof(sentence));
        if(pid > 0){ // 发出
            signal(SIGINT, stop);
            signal(SIGUSR1, end);
            if(fgets(sentence, BUFFER_SIZE, stdin) != NULL){
                send(clnt_sock, sentence, sizeof(sentence), 0);
            }
        }else if(pid == 0){ // 接受
            if(recv(clnt_sock, sentence, sizeof(sentence), 0) > 0){
                printf("From client: %s\n", sentence);
            }else{
                kill(getppid(), SIGUSR1);
                exit(0);
            }
        }
    }

    return 0;
}
