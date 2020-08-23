/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-23 11:32:45
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;

ll mod = 1e9 + 7;

ll	a[size], b[size];
int n;

ll lcm(ll x, ll y) { return x * y / __gcd(x, y); }

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll gcd = exgcd(b, a % b, x, y);
	ll tp  = x;
	x	   = y;
	y	   = tp - a / b * y;
	return gcd;
}

ll qmul(ll n, ll x, ll mod) {
	ll ret = 0;
	while(x) {
		if(x & 1)
			ret = (ret + n) % mod;
		n = (n << 1) % mod;
		x >>= 1;
	}
	return ret;
}

ll excrt() {
	ll ans = a[1];
	ll mod = b[1];
	for(int i = 2; i <= n; i++) {
		ll x, y;
		// ax = c mod b
		ll c = ((a[i] - ans) % b[i] + b[i]) % b[i];
		// if(c == 0)
		// 	continue;
		ll gcd = exgcd(b[i], mod, x, y);
		if(c % gcd)
			return -1;
		y = qmul(y, c / gcd, b[i] / gcd);
		ans += y * mod;
		mod *= b[i] / gcd;
		ans = (ans % mod + mod) % mod;
	}
	return ans;
}

int main() {
	// ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++) { // x = a mod b
		cin >> b[i];
		cin >> a[i];
	}
	cout << excrt() << '\n';

	return 0;
}