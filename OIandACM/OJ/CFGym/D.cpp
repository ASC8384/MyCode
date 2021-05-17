#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll jc[112345];

ll mod = 2;

ll qpow(ll n, ll x) {
    ll ans = 1;
    while(x) {
        if(x & 1)
            ans = (ans * n) % mod;
        n = (n * n) % mod;
        x >>= 1;
    }
    return ans;
}

ll C(ll n, ll m) {
    if(n < m)
        return 0;
    return (jc[n] % mod * qpow(jc[m] * jc[n - m] % mod, mod - 2) % mod) % mod;
}

ll lucas(ll n, ll m) {
    if(m == 0)
        return 1;
    else
        return (lucas(n / mod, m / mod) * C(n % mod, m % mod)) % mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    jc[0] = 1;
        // jc[1] = 1;
        for(ll i = 1; i <= 112340; i++) {
            jc[i] = (jc[i - 1] * i) % mod;
        }

    int t;
    cin >> t;
    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;
        ll t1 = n - 2 - (m-1)*(k-1);
        ll t2 = m - 2;
        // ll t1 = n - 2 - (m-1)*k;
        // ll t2 = m - 2;
        cout << (lucas(t1, t2)?"yEs":"no") << '\n';
    }

    return 0;
}

