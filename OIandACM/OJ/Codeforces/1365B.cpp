#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const ll				   size = 1e5 + 9;
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

int a[size];
int b[size];

int main() {
	int t;
	qread(t);

	while(t--) {
		int n;
		qread(n);
		for(int i = 1; i <= n; i++)
			qread(a[i]);
		for(int i = 1; i <= n; i++) {
			qread(b[i]);
		}
		bool flag = true;
		for(int i = 1; i < n; i++) {
			if(a[i] > a[i + 1]) {
				flag = false;
				break;
			}
		}
		if(flag) {
			cout << "Yes" << endl;
		} else {
			int n1 = 0;
			int n0 = 0;
			for(int i = 1; i <= n; i++) {
				if(b[i])
					n1++;
				else
					n0++;
				if(n1 != 0 && n0 != 0)
					break;
			}
			if(n1 != 0 && n0 != 0)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}
