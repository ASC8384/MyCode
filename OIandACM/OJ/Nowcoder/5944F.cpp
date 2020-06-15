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

double eps = 1e-4;

int a[size];
int p[size];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	// qread(t);
	t = 1;
	// double ans = 0.0;
	int ans = 0;
	while(t--) {
		int n;
		qread(n);
		for(int i = 1; i <= n; i++)
			qread(a[i]);
		for(int i = 1; i <= n; i++)
			qread(p[i]);
		for(int i = 1; i <= n; i++)
			ans += (a[i] * p[i]);
		if(9990 <= ans && ans <= 10010)
			cout << "Yes" << endl;
		else {
			cout << "No" << endl;
		}
	}

	return 0;
}