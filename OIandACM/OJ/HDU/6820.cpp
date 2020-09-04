#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int	maxn = 5e4 + 10;
vector<int> tree[maxn];

int N, c;
int val[maxn], trap[maxn];
int dp[maxn][5][3];
int ans;

void dfs(int u, int fa) {
	dp[u][trap[u]][trap[u]] = val[u];
	for(int i = 0; i < tree[u].size(); i++) {
		int v = tree[u][i];
		if(v == fa)
			continue;
		dfs(v, u);
		for(int j = 0; j <= c; j++) {
			for(int k = 0; j + k <= c; k++) {
				ans = max(ans, dp[u][j][1] + dp[v][k][1]);
				if(j + k < c)
					ans = max(ans, dp[u][j][0] + dp[v][k][0]);
				if(k)
					ans = max(ans, dp[u][j][0] + dp[v][k][1]);
				if(j)
					ans = max(ans, dp[u][j][1] + dp[v][k][0]);
			}
		}
		for(int k = 0; k + trap[u] <= c; k++) {
			dp[u][k + trap[u]][0] = max(dp[u][k + trap[u]][0], dp[v][k][0] + val[u]);
			if(k)
				dp[u][k + trap[u]][1] = max(dp[u][k + trap[u]][1], dp[v][k][1] + val[u]);
		}
	}
}

int main() {
	int t, u, v;
	scanf("%d", &t);
	c = 2;
	while(t--) {
		scanf("%d%d", &N, &k);
		for(int i = 0; i < N; i++)
			tree[i].clear();
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < N; i++)
			scanf("%d%d", &val[i], &trap[i]);
		for(int i = 0; i < N - 1; i++) {
			scanf("%d%d", &u, &v);
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		ans = 0;
		dfs(0, -1);
		printf("%d\n", ans);
	}
}

