#include <csignal>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

pid_t child_pid[2333];
int n;
int now = 0;
int pid, i;
int flag = 0;

void stopall(int sig){
    // for(int j = n; j; j--){
    for(int j = 1; j <= n; j++){
        // printf("%d %d\n", j, child_pid[j]);
        kill(child_pid[j], SIGUSR2);
        // sleep(1);
        // wait(NULL);
    }
    for(int i = 1; i <= n; i++)
        wait(NULL);
    sleep(1);
    printf("Parent-finished\n");
    _exit(0);
}

void kill_child(int sig){
    // printf("%d\n", sig);
    // printf("Child%d-finished\n", i);
    // _exit(0);
    flag = 1;
}

int main(int argc, char *argv[])
{
    signal(SIGINT, SIG_IGN);
    // signal(SIGQUIT, SIG_IGN);
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        pid = fork();
        child_pid[i] = pid;
        if(pid == -1){
            printf("process of %u create failurely!\n", getpid());
        }else if(pid == 0){ // child and then break
            break;
        }else{ // father and then continue
            continue;
        }
    }
    if(i != n + 1){
        signal(SIGUSR2, kill_child);
        sleep(i);
        now = i;
    }else{
        signal(SIGINT, stopall);
    }
    while(true){
        if(i == n + 1){ // father
            printf("Parent-hello-%d\n",  now);
            now += n + 1;
            sleep(n+1);
        }else{ // son
            if(flag == 1){
                sleep(n - i);
                printf("Child%d-finished\n", i);
                _exit(0);
            }
            printf("Child%d-hello-%d\n", i, now);
            now += n + 1;
            sleep(n+1);
        }
    }
    return 0;
}
