#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int size = 1e5 + 7;

ll	mod = 1e9 + 7;
ll	Z[110000][2];
int F[110000];
int fa(int k) {
	if(k == F[k])
		return k;
	F[k] = fa(F[k]);
	return F[k];
}
ll fac[size];
ll inv[size];
ll qpow(long long a, long long b) {
	ll ans = 1;
	ll k   = a;
	while(b) {
		if(b & 1)
			ans = ans * k % mod;
		k = k * k % mod;
		b >>= 1;
	}
	return (ans + mod) % mod;
}
void init() {
	long long i;
	fac[0] = 1;
	inv[0] = 1;
	fac[1] = 1;
	inv[1] = 1;
	for(i = 2; i < size; i++) {
		fac[i] = ((fac[i - 1] * i) % mod + mod) % mod;
		inv[i] = (qpow(fac[i], mod - 2) + mod) % mod;
	}
}
ll C(ll n, ll m) {
	if(n < m || m < 0)
		return 0;
	return (fac[n] * inv[m] % mod * inv[n - m] % mod + mod) % mod;
}
int main() {
	int t;
	init();
	scanf("%d", &t);
	// cout << 0 << endl;
	while(t--) {
		int n;
		scanf("%d", &n);
		ll o = 0, j = 0;
		for(int i = 1; i <= n; i++) {
			F[i]	= i;
			Z[i][0] = Z[i][1] = 0;
			int a;
			scanf("%d", &a);
			if(a & 1) {
				Z[i][1] = 1;
				j++;
			} else {
				Z[i][0] = 1;
				o++;
			}
		}
		ll ans = (C(o, 2) * j % mod + C(o, 3) % mod) % mod;
		printf("%lld\n", ans);
		int q = n - 1;
		while(q--) {
			int a, b;
			scanf("%d%d", &a, &b);
			int A = fa(a), B = fa(b);
			if(A == B || ans == 0) {
				printf("%lld\n", ans);
				continue;
			}
			ans = (ans + mod - ((Z[A][0] * Z[B][0] % mod * ((o - Z[A][0] - Z[B][0] + j - Z[A][1] - Z[B][1] + mod) % mod)) % mod + (((o - Z[A][0] - Z[B][0] + mod) % mod) * ((Z[A][0] * Z[B][1] % mod + Z[A][1] * Z[B][0] % mod) % mod)) % mod)) % mod;
			printf("%lld\n", ans);
			Z[A][0] += Z[B][0];
			Z[A][1] += Z[B][1];
			F[B]	= A;
			Z[B][0] = Z[B][1] = 0;
		}
	}
}

/*
1
5
2 2 2 1 1
1 4

*/