#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const ll				   size = 10e5 + 9;
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

ll a[size][61];
ll f[size];
ll d[size];

int main() {
	ll n;
	qread(n);
	d[0] = -1;
	for(ll i = 1; i <= n; i++) {
		qread(a[i][0]);
		f[i] = f[i - 1] + a[i][0];
		d[i] = d[i >> 1] + 1;
	}
	for(ll j = 1; j <= 60; j++) {
		for(ll i = 1; i + (j << 1) - 1 <= n; i++) {
			a[i][j] = max(a[i][j - 1], a[i + (1 << j - 1)][j - 1]);
		}
	}

	ll ans = 0;
	for(ll i = 1; i <= n; i++) {
		for(ll j = i; j <= n; j++) {
			ll s = d[j - i + 1];
			ans	 = max(ans, (f[j] - f[i - 1] - max(a[i][s], a[j - (1 << s) + 1][s])));
		}
	}
	cout << ans << endl;

	return 0;
}