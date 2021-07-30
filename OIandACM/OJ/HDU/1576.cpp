#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 9973;

ll qpow(ll x, ll n){
    ll ret = 1;
    while (n) {
        if(n & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b;
        cout << a * qpow(b, mod-2) % mod << '\n';
    }

    return 0;
}

