#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll mod = 1e9 + 7;

ll qpow(ll n, ll x) {
	ll ret = 1;
	while(x) {
		if(x & 1)
			ret = ret * n % mod;
		x >>= 1;
		n = n * n % mod;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	ll inv2 = qpow(2, mod - 2);
	// cout << inv2 << endl;
	ll inv3 = qpow(3, mod - 2);
	// cout << inv3 << endl;
	while(cin >> n && n) {
		ll ans = 0;
        ll m = n / 2;
        ans = 4 * (m-1) * m % mod * (2*m-1) % mod * inv3 % mod;
        ans =(ans + m + 4 * m * m % mod)% mod;
        if(n & 1){
            ans = (ans + 4 * m * m % mod + 1) % mod;
        }
		cout << ans << '\n';
	}

	return 0;
}