#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const int				   size = 1e6 + 12;
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

ll a[size];
ll f[5], tmp[5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	// qread(t);
	t = 1;
	while(t--) {
		int n;
		// qread(n);
		cin >> n;
		vector<long long> se[5];
		ll				  sum = 0;
		for(int i = 1; i <= n; i++) {
			// int tmp;
			// qread(a[i]);
			cin >> a[i];
			sum += a[i];
			se[a[i] % 5].push_back(a[i]);
			// se.insert(tmp);
		}
		if(sum % 5 == 0)
			cout << sum << endl;
		else {
			// sum = 0;
			for(int i = 1; i <= 4; i++)
				// f[i] = (unsigned long long)-1;
				f[i] = 0x7ffffffffffffff;
			// cout << f[1] << endl;
			for(int i = 1; i <= n; i++) {
				for(int j = 0; j <= 4; j++)
					tmp[j] = f[j];
				for(int j = 0; j <= 4; j++)
					f[(a[i] + j) % 5] = min(f[(a[i] + j) % 5], tmp[j] + a[i]);
				f[a[i] % 5] = min(f[a[i] % 5], a[i]);
			}
			cout << max(sum - f[sum % 5], (ll)0) << endl;
		}
	}

	return 0;
}
