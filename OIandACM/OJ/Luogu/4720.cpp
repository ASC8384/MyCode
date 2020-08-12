#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p;

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if(!b) {
		x = 1, y = 0;
		return a;
	}
	ll res = exgcd(b, a % b, x, y);
	ll t   = x;
	x	   = y;
	y	   = t - a / b * y;
	return res;
}

ll qpow(ll a, ll n, ll mod) {
	ll res = 1;
	while(n) {
		if(n & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return res;
}

ll inv(ll a, ll p) {
	ll x, y;
	exgcd(a, p, x, y);
	if(x + p > p)
		return x;
	return x + p;
}

ll crt(ll n, ll mod) {
	return n * (p / mod) % p * inv(p / mod, mod) % p;
}

ll fac(ll n, ll p, ll k) { //k = p^x
	if(!n)
		return 1;
	ll ans = 1;
	for(int i = 2; i <= k; i++) {
		if(i % p)
			ans = ans * i % k;
	}
	ans = qpow(ans, n / k, k);
	for(int i = 2; i <= n % k; i++) {
		if(i % p)
			ans = ans * i % k;
	}
	return ans * fac(n / p, p, k) % k;
}

ll C(ll n, ll m, ll p, ll k) { //k = p^x
	if(n < m)
		return 0;
	ll a = fac(n, p, k), b = fac(m, p, k), c = fac(n - m, p, k);
	ll cnt = 0;
	for(ll i = p; i <= n; i *= p)
		cnt += n / i;
	for(ll i = p; i <= m; i *= p)
		cnt -= m / i;
	for(ll i = p; i <= n - m; i *= p)
		cnt -= (n - m) / i;
	return a * inv(b, k) % k * inv(c, k) % k * qpow(p, cnt, k) % k;
}

ll exlucas(ll n, ll m, ll p) {
	ll t = p, ans = 0;
	for(ll i = 2; i * i <= t; i++) {
		if(t % i)
			continue;
		ll tmp = 1;
		while(t % i == 0) {
			tmp *= i;
			t /= i;
		}
		ans = (ans + crt(C(n, m, i, tmp), tmp)) % p;
	}
	if(t > 1)
		ans = (ans + crt(C(n, m, t, t), t)) % p;
	return ans % p;
}

int main() {
	ll n, m;
	cin >> n >> m >> p;
	cout << exlucas(n, m, p);
	return 0;
}
