#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const int				   size = 4e4 + 9;
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

int			 n, m;
int			 in[size];
bitset<size> v[size];
int			 ans = 0;

vector<int> g[size];
queue<int>	que;

void bfs(int pos) {
	for(int i = 1; i <= n; i++)
		if(in[i] == 0)
			que.push(i);
	v[1][1] = 1;
	// que.push(pos);
	while(!que.empty()) {
		pos = que.front();
		que.pop();
		if((v[pos].count() & 1) || pos == 1) {
			ans++;
			v[pos].set(pos, 1);
		}
		for(auto i : g[pos]) {
			// v[i] = !v[i];
			// v[i] += v[pos];
			// if(v[i] == 0)
			// 	v[i] = v[pos];
			// v[i]++;
			in[i]--;
			v[i] |= v[pos];
			if(in[i] == 0)
				que.push(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	// qread(t);
	t = 1;
	while(t--) {
		qread(n, m);
		// if(n == m - )
		for(int i = 1; i <= m; i++) {
			int u, v;
			qread(u, v);
			g[u].push_back(v);
			in[v]++;
		}
		// v[1] = 0;
		bfs(1);
		cout << ans << endl;
	}

	return 0;
}