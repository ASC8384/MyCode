#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const int				   size = 1e7 + 9;
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
bool prime[size];  //prime[i]表示i是不是质数
int	 p[size], tot; //p[size]用来存质数
void init() {
	for(int i = 2; i < size; i++) {
		if(p[i] == 0) {
			p[i] = i;
			for(int j = 2; i * j < size; j++) {
				if(p[i * j] == 0) {
					p[i * j] = i;
				}
			}
		}
	}
}

int d1[size], d2[size];
int a[size];

int main() {
	cout.tie(0);
	cin.tie(0);
	ios::sync_with_stdio(0);
	init();

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++) {
		if(p[a[i]] == a[i]) {
			d1[i] = d2[i] = -1;
			continue;
		}
		int ans = 1;
		int tmp = a[i];
		while(tmp % p[a[i]] == 0) {
			tmp /= p[a[i]];
			ans *= p[a[i]];
		}
		if(tmp == 1) {
			d1[i] = d2[i] = -1;
			continue;
		}
		d1[i] = ans;
		d2[i] = a[i] / ans;
	}

	for(int i = 1; i <= n; i++)
		cout << d1[i] << " ";
	cout << endl;
	for(int i = 1; i <= n; i++)
		cout << d2[i] << " ";
	return 0;
}