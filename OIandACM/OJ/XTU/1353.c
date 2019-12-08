#include <stdio.h>
#include <string.h>
#include <math.h>
 
const int mo = 1e9+7;
 
char s[55];
unsigned long long n;
 
int main()
{
    while(scanf("%s %lld", s, &n) == 2){
        char flag = 1;
        char f = 1;
        int ans = 0;
        int ll = strlen(s);
        int tmp = 0;
        for(int i = 0; i < ll; i++)
            if(s[i] > tmp)
                tmp = s[i];
        unsigned long long a = 0;
        if(tmp < 'A'){
            for(int i = tmp - '0' + 1; i <= 16; i++){
                for(int j = 0; j < ll; j++)
                    a = a * i + s[j] - '0';
                if(a == n){
                    ans = i;
                    break;
                }
                if(a > n)
                    break;
                a = 0;
            }
            if(ans == 0)
                flag = 0;
        }else{
            a = 0;
            for(int i = tmp - 'A' + 11; i <= 16; i++){
                for(int j = 0; j < ll; j++){
                 
                    if(s[j] <= '9')
                        a = a * i + s[j] - '0';
                    else
                        a = a * i + s[j] - 'A' + 10;
                }
                if(a == n){
                    ans = i;
                    break;
                }
                if(a > n)
                    break;
                a = 0;
            }
            if(ans == 0)
                flag = 0;
        }
         
        if(flag)
            printf("%d\n", ans);
        else
            printf("Impossible\n");
    }
    return 0;
}
/**************************************************************
    Problem: 1063
    User: ASC_8384
    Language: C
    Result: 正确
    Time:0 ms
    Memory:1120 kb
****************************************************************/
