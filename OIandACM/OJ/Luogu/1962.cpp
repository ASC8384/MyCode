/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-19 10:12:31
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

struct fib { // 扩域
	ll a, b;
	fib(ll a = 0, ll b = 0) : a(a), b(b) {}

	fib operator+(const fib &x) const {
		fib res;
		res.a = a + x.a;
		res.b = b + x.b;
		if(res.a >= mod)
			res.a -= mod;
		if(res.b >= mod)
			res.b -= mod;
		return res;
	}
	fib operator-(const fib &x) const {
		fib res;
		res.a = a - x.a + mod;
		res.b = b - x.b + mod;
		if(res.a >= mod)
			res.a -= mod;
		if(res.b >= mod)
			res.b -= mod;
		return res;
	}
	fib operator*(const fib &x) const {
		fib res;
		res.a = (a * x.a + 5ll * b * x.b) % mod;
		res.b = (a * x.b + x.a * b) % mod;
		return res;
	}
};

fib qpow(fib a, ll t) {
	fib res = fib(1, 0);
	while(t) {
		if(t & 1)
			res = res * a;
		a = a * a;
		t >>= 1;
	}
	return res;
}

int main() {
	const ll inv2 = 500000004;

	ll n;
	// cin >> n;
	scanf("%lld", &n);

	fib x, y;
	x = fib(inv2, inv2);
	y = fib(inv2, mod - inv2);
	x = qpow(x, n);
	y = qpow(y, n);

	ll ans;
	ans = (x - y).b;
	// cout << ans << end;
	printf("%lld\n", ans);

	return 0;
}