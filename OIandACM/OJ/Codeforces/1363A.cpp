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
		int tmp1 = 0, tmp2 = 0;
		int tmp;
		int x, n;
		qread(n, x);
		for(int i = 1; i <= n; i++) {
			qread(tmp);
			if(tmp & 1)
				tmp1++;
			else
				tmp2++;
		}
		int f = 0;
		// if((tmp1 %2 == 1 && x % 2 == 1) || (x % 2 == 0 && tmp1 != 0 && tmp2 != 0))
		// if((x == n && tmp1 % 2 == 0) || (tmp1 == 0) || (tmp2 == 0 && x % 2 == 0))
		for(int i = 1, j = x - i; i <= x; i += 2, j -= 2) {
			if(tmp1 >= i && tmp2 >= j)
				f = 1;
		}
		if(f)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}