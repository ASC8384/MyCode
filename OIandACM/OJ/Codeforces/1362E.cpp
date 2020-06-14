#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const ll				   size = 1e6 + 9;
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

ll mod = 1000000007;
ll qpow(ll a, ll n, ll mod) {
	ll ans = 1;
	while(n) {
		if(n & 1)
			ans = ans * a % mod;
		n >>= 1;
		a = a * a % mod;
	}
	return ans;
}

int a[size];
ll	p;

int main() {
	int t;
	qread(t);

	while(t--) {
		ll n, p;
		qread(n, p);
		// ll ans = (n << 1);
		// ans		= 0;
		// ll sum = 0;
		for(int i = 1; i <= n; i++) {
			qread(a[i]);
		}
		sort(a + 1, a + n + 1);
		ll ans1 = 0;
		ll ans2 = 0;
		ll tmp	= 19260817;
		for(int i = n; i >= 1; i--) {
			if(!ans1 && !ans2) {
				ans1 = (ans1 + qpow(p, a[i], mod)) % mod;
				ans2 = (ans2 + qpow(p, a[i], tmp)) % tmp;
			} else {
				ans1 = (ans1 - qpow(p, a[i], mod) + mod) % mod;
				ans2 = (ans2 - qpow(p, a[i], tmp) + tmp) % tmp;
			}
		}
		cout << ans1 << endl;
	}
	return 0;
}
