/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-18 11:30:21
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
	ll ret;
	if(!b) {
		x = 1;
		y = 0;
		return a;
	}
	ret	   = extended_gcd(b, a % b, x, y);
	ll tmp = x;
	x	   = y;
	y	   = tmp - a / b * y;
	return ret;
}

ll inv(ll a, ll b) {
	ll x, y;
	extended_gcd(a, b, x, y);
	return x;
}

ll CRT(const ll a[], const ll m[], ll n) {
	ll M   = 1;
	ll ret = 0;
	for(ll i = 1; i <= n; i++)
		M *= m[i];
	for(ll i = 1; i <= n; i++) {
		ll Mi = M / m[i];
		ll ti = inv(Mi, m[i]);
		ret = (ret + a[i] * Mi % M * ti % M) % M;
	}
	return (ret + M) % M;
}

ll a[size], b[size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	cout << CRT(b, a, n) << endl;

	return 0;
}