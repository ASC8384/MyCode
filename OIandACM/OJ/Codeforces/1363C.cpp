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
		int n, x;
		qread(n, x);
		int du[1009]; //, g[1009][1009];
		for(int i = 1; i <= 1009; i++) {
			du[i] = 0;
		}
		for(int i = 1; i < n; i++) {
			int u, v;
			qread(u, v);
			du[u]++;
			du[v]++;
		}

		if(n == 1) {
			cout << "Ayush" << endl;
		} else if(du[x] == 1) {
			cout << "Ayush" << endl;
		} else {
			if(((n % 2)))
				cout << "Ashish" << endl;
			else
				cout << "Ayush" << endl;
		}
	}
	return 0;
}