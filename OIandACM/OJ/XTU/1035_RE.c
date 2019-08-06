#include <stdio.h>
//#include <string.h>

int main()
{
    int k;
    int n, stk[666666], in[666666];
    //int t;
    int i, j, h, pos, top, flag;
    scanf("%d", &k);
    for(i = 0; i < k; i++){
        scanf("%d", &n);
        //memset(stk, 0, )
        for(j = 1; j <= n; j++)
            scanf("%d", &in[j]);
        pos = top = 0;
        flag = 1;
        for(j = 1; j <= n; j++){
            for(h = pos+1; h <= in[j]; h++){
                pos = h;
                stk[top++] = h; 
            }//压到底啊
            if(stk[--top] != in[j]){
                //printf("NO\n");
                flag = 0;
                break;
            }
        }
        (flag) ? printf("Yes\n") : printf("No\n");
    }
    return 0;
}