#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    while (cin >> n, n) {
        ll ans = 0;
        for(int i = 1; i < n; i++)
            for(int j = i+1; j <= n; j++)
                ans += __gcd(i, j);
        cout << ans << '\n';
    }

    return 0;
}

