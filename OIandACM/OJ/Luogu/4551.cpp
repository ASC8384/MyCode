#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 4e6 + 9;
const ll  mod  = 1e9 + 7;

int top, tot = 1;
int dis[size];
int head[size], wei[size], to[size], nxt[size];
int ans;
int ch[size][3];
int n;

void add(int u, int v, int w) {
	nxt[++top] = head[u];
	head[u]	   = top;
	to[top]	   = v;
	wei[top]   = w;
}

void insert(int x) {
	for(int i = 30, p = 1; i >= 0; --i) {
		int c = ((x >> i) & 1);
		if(!ch[p][c])
			ch[p][c] = ++tot;
		p = ch[p][c];
	}
}

void get(int x) {
	int ret = 0;
	for(int i = 30, p = 1; i >= 0; --i) {
		int c = ((x >> i) & 1);
		if(ch[p][c ^ 1]) {
			p = ch[p][c ^ 1];
			ret |= (1 << i);
		} else
			p = ch[p][c];
	}
	ans = max(ans, ret);
}

void dfs(int u, int fa) {
	insert(dis[u]);
	get(dis[u]);
	for(int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if(v == fa)
			continue;
		dis[v] = dis[u] ^ wei[i];
		dfs(v, u);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// int t = 1;
	cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	dfs(1, 0);
	cout << ans << endl;

	return 0;
}