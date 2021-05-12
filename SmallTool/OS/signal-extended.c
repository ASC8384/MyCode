#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

pid_t p1, p2;

void stopall(int sig){
    printf("stopall: %d\n", sig);
    // printf("p1: %d ; p2: %d\n", p1, p2);
    kill(p1, SIGUSR1);
    kill(p2, SIGUSR2);
}

void kill_p1(int sig){
    printf("kill_p1: %d\n", sig);
    printf("Child Processl1 is killed by parent!\n");
}

void kill_p2(int sig){
    printf("kill_p2: %d\n", sig);
    printf("Child Processl2 is killed by parent!\n");
}

int main(int argc, char *argv[])
{
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    while((p1 = fork()) == -1)
        continue;
    if(p1 == 0){
        printf("This is the 1st child process\n");
        signal(SIGUSR1, kill_p1);
        pause();
    }else{
        while((p2 = fork()) == -1)
            continue;
        if(p2 == 0){
            printf("This is the 2nd child process\n");
            signal(SIGUSR2, kill_p2);
            pause();
        }else{
            signal(SIGINT, stopall);
            wait(NULL);
            wait(NULL);
            printf("Parent Process is killed!\n");
        }
    }
    return 0;
}
