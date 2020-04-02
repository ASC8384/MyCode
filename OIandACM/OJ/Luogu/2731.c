#include <stdio.h>

int n, m, i;
int u, v;
int cnt;
int g[2333][2333], du[2333];
int stk[2333];

void dfs(int u) {
	int i;
	for(i = 1; i <= n; i++) {
		if(g[u][i]) {
			g[u][i]--;
			g[i][u]--;
			dfs(i);
		}
	}
	stk[++cnt] = u;
}

int max(int a, int b) { return a > b ? a : b; }

int main() {
	int m;
	scanf("%d", &m);
	for(i = 1; i <= m; i++) {
		scanf("%d%d", &v, &u);
		g[v][u]++;
		g[u][v]++;
		du[v]++;
		du[u]++;
		n = max(n, v);
		n = max(n, u);
	}
	int s = 1;
	for(i = 1; i <= n; i++) {
		if(du[i] & 1) {
			s = i;
			break;
		}
	}
	dfs(s);
	for(i = cnt; i; i--) {
		printf("%d\n", stk[i]);
	}
	return 0;
}