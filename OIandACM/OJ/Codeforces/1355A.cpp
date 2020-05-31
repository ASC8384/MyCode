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

int main() {
	ll t;
	qread(t);
	while(t--) {
		ll a, k;
		qread(a, k);
		ll tmp = a;
		// ll cnt = 1;
		for(int i = 1; i < k; i++) {
			ll minn = a % 10, maxx = a % 10;
			while(tmp) {
				minn = min(minn, tmp % 10);
				maxx = max(maxx, tmp % 10);
				tmp /= 10;
			}
			if(minn == 0)
				break;
			a	= a + minn * maxx;
			tmp = a;
		}
		cout << a << endl;
	}
	return 0;
}