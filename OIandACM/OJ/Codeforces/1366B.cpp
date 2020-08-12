#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const int				   size = 55;
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
		int n, x, m;
		qread(n, x, m);
		int le, rr;
		int maxx = x;
		int minn = x;
		int nle	 = x;
		int nrr	 = x;
		for(int i = 1; i <= m; i++) {
			qread(le, rr);
			if(nrr < le || nle > rr)
				continue;
			minn = min(minn, le);
			maxx = max(maxx, rr);
			nle	 = minn;
			nrr	 = maxx;
		}
		cout << maxx - minn + 1 << endl;
	}
	return 0;
}