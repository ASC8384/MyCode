/***
 * @Author       : ASC_8384
 * @License      : CC0
 * @Website      : http://www.ASC8384.top
 * @FilePath     : \OIandACM\OJ\Luogu\1129.cpp
 * @Date         : 2020-04-26 16:28:19
 * @LastEditTime : 2020-04-26 16:28:19
 * @Description  : P1129
 */

#include <bits/stdc++.h>
using namespace std;

bool vis[2333];
int	 mat[2333];
bool g[2333][2333];
int	 n;
// vector<int> g[233];

bool dfs(int pos) {
	// for(auto i : g[pos]) {
	for(int i = 1; i <= n; i++) {
		if(!g[pos][i] || vis[i])
			continue;
		vis[i] = true;
		if(!mat[i] || dfs(mat[i])) {
			mat[i] = pos;
			return true;
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		// int n;
		cin >> n;
		memset(g, 0, sizeof(g));
		// for(int i = 0; i < n; i++)
		// 	g[i].clear();
		// vector<int> g[n];
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++) {
				scanf("%d", &g[i][j]);
			}
		int ans = 0;
		memset(mat, 0, sizeof(mat));
		for(int i = 1; i <= n; i++) {
			memset(vis, false, sizeof(vis));
			if(dfs(i))
				ans++;
		}
		// cout << ans << endl;
		if(ans == n)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}