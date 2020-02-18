#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

bool		is_root[6666];
bool		vis[6666];
vector<int> son[6666];
int			v[6666]; // no
int			f[6666]; // yes
int			n;
int			a, b;
int			root = 0;

void dfs(int node) {
	vis[node] = true;
	// for(int i = 1; i <= n; i++) {
	int ll = son[node].size();
	for(int i = 0; i < ll; i++) {
		int sons = son[node][i];
		// if(father[i] == node && !vis[i]) {
		dfs(sons);
		f[node] += v[sons];
		v[node] += max(v[sons], f[sons]);
	}
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);

	while(~scanf("%d", &n)) {
		memset(is_root, 0, sizeof(is_root));
		memset(vis, 0, sizeof(vis));
		memset(v, 0, sizeof(v));
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++)
			son[i].clear();

		for(int i = 1; i <= n; i++)
			scanf("%d", &f[i]);
		while(scanf("%d%d", &a, &b) == 2 && a != 0 && b != 0) {
			// while(cin >> a >> b && a != 0 && b != 0) {
			// father[a]  = b;
			son[b].push_back(a);
			is_root[a] = true;
		}

		for(int i = 1; i <= n; i++)
			if(!is_root[i]) {
				root = i;
				break;
			}

		dfs(root);
		// cout << max(f[root], v[root]) << endl;
		printf("%d\n", max(f[root], v[root]));
	}

	return 0;
}