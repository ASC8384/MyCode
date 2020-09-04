/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-06 13:04:40
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;
// const ll  inv  = 1e9 + 7;

ll qpow(ll x, ll n) {
	ll res = 1;
	while(n > 0) {
		if(n & 1)
			res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

ll a[size], s[size], inv[size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	inv[0] = inv[1] = 1;
	for(ll i = 2; i < 200004; i++) {
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	}

	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		ll sum = 0;
		a[0]   = 0;
		for(int i = 1; i <= n; i++) {
			cin >> s[i];
			sum	 = (sum + s[i]) % mod;
			a[i] = (a[i - 1] + s[i]) % mod;
		}
		ll ans = 0;
		ll tmp = 0;
		for(int i = 1; i <= n; i++) {
			ans = ans + (tmp = (tmp + a[n + 1 - i] - a[i - 1] + mod) % mod) * inv[i] % mod;
			while(ans >= mod)
				ans -= mod;
		}

		ll ff = 1ll * n * (n + 1) % mod * inv[2] % mod;
		cout << ans * qpow(ff, mod - 2) % mod << '\n';
	}

	return 0;
}