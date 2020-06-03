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

typedef struct tree {
	int a, b, c;
} sdg3sdg;

vector<int> g[size];
sdg3sdg		t[size];

int n;
int qb[size];
int qc[size];
int f[size];

void dfs(int u) {
	qb[u] += t[u].b;
	qc[u] += t[u].c;
	for(auto i : g[u]) {
		// printf("%d,%d\n", u, i);
		dfs(i);
		qc[u] += qc[i];
		qb[u] += qb[i];
	}
}

void dp(int u) {
	if(t[u].b == t[i].c) {
		for(auto i : g[u]) {
			f[u] += f[i];
			//return f[];
		}
		return;
	}
	for(auto i : g[u]) {
		if(qc[i] == qb[i])
			return min(a[i] * g[i].size(), );
	}
}

int main() {
	qread(n);
	// while(t--) {
	int a, b, c;
	int u, v;
	for(int i = 1; i <= n; i++) {
		qread(a, b, c);
		t[i].a = a;
		t[i].b = b;
		t[i].c = c;
		// g[i].push_back(a, b, c);
	}
	for(int i = 1; i < n; i++) {
		qread(u, v);
		g[u].push_back(v);
		// g[v].push_back(u);
	}
	dfs(1);
	if(gc[1] == gb[1]) {

		cout << dp(1);
	} else {
		cout << "-1" << endl;
	}
	// for(int i = 1; i <= n; i++)
	// 	printf("%d:%d %d\n", i, qb[i], qc[i]);

	return 0;
}