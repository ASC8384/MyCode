#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 998244353;

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

ll qpow(ll n, ll t) {
	ll ret = 1;
	while(t) {
		if(t & 1)
			ret = ret * n % mod;
		t >>= 1;
		n = n * n % mod;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	int n;
	// cin >> t;
	const ll inv2 = qpow(2, mod - 2);
	while(cin >> n) {
		// int n;
		// cin >> n;
		fib x, y;
		x = fib(inv2, inv2);
		y = fib(inv2, mod - inv2);
		x = qpow(x, n);
		y = qpow(y, n);
		ll ans;
		ans = (x - y).b;
		cout << ans * qpow(qpow(2, n), mod - 2) % mod << '\n';
	}

	return 0;
}