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

int			n, m;
vector<int> g[size];
typedef struct point {
	int id;
	int val;
} aaa;
aaa	 pot[size];
// bool mp[size];

bool cmp(aaa x, aaa b) {
	return x.val < b.val;
}

int main() {
	int t;
	// qread(t);
	t = 1;

	while(t--) {
		qread(n, m);
		for(int i = 0; i < m; i++) {
			int u, v;
			qread(u, v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i = 1; i <= n; i++) {
			int tmp;
			qread(tmp);
			pot[i].id  = i;
			pot[i].val = tmp;
		}
		for(int i = 1; i <= n; i++) {
			// memset(mp, 0, sizeof(mp));
			// for(int i = 1; i <= n; i++)
			// mp[i] = 0;
			map<int, bool> mp;
			for(auto it : g[i])
				mp[pot[it].val] = 1;
			for(int j = 1; j < pot[i].val; j++) {
				if(!mp[j]) {
					cout << -1 << endl;
					return 0;
				}
			}
			if(mp[pot[i].val]) {
				cout << -1 << endl;
				return 0;
			}
		}
		sort(pot + 1, pot + n + 1, cmp);
		for(int i = 1; i <= n; i++)
			cout << pot[i].id << " ";
		cout << endl;
		return 0;
	}
	return 0;
}
