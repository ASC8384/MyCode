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

bool a[55][55];

int main() {
	int t;
	qread(t);

	while(t--) {
		int n, m;
		qread(n, m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				qread(a[i][j]);
		int y = m;
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= n; j++)
				if(a[j][i]) {
					y--;
					break;
				}
		int x = n;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if(a[i][j]) {
					x--;
					break;
				}
		if(min(x, y) % 2 == 0)
			cout << "Vivek" << endl;
		else
			cout << "Ashish" << endl;
	}
	return 0;
}