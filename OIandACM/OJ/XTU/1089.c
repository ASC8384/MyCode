#include <stdio.h>

int main()
{
    int x;
    int i, ans;

    while(scanf("%d", &x) == 1){
        for(i = 2; i * i <= x; i++){
            ans = 0;
            while(x % i == 0){
                ++ans;
                x /= i;
            }
            if(ans){
                printf("%d", i);
                if(ans != 1)
                    printf("^%d", ans);
                if(x != 1)
                    printf("*");
                else
                    break;
            }
        }
        if(x != 1)
            printf("%d", x);
        putchar('\n');
    }
    return 0;
}