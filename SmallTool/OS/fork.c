#include <stdio.h>
// #include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t p1, p2;
    while((p1 = fork()) == -1);
    if(p1 == 0){
        putchar('c');
    }else{
        while((p2 = fork()) == -1);
        if(p2 == 0){
            putchar('b');
        }else{
            putchar('a');
        }
    }
    putchar('\n');
    return 0;
}
