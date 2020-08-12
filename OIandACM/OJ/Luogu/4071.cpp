#include <stdio.h>
typedef long long ll;

const int size = 1e6 + 9;

ll mod = 1e9 + 7;

ll f[size], jc[size];

ll qpow(ll n, ll x, ll mod) {
	ll ans = 1;
	while(x) {
		if(x & 1)
			ans = (ans * n) % mod;
		n = (n * n) % mod;
		x >>= 1;
	}
	return ans;
}

ll C(ll n, ll m, ll mod) {
	return (jc[n] % mod * qpow(jc[m] * jc[n - m] % mod, mod - 2) % mod) % mod;
}

ll lucas(ll n, ll m, ll mod) {
	if(!m)
		return 1;
	else
		return (lucas(n / mod, m / mod, mod) * C(n % mod, m % mod, mod)) % mod;
}

int main() {
	int t;
	f[1] = 0, f[2] = 1;
	jc[1] = 1, jc[2] = 2;
	for(ll i = 3; i <= 1000000; i++) {
		f[i]  = ((i - 1) * (f[i - 1] + f[i - 2]) % mod) % mod;
		jc[i] = (jc[i - 1] * i) % mod;
	}
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		if(n == m)
			puts("1");
		else if(n - m == 1)
			printf("0\n");
		else if(m == 0)
			printf("%lld\n", f[n]);
		else
			printf("%lld\n", lucas(n, m) * f[n - m] % mod);
	}
	return 0;
}