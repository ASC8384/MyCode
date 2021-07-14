#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 10000007;

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

    ll a, b;
    while (cin >> a >> b, a|b) {
        cout << (2 * qpow(a - 1, b) + qpow(a, b) + 2 * qpow(a - 1, a - 1) + qpow(a, a)) % mod << '\n';
    }

    return 0;
}

