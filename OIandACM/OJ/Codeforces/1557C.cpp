#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int		  size = 2e5 + 9;
const ll		  mod  = 1000000007;

ll qpow(ll x, ll t = mod - 2) {
	ll ret = 1;
	while(t) {
		if(t & 1)
			ret = ret * x % mod;
		x = x * x % mod;
		t >>= 1;
	}
	return ret;
}

ll fac[size], inc[size];

ll C(ll n, ll m) {
	return fac[n] * inc[m] % mod * inc[n - m] % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fac[0] = inc[0] = 1;
	for(ll i = 1; i < size; ++i)
		fac[i] = fac[i - 1] * i % mod, inc[i] = qpow(fac[i]);
	ll T;
	cin >> T;
	while(T--) {
		ll n, k;
		cin >> n >> k;
		ll now = 0;
		for(ll i = 0; i < n; i += 2)
			now = (now + C(n, i)) % mod;
		ll ans = 0;
		ll tmp = 1ll;
		if(n & 1) {
			now++;
			now %= mod;
			ans = qpow(now, k);
		} else {
			for(ll i = k; i > 0; i--) {
				ans = (ans + tmp * qpow(2, (ll)(i - 1) * n)) % mod;
				tmp = tmp * now % mod;
			}
			ans = (ans + tmp) % mod;
		}
		cout << ans % mod << '\n';
	}
	return 0;
}
