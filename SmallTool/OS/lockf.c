#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t p1, p2;
    const int fd = 1; // stdout

    while((p1 = fork()) == -1)
        continue;
    if(p1 == 0){
        while(lockf(fd, F_LOCK, 0) != 0)
            continue;
        for(int i = 1; i <= 23; i++)
            printf("%d\t:This is the 1st child process\n", i);
        lockf(fd, F_ULOCK, 0);
    }else{
        while((p2 = fork()) == -1)
            continue;
        if(p2 == 0){
            while(lockf(fd, F_LOCK, 0) != 0)
                continue;
            for(int i = 1; i <= 23; i++)
                printf("%d\t:This is the 2nd son process\n", i);
            lockf(fd, F_ULOCK, 0);
        }else{
            while(lockf(fd, F_LOCK, 0) != 0)
                continue;
            for(int i = 1; i <= 23; i++)
                printf("%d\t:This is the parent process\n", i);
            lockf(fd, F_ULOCK, 0);
        }
    }
    putchar('\n');
    return 0;
}
