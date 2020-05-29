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
		int n, m, x, y;
		qread(n, m, x, y);
		string s;
		y		= min(2 * x, y);
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			cin >> s;
			int flag = 0;
			for(int j = 0; j < m; j++) {
				if(s[j] == '*') {
					if(flag == 1) {
						ans += x;
						flag = 0;
					}
				} else {
					flag++;
					if(flag == 2) {
						ans += y;
						flag = 0;
					}
				}
				if(j == m - 1)
					ans += flag * x;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
