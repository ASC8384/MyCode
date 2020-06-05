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

int n;
int s[1100], a[1100], b[1100];

int main() {
	int t;
	qread(t);

	while(t--) {
		qread(n);
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++) {
			qread(s[i]);
			a[s[i]]++;
		}
		// int ll = 1;
		// int rr = 1024;
		ll	 k	  = 0;
		bool flag = false;
		for(int i = 1; i <= 1023; i++) {
			for(int j = 0; j <= 1023; j++)
				b[j] = 0;
			flag = true;
			for(int j = 1; j <= n; j++)
				b[(s[j] ^ i)]++;
			for(int j = 0; j <= 1023; j++)
				if(a[j] != b[j])
					flag = false;
			if(flag) {
				cout << i << endl;
				break;
			}
		}
		if(!flag)
			cout << -1 << endl;
		// while(ll < rr) {
		// 	int mid = ll + (rr - ll) / 2;
		// 	if(is(mid)) {
		// 		ll == mid + 1;
		// 	} else {
		// 		;
		// 	}
		// }
	}
	return 0;
}