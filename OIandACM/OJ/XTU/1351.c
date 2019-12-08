#include <stdio.h>
#include <string.h>
 
int main()
{
    char s[2333];
    int a[40];
    while(scanf("%s", s) == 1){
        memset(a, 0, sizeof(a));
        int ll = strlen(s);
        for(int i = 0; i < ll; i++){
            a[s[i]-'a']++;
        }
        int flag = 1;
        for(int i = 0; i < 40; i++)
            if(a[i] & 1){
                flag = 0;
                break;
            }
        if(flag == 0){
            for(int i = 0; i < 40; i++)
                if(a[i] & 1)
                    flag++;
            if(flag != 1)
                flag = 0;
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
/**************************************************************
    Problem: 1061
    User: ASC_8384
    Language: C
    Result: 正确
    Time:20 ms
    Memory:1120 kb
****************************************************************/
