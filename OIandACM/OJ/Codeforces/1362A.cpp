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
		ll a, b;
		qread(a, b);
		if(a > b)
			swap(a, b);
		if(b % a) {
			cout << -1 << endl;
		} else {
			ll ans = 0;
			b /= a;
			while(b % 8 == 0) {
				b >>= 3;
				ans++;
			}
			while(b % 4 == 0) {
				b >>= 2;
				ans++;
			}
			while(b % 2 == 0) {
				b >>= 1;
				ans++;
			}
			if(b != 1)
				cout << -1 << endl;
			else
				cout << ans << endl;
		}
	}
}