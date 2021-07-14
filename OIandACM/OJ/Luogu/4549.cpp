#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll ans = 0;
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        ans = __gcd(x, ans);
    }
    cout << abs(ans);

   return 0;
}

