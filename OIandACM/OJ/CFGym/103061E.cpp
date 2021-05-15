#include <bits/stdc++.h>
using namespace::std;

int a[1123456];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = a[n];
    for(int i = n - 1; i; i--){
        ans = abs(ans - a[i]);
    }
    cout << ans << '\n';

    return 0;
}
