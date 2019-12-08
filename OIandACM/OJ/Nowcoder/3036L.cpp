#include <bits/stdc++.h>
using namespace std;
 
int a[23333];
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    int n, ll, m;
    cin >> n >> ll >> m;
    double ans = 0;
    for(int i = 1; i <= n; i++){
        ans += (double)ll / 2.0 / (double)i;
    }
    printf("%.4lf\n", ans);
 
    return 0;
}