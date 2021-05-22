#include <bits/stdc++.h>
#include <cstdio>
using namespace::std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> n;
    int n;

    scanf("%d", &n);

    double ans = 0.0;

    for(int i = 0; i <= n; i++){
        double tmp = i * 100.0 + (n - i) * 200.0;
        for(int j = 1; j <= i; j++)
            tmp *= 1.1;
        ans = max(ans, tmp);
    }
    printf("%.9lf\n", ans);

    return 0;
}

