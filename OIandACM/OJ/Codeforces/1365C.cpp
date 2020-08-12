#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const ll				   size = 4e5 + 9;
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

int a[size], b[size], c[size];

int main() {
	int t;
	// qread(t);
	t = 1;

	while(t--) {
		int n;
		qread(n);
		// string text1 = "";
		for(int i = 1; i <= n; i++) {
			int tmp;
			qread(tmp);
			a[tmp] = i;
			// text1 += to_string(a[i]);
		}
		// string text2 = "";
		int ans = 1;
		int kth = 0;
		for(int i = 1; i <= n; i++) {
			// qread(b[i]);
			int tmp;
			qread(tmp);
			kth = i - a[tmp];
			if(kth < 0)
				kth += n;
			b[kth]++;
			// b[i + n] = b[i];
			// text2 += to_string(b[i]);
			ans = max(b[kth], ans);
		}
		for(int i = 1; i <= n; i++) {
			c[i] = a[i] - i;
		}
		c[1] = 1;
		//sort(c + 1, c + n + 1);
		cout << max(c[1], ans) << endl;
	}
	return 0;
}
