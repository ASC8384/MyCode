/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-23 18:03:44
*/
#include <bits/stdc++.h>
typedef __int128 ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 12;
const ll  mod  = 1e9 + 7;

long long n, a[size], b[size];

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
//ret == gcd(a, b)
//x * a + y * b == gcd(a, b)

// 利用exgcd求逆元
ll inv(ll a, ll b) {
	ll x, y;
	extended_gcd(a, b, x, y);
	return x;
}

ll CRT(const long long a[], const long long m[], long long n) {
	ll M   = 1;
	ll ret = 0;
	for(ll i = 1; i <= n; i++)
		M *= m[i];
	for(ll i = 1; i <= n; i++) {
		ll Mi = M / m[i];
		ll ti = inv(Mi, m[i]);
		ret	  = (ret + a[i] * Mi % M * ti % M) % M;
	}
	return (ret + M) % M;
}

void prt(__int128 x) {
	if(x < 0)
		putchar('-'), x = -x;
	if(x > 9)
		prt(x / 10);
	putchar(x % 10 + '0');
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	prt(CRT(a, b, n));

	return 0;
}