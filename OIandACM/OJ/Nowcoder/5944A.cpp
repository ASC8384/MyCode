#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const int				   size = 100000 + 100;
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

ll	a[size];
ll	t[size];
ll	mod = 1000000007;
int main() {
	a[0]   = 0;
	t[0]   = 1;
	ll tmp = 1;
	for(int i = 1; i < size; i++) {
		t[i] = (t[i - 1] * 10) % mod;
		a[i] = (a[i - 1] * 10 + tmp) % mod;
		tmp	 = (tmp * 10) % mod;
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	// qread(T);
	cin >> T;
	string s;
	while(T--) {
		ll ans	= 0;
		ll doyu = 0;
		ll left = 0;
		cin >> s;
		size_t len = s.size();
		for(int i = 0; i < len; i++) {
			ll tmp = s[i] - '0';
			left   = (left * 10 + doyu * tmp) % mod;
			if(tmp < 7)
				ans = (ans + tmp * a[len - i - 1]) % mod;
			else if(tmp > 7)
				ans = (ans + tmp * a[len - i - 1] + t[len - i - 1]) % mod;
			else if(tmp == 7) {
				ans = (ans + tmp * a[len - i - 1]) % mod;
				doyu++;
			}
		}
		ans = (left + doyu + ans) % mod;
		cout << ans << endl;
	}
}
