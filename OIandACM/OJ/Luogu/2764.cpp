/***
 * @Author       : ASC_8384
 * @License      : CC0
 * @Website      : http://www.ASC8384.top
 * @FilePath     : \OIandACM\OJ\Luogu\2764.cpp
 * @Date         : 2020-04-26 17:42:47
 * @LastEditTime : 2020-04-26 17:42:47
 * @Description  : P2764
 */

#include <bits/stdc++.h>
using namespace std;

int	 n, m;
int	 mat[666];
bool g[666][666];
bool vis[666];

bool dfs(int x) {
	for(int i = n + 1; i <= 2 * n; i++) {
		if(vis[i] || !g[x][i])
			continue;
		vis[i] = true;
		if(!mat[i] || dfs(mat[i])) {
			mat[i] = x;
			mat[x] = i;
			return true;
		}
	}
	return false;
}

int match() {
	int ret = 0;
	for(int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		if(dfs(i))
			ret++;
	}
	return ret;
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int v, u;
		cin >> u >> v;
		g[u][v + n] = 1;
	}
	int ans = match();
	memset(vis, false, sizeof(vis));
	for(int i = 1; i <= n; i++) {
		if(vis[i])
			continue;
		int x = i + n;
		do {
			printf("%d ", x = x - n);
		} while(vis[x] = 1, x = mat[x]);
		putchar('\n');
	}
	cout << n - ans << endl;
	return 0;
}