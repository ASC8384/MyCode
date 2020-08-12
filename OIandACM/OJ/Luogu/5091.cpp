/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-08 11:51:11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
// const ll  mod  = 1e9 + 7;

ll qpow(ll a, ll n, ll mod) {
	ll ret = 1;
	while(n) {
		if(n & 1)
			ret = ret * a % mod;
		n >>= 1;
		a = a * a % mod;
	}
	return ret;
}

ll phi(ll x) {
	ll ans = 1, num = 1;
	for(ll i = 2; i * i <= x; i++) {
		if(!(x % i)) {
			num = i - 1, x /= i;
			while(!(x % i))
				num = num * i, x /= i;
			ans = num * ans;
		}
	}
	if(x != 1)
		ans = ans * (x - 1);
	return ans;
}

ll oula(ll mod) {
	bool flag = false;
	int	 ret  = 0;
	char c;
	while(!isdigit(c = getchar()))
		;
	while(isdigit(c)) {
		ret = ret * 10 + c - '0';
		if(ret >= mod) {
			ret %= mod;
			flag = true;
		}
		c = getchar();
	}
	if(flag)
		return (ret + mod);
	else
		return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll a, m;
	// cin >> a >> m;
	scanf("%lld%lld", &a, &m);
	ll mod = phi(m);
	ll p   = oula(mod);

	cout << qpow(a, p, m) << endl;

	return 0;
}