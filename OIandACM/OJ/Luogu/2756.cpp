/***
 * @Author       : ASC_8384
 * @License      : CC0
 * @Website      : http://www.ASC8384.top
 * @FilePath     : \OIandACM\OJ\Luogu\2756.cpp
 * @Date         : 2020-04-28 15:01:31
 * @LastEditTime : 2020-04-28 15:01:32
 * @Description  : P2756
 */

#include <bits/stdc++.h>
using namespace std;

// vector<int> g[233];

int	 n, m;
bool vis[233];
int	 mat[233];
bool g[2333][2333];

bool dfs(int x) {
	// for(auto i : g[x]) {
	// for(int i = 0; i < g[x].size(); i++) {
	for(int i = 1; i <= n + m; i++) {
		// int j = g[x][i];
		if(vis[i] || !g[x][i])
			continue;
		vis[i] = true;
		if(!mat[i] || dfs(mat[i])) {
			mat[i] = x;
			return true;
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	int u, v;
	cin >> u >> v;
	while(u != -1 && v != -1) {
		g[u][v] = true;
		cin >> u >> v;
		// g[u].push_back(v);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		memset(vis, false, sizeof(vis));
		ans += dfs(i);
	}
	cout << ans << endl;
	for(int i = n + 1; i <= n + m; i++) {
		if(mat[i]) {
			cout << mat[i] << " " << i << endl;
		}
	}

	return 0;
}