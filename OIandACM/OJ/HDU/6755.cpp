/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-21 12:57:29
*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const unsigned int mod	= 1000000009;
const ll		   mdd	= 1000000008;
const unsigned int fiv	= 616991993;
const unsigned int size = 100005;

unsigned int jc[size], ny[size], v1[size], v2[size];

unsigned int mul(unsigned int x, unsigned int y) {
	return 1ll * x * y - 1ll * x * y / mod * mod;
}
unsigned int ksm(unsigned int x, ll y) {
	unsigned int ans = 1;
	// y %= mdd;
	while(y) {
		if(y & 1)
			ans = mul(ans, x);
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}

// unsigned int get_sum(unsigned int x, ll c, ll n) {
// 	return (ll)(ksm(x, n + 1) + mod - x) * ksm(x - 1, mod - 2) % mod;
// }
unsigned int get_sum(unsigned int x, ll c, ll n) {
	return (ll)((ll)mul(ksm(x, (n + 1)), ksm(x, c)) % mod + mod - 1) % mod * ksm(ksm(x, c) - 1, mod - 2) % mod;
}

unsigned int tmp1 = mod - 2;
unsigned int tmp2 = mod - 1;

unsigned int solve(ll n, ll c, unsigned int k) {
	unsigned int ans = 0;
	for(unsigned int i = 0; i <= k; i++) {
		unsigned int w = mul(v1[i], v2[k - i]); //(ll)v1[i] * v2[k - i] % mod;
		if(w == 1)
			w = n % mod;
		else
			w = get_sum(w, c, n);
		// w	  = w == 1 ? n % mod : get_sum(w, c, n);
		if((k - i) & 1)
			ans += mod - (ll)mul(jc[k], ny[i]) * mul(ny[k - i], w) % mod;
		else
			ans += (ll)mul(jc[k], ny[i]) * mul(ny[k - i], w) % mod;
		if(ans >= mod)
			ans -= mod;
		// ans -= (ans >= mod ? mod : 0);
	}
	ans = mul(ans ,ksm(fiv, (ll)k * tmp1 % tmp2));
	return ans;
}

void init(unsigned int n) {
	jc[0] = jc[1] = ny[0] = ny[1] = 1;
	for(unsigned int i = 2; i <= n; i++) {
		jc[i] = mul(jc[i - 1], i);
		ny[i] = mul((mod - mod / i), ny[mod % i]);
	}
	for(unsigned int i = 2; i <= n; i++)
		ny[i] = mul(ny[i - 1], ny[i]);
	v1[0] = v2[0]	  = 1;
	unsigned int tmp1 = 1 + fiv;
	unsigned int tmp2 = 1 + mod - fiv;
	for(unsigned int i = 1; i <= n; i++) {
		v1[i] = (ll)mul(v1[i - 1], tmp1) * ny[2] % mod;
		v2[i] = (ll)mul(v2[i - 1], tmp2) * ny[2] % mod;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	unsigned int t;
	// IO::read(t);
	// scanf("%d", &t);
	cin >> t;
	init(size - 1);
	while(t--) {
		long long	 n;
		long long	 c;
		unsigned int k;
		// IO::read(n);
		// IO::read(c);
		// IO::read(k);
		// IO::println(solve(n, c, k));
		cin >> n >> c >> k;
		cout << solve(n, c, k) << '\n';
		// scanf("%lld%lld%d", &n, &c, &k);
		// printf("%d\n", solve(n, c, k));
	}
}