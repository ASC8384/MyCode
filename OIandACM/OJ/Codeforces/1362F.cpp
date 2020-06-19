#include <bits/stdc++.h>
using namespace std;

const int size = 9 + (1 << 20);

bool v[size];
int	 ans[size];
int	 a[size];
int	 b[size];
int	 n;

vector<pair<int, int>> g[size];

void dfs(int now) {
	v[now] = true;
	for(auto i : g[now]) {
		if(!v[i.first])
			dfs(i.first);
	}
}

bool is(int val) {
	memset(v, 0, sizeof(v));
	for(int i = 0; i <= val; i++) {
		g[i].clear();
	}
	for(int i = 1; i <= n; i++) {
		int u = val & a[i];
		int v = val & b[i];
		g[u].push_back({v, 2 * i - 1});
		g[v].push_back({u, 2 * i - 2});
	}
	int cnt = 0;
	for(int i = 0; i <= val; i++) {
		if(g[i].size() & 1)
			return false;
		if(!v[i] && g[i].size() > 0) {
			cnt++;
			if(cnt > 1)
				return false;
			dfs(i);
		}
	}
	return (1 == cnt);
}

int acnt = 0;

void find(int now, int flag) {
	// int flag = -1;
	while(g[now].size()) {
		auto e = g[now].back();
		g[now].pop_back();
		if(v[e.second >> 1])
			continue;
		v[e.second >> 1] = true;
		find(e.first, e.second);
	}
	if(flag != -1) {
		ans[++acnt] = flag;
		ans[++acnt] = flag ^ 1;
		// ans[++acnt] = flag +- 1;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	t = 1;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i];
		}
		for(int i = 20; i >= 0; i--) {
			if(is((1 << i) - 1)) {
				cout << i << endl;
				memset(v, 0, sizeof(v));
				for(int j = 0; j <= (1 << i) - 1; j++) {
					if(g[j].size()) {
						find(j, -1);
						break;
					}
				}
				for(int j = 1; j <= n * 2; j++)
					cout << ans[j] + 1 << " ";
				return 0;
			}
		}
	}
	return 0;
}