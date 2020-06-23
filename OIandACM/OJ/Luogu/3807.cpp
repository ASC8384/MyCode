#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 1e5 + 9;

// ll mod = 1e9 + 7;

ll jc[size];

ll mod;

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
		return 0; // nb
	return (jc[n] % mod * qpow(jc[m] * jc[n - m] % mod, mod - 2) % mod) % mod;
}

ll lucas(ll n, ll m) {
	if(m == 0)
		return 1;
	else
		return (lucas(n / mod, m / mod) * C(n % mod, m % mod)) % mod;
}

int main() {
	int t;
	// scanf("%d", &t);
	cin >> t;
	while(t--) {
		ll n, m;
		cin >> n >> m >> mod;
		// scanf("%lld%lld%lld", &n, &m, &p);
		jc[0] = 1;
		// jc[1] = 1;
		for(ll i = 1; i <= mod; i++) {
			jc[i] = (jc[i - 1] * i) % mod;
		}
		cout << lucas(n + m, m) << endl;
		// printf("%lld\n", lucas(n + m, m));
	}
	return 0;
}