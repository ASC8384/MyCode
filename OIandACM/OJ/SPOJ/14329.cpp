#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

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

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll ans = 0;
        if(n <= 2){
            ans = n;
        }else{
            if(n % 3 == 0){
                ans = qpow(3, n / 3);
            }else if(n % 3 == 1){
                ans = qpow(3, n / 3 - 1) * 4;
            }else{
                ans = qpow(3, n / 3) * 2;
            }
        }
        cout << ans % mod << '\n';
    }

    return 0;
}

