#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const int				   size = 99;
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

bool ma[size][size];
int	 a[size];
int	 b[size];

int main() {
	int t;
	qread(t);
	while(t--) {
		int n, m;
		qread(n, m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				qread(ma[i][j]);
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int mid = n + m - 2;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) {
				int tmp = i + j - 2;
				if(ma[i][j])
					a[tmp]++;
				b[tmp]++;
			}
		int ans = (ma[1][1] != ma[n][m]);
		if(mid & 1) {
			// mid >>= 1;
			for(int i = 1; i <= mid / 2; i++) {
				a[i] += a[mid - i];
				b[i] += b[mid - i];
				ans += min(b[i] - a[i], a[i]);
			}
		} else {
			for(int i = 1; i <= mid / 2; i++) {
				if(i == mid / 2)
					continue;
				a[i] += a[mid - i];
				b[i] += b[mid - i];
				ans += min(b[i] - a[i], a[i]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
