/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-06-29 13:39:00
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 9901;

ll qpow(ll n, ll x) {
	ll ret = 1;
	while(x) {
		if(x & 1) {
			ret = ret * n % mod;
		}
		n = n * n % mod;
		x >>= 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll a, b;
	cin >> a >> b;
	ll ans = 1;
	for(ll i = 2; i * i <= a; i++) {
		if(a % i)
			continue;
		ll tmp = 0;
		while(a % i == 0) {
			a /= i;
			tmp++;
		}
		if(i % mod == 1)
			ans = ans * (tmp + 1) % mod;
		else {
			ll pp	= (tmp * b + 1);
			ll niyr = i % mod;
			ans		= ans * (qpow(niyr, pp) - 1) * qpow(niyr - 1, mod - 2) % mod;
		}
	}
	if(a != 1) {
		if(a % mod == 1)
			ans = ans * (b + 1) % mod;
		else {
			ll pp	= (b + 1); 
			ll niyr = a % mod;
			ans		= ans * (qpow(niyr, pp) - 1) * qpow(niyr - 1, mod - 2) % mod;
		}
	}
	cout << ans << endl;

	return 0;
}