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

ll	x, y, t;
int cal(int x) {
	// int res;
	return (x - y) / (2 * t - x - y);
}

int solve(int l, int r) {
	while(r > l) {
		int m1 = (2 * l + r) / 3;
		int m2 = (2 * r + l + 2) / 3;
		if(cal(m1) > cal(m2))
			r = m2 - 1;
		else
			l = m1 + 1;
	}
	return l;
}

int main() {
	int T;
	qread(T);
	while(T--) {
		qread(x, y, t);
		ll	   pk  = (x + y);
		ll	   ia  = (x - y);
		ll	   n   = 1;
		ll	   ans = 1;
		double tmp = t * 1.0 - pk / 2.0;
		if(t * 2 <= x + y) {
			cout << 2 << endl;
			continue;
		}
		// cout << ans << endl;
		n = (t - y) / (2 * t - pk);

		// double tmp1 = (n * (x + y) - y) * 1.0 / (2 * n - 1);
		// double tmp2 = ((n + 1) * (x + y) - y) * 1.0 / (2 * (n + 1) - 1);
		ll tmp1 = n;
		ll tmp2 = n + 1;

		// if(abs(tmp1 - 1.0 * t) - abs(tmp2 - 1.0 * t) < 1e-8) {
		if(abs((tmp1 * pk - y) * 1.0 / (2 * tmp1 - 1) - t * 1.0) >
		   abs((tmp2 * pk - y) * 1.0 / (2 * tmp2 - 1) - t * 1.0))
			// cout << 2 * n - 1 << endl;
			n = tmp2;
		else
			n = tmp1;

		// else {
		cout << 2 * n - 1 << endl;
		// }
		// cout << solve(1, 10000) << endl;
	}
	return 0;
}
