#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int now, last;
    int ans = 1;
    // bool flg = false;
    int flg = 0;
    scanf("%d", &n);
    scanf("%d", &now);
    while(--n){
        last = now;
        scanf("%d", &now);
        if(now != last){
            if(flg ^ (now < last)){
                ans++;
                flg = (now < last);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
