#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pipefd[2];
    pid_t p1, p2;
    char outpipe[233], inpipe[233];
    pipe(pipefd);
    while((p1 = fork()) == -1);
    if(p1 == 0){
        lockf(pipefd[1], F_LOCK, 0);
        write(pipefd[1], "Child 1 is sending a message!\n", 50);
        sleep(1);
        lockf(pipefd[1], F_ULOCK, 0);
    }else{
        while((p2 = fork()) == -1);
        if(p2 == 0){
            lockf(pipefd[1], F_LOCK, 0);
            write(pipefd[1], "Child 2 is sending a message!\n", 50);
            sleep(1);
            lockf(pipefd[1], F_ULOCK, 0);
        }else{
            wait(NULL);
            read(pipefd[0], inpipe, 50);
            printf("%s", inpipe);
            wait(NULL);
            read(pipefd[0], inpipe, 50);
            printf("%s", inpipe);
        }
    }
    return 0;
}
