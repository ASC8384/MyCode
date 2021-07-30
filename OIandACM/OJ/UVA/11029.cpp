#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

ll qpow(ll x, ll n){
    ll ret = 1;
    while (n) {
        if(n & 1)
            ret = x * ret % 1000;
        x = x * x % 1000;
        n >>= 1;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T;
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b;
        double tmp = b * log10(a);
        cout << (ll)(pow(10, tmp - (ll)tmp) * 100);
        a = qpow(a, b);
        cout << "...";
        if(a < 10)
            cout << "00";
        else if(a < 100)
            cout << "0";
        cout << a << '\n';
    }

    return 0;
}

