#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
long long		  mod = 998244353;

long long qpow(long long base, long long power) {
	long long result = 1;
	base			 = base % mod;
	while(power > 0) {
		if(power & 1) {
			result = result * base % mod;
		}
		power >>= 1;
		base = (base * base) % mod;
	}
	return result % mod;
}

long long inv[6100000];

void init() {
	inv[0] = inv[1] = 1;
	for(ll i = 2; i < 6000009; i++) {
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	}
	inv[0] = 0;
	for(int i = 1; i <= 6000009; i++) {
		// inv[i] = qpow(1ll * i * i, mod - 2);
		inv[i] = inv[i] * inv[i] % mod;
		inv[i] = (inv[i] + inv[i - 1]);
		if(inv[i] >= mod)
			inv[i] -= mod;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	init(); //求1+.....1/n^2的和
	while(t--) {
		long long n;
		scanf("%lld", &n);
		long long ans = (inv[n] * (3 * n * n % mod) % mod) % mod * qpow(1ll * n * n, mod - 2) % mod * qpow(1ll * n, mod - 2) % mod;
		printf("%lld\n", ans);
	}
}
