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

int main() {
	int t;
	qread(t);

	while(t--) {
		ll n;
		qread(n);
		ll ans = (n << 1);
		// ans		= 0;
		ll sum = 0;
		while(n != 0) {
			if(n & 1) {
				sum++;
			}
			n >>= 1;
		}
		cout << ans - sum << endl;
	}
	return 0;
}
