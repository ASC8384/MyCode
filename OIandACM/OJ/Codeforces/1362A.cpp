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

ll a, b;
ll srtayade() {
	if(a % b) {

	} else {
		ll k   = a / b;
		ll ans = 0;
		while(k != 1) {
			if(k & 1)
				return -1;
			ans++;
			k >>= 1;
		}
		return ans / 3 + ((ans % 3) > 0);
	}
	return -1;
}

int main() {
	int t;
	qread(t);

	while(t--) {
		qread(a, b);
		if(a < b) {
			ll t = b;
			b	 = a;
			a	 = t;
		}
		ll sum = 0;
		// ll ans = (n << 1);
		// if(a % b) {
		// 	ans = 0;
		// 	ll k = a / b;
		// 	ans++;
		// 	k >>= 1;
		//     while(k != 1){
		//         if(k & 1)

		//     }
		// } else {
		// 	cout << -1 << endl;
		// }
		ll ans = srtayade();
		cout << ans << endl;
	}
	return 0;
}