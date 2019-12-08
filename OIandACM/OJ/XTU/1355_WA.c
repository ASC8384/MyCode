#include <stdio.h>
#include <string.h>
#include <math.h>
 
const int mo = 1e9+7;
 
unsigned long long phi[3000002];
int n = 3000002;
unsigned long long ans[3000002];
int a, b, t;
 
int main()
{
    for(int i = 2; i <= n; i++)
        phi[i] = i;
    for(int i = 2; i <= n; i++)
        if(phi[i] == i)
            for(int j = i; j <= n; j += i)
                phi[j] = phi[j] / i * (i - 1);
    phi[1] = 1;
    for(int i = 1; i < n; i++)
        ans[i] = ans[i-1] + phi[i];
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        printf("%lld\n", ans[b] - ans[a-1]);
    }
    return 0;
}
