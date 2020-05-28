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

ll n, m;
ll a[size], x;
ll ans;
ll f[size];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	qread(n);
	for(int i = 1; i <= (n + 1) / 2; i++) {
		qread(a[i]);
		f[i] = f[i - 1] + a[i];
	}
	m = (n + 1) / 2;
	qread(a[m + 1]);
	for(int i = m + 1; i <= n; i++) {
		a[i] = a[m + 1];
		f[i] = f[i - 1] + a[i];
	}

	if(a[n] >= 0) {
		if(f[n] > 0)
			cout << n << endl;
		else
			cout << -1 << endl;
	} else {
		ans = n;
		for(int i = 1; i <= m; i++) {
			ans = min(ans, (f[m] - f[i - 1] - 1) / (-1 * a[m + 1]) + m - i + 1);
			if(i + ans - 1 >= n) {
				cout << min(ans, n) << endl;
				return 0;
			}
		}
		cout << -1 << endl;
	}

	return 0;
}