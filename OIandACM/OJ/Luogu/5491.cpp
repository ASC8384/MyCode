/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-21 12:13:53
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;

ll mod = 1e9 + 7;
ll i2  = 0;

struct com {
	ll a, b; // a 是实部，b 是虚部
	ll i2;	 // i^2
	com(ll a = 0, ll b = 0, ll i2 = 0) : a(a), b(b), i2(i2) {}
	com operator*(const com &x) const {
		return com((a * x.a % mod + b * x.b % mod * i2 % mod + mod) % mod,
				   (b * x.a % mod + a * x.b % mod + mod) % mod, x.i2);
	}
	bool operator==(const com &x) const {
		return (a == x.a && b == x.b);
	}
	friend com operator^(com &x, ll t) {
		com ret = 1;
		ret.i2	= x.i2;
		while(t) {
			if(t & 1)
				ret = ret * x;
			x = x * x;
			t >>= 1;
		}
		return ret;
	}
};

ll check_if_residue(ll x) {
	com xx = x;
	return (xx ^ ((mod - 1) >> 1)).a;
}

ll solve(ll n) {
	if(n == 0)
		return 0;
	if(mod == 2)
		return n % mod;
	i2 = 0;
	if(check_if_residue(n) == mod - 1)
		return -1;
	ll a;
	do {
		a  = rand() % mod;
		i2 = (a * a % mod - n + mod) % mod;
	} while(check_if_residue(i2) != mod - 1);
	com aa = com(a, 1, i2);
	return (aa ^ ((mod + 1) >> 1)).a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(NULL));

	int t = 1;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n >> mod;
		ll x1 = solve(n);
		if(x1 == 0) {
			cout << "0\n";
		} else if(x1 == -1) {
			cout << "Hola!\n";
		} else {
			ll x2 = mod - x1;
			if(x1 > x2)
				cout << x2 << " " << x1 << '\n';
			else if(x1 == x2)
				cout << x1 << '\n';
			else
				cout << x1 << " " << x2 << '\n';
		}
	}

	return 0;
}