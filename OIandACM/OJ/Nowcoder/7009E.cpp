/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-25 21:18:32
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int n, q;
struct edge {
	int next, v;
} edges[size * 2];
int cnt;
int head[size];

void init() {
	memset(head, -1, sizeof(head));
	cnt = 0;
}
void addedge(int u, int v) {
	edges[cnt].next = head[u];
	edges[cnt].v	= v;
	head[u]			= cnt++;
}
int dep[size];
int f[size][21];

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	for(int i = 0; i <= 19; i++)
		f[u][i + 1] = f[f[u][i]][i];
	for(int i = head[u]; i != -1; i = edges[i].next) {
		int v = edges[i].v;
		if(v == fa)
			continue;
		f[v][0] = u;
		dfs(v, u);
	}
}
int lca(int x, int y) {
	if(dep[x] < dep[y])
		swap(x, y);
	for(int i = 20; i >= 0; i--) {
		if(dep[f[x][i]] >= dep[y])
			x = f[x][i];
		if(x == y)
			return x;
	}
	for(int i = 20; i >= 0; i--) {
		if(f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

ll qpow(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int dis(int a, int b) { return dep[a] + dep[b] - 2 * dep[lca(a, b)]; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	init();
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		addedge(u, v);
		addedge(v, u);
	}
	dfs(1, 0);
	int q;
	cin >> q;
	int ans = 0;
	for(int i = 1; i <= q; i++) {
		int a, b, c, t;
		cin >> a >> b >> c >> t;
		// t += dis(1, );
		// cout << dis(1, a) << endl;
		if(t > max(dis(1, a), dis(c, b) + dis(b, 1))) //, dis(a, b) + dis(b, 1)))
			ans++;
		// cout << ans << endl;
	}
	cout << ans * qpow(q, mod - 2) % mod;

	return 0;
}