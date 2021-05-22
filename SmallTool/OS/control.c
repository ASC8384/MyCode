#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t p1, p2;
    while((p1 = fork()) == -1);
    if(p1 == 0){
        for(int i = 1; i <= 23; i++)
            printf("%d\t:This is the 1st child process (pid:%d, parent pid:%d)\n", i, getpid(), getppid());
    }else{
        while((p2 = fork()) == -1);
        if(p2 == 0){
            for(int i = 1; i <= 23; i++)
                printf("%d\t:This is the 2nd son process (pid:%d, parent pid:%d)\n", i, getpid(), getppid());
        }else{
            for(int i = 1; i <= 23; i++)
                printf("%d\t:This is the parent process (pid:%d)\n", i, getpid());
        }
    }
    putchar('\n');
    return 0;
}
