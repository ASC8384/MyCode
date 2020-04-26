/***
 * @Author       : ASC_8384
 * @License      : CC0
 * @Website      : http://www.ASC8384.top
 * @FilePath     : \OIandACM\OJ\Luogu\2055.cpp
 * @Date         : 2020-04-26 17:18:06
 * @LastEditTime : 2020-04-26 17:18:07
 * @Description  : P2055
 */

#include <bits/stdc++.h>
using namespace std;

int	 n;
bool g[2333][2333];
bool vis[2333], hom[2333], sch[2333];
int	 mat[2333];

bool dfs(int x) {
	for(int i = 1; i <= n; i++) {
		if(vis[i] || !g[x][i] || !sch[i])
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
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		// memset(g, 0, sizeof(g));
		memset(mat, 0, sizeof(mat));
		for(int i = 1; i <= n; i++)
			cin >> sch[i];
		for(int i = 1; i <= n; i++) {
			cin >> hom[i];
			if(!sch[i])
				hom[i] = 0;
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++)
				cin >> g[i][j];
			if(sch[i])
				g[i][i] = 1;
		}

		int ans = 0;
		for(int i = 1; i <= n; i++) {
			memset(vis, false, sizeof(vis));
			if(hom[i] || dfs(i)) {
				ans++;
			} else {
				ans = 0;
				break;
			}
		}

		if(ans == n)
			cout << "^_^" << endl;
		else
			cout << "T_T" << endl;
	}
	return 0;
}