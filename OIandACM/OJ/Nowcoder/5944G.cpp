#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const int				   size = 1e6 + 9;
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

ll		 a[size], b[size];
const ll mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	// qread(t);
	t = 1;
	while(t--) {
		int n;
		int ans = 0;
		qread(n);
		for(int i = 1; i <= n; i++)
			qread(a[i]);
		for(int i = 1; i <= n; i++)
			qread(b[i]);
		for(int i = 1; i <= n; i++)
			b[i] = (b[i] * (n + 1 - i)) % mod;
		// for(int i = 1; i <= n; i++)
		for(int i = n - 1; i; i--)
			b[i] = (b[i] + b[i + 1]) % mod;
		for(int i = 1; i <= n; i++)
			ans = (ans + (((a[i] * b[i]) % mod) * i) % mod) % mod;
		cout << ans << endl;
	}
	return 0;
}