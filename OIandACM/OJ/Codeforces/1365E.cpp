#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const ll				   size = 599;
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

ll a[size];

int main() {
	int t;
	// qread(t);
	t = 1;

	while(t--) {
		int n;
		qread(n);
		for(int i = 1; i <= n; i++)
			qread(a[i]);
		ll ans = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				for(int k = 1; k <= n; k++) {
					ans = max(ans, (long long)(a[i] | a[j] | a[k]));
				}
		cout << ans << endl;
	}
	return 0;
}
