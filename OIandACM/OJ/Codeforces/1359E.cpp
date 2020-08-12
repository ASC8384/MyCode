#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const ll				   size = 5e5 + 9;
inline void				   qread() {}
template <class T1, class... T2>
inline void qread(T1 &IEE, T2 &... ls) {
	register T1	  __ = 0, ___ = 1;
	register char ch;
	while(!isdigit(ch = getchar()))
		___ = (ch == '-') ? -___ : ___;
	do {
		__ = (__ << 1) + (__ << 3) + (ch ^ 48);
	} while(isdigit(ch = getchar()));
	__ *= ___;
	IEE = __;
	qread(ls...);
	return;
}

ll fac[size], inv[size];
ll mod = 998244353;

ll qpow(ll x, ll n) //x的n次方
{
	ll res = 1;
	while(n) {
		if(n & 1)
			res = (1ll * res * x) % mod;
		x = (1ll * x * x) % mod;
		n >>= 1;
	}
	return res;
}

ll C(ll n, ll m) {
	ll res = (1ll * fac[n] * inv[m]) % mod;
	return (1ll * res * inv[n - m]) % mod;
}

int main() {
	int n, k;
	cin >> n >> k;

	fac[0] = 1;
	for(int i = 1; i <= n; i++)
		fac[i] = (1ll * fac[i - 1] * i) % mod;
	inv[n] = qpow(fac[n], mod - 2);
	for(int i = n - 1; i >= 0; i--)
		inv[i] = (1ll * inv[i + 1] * (i + 1)) % mod;

	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		if(n / i < k)
			break;
		ans = (ans + C(n / i - 1, k - 1)) % mod;
	}
	cout << ans << endl;
}