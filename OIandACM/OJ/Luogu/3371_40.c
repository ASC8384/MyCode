#include <stdio.h>

long long u[10008], v[10008], w[10008];
long long dis[10008];

long long inf = 2147483647; // 0x7fffffff; //(1 << 31) - 1; // 0x7fffffff;

int main() {
	int n, m, s;
	scanf("%d%d%d", &n, &m, &s);

	for(int i = 1; i <= m; i++)
		scanf("%d%d%d", u + i, v + i, w + i);

	for(int i = 1; i <= n; i++)
		dis[i] = inf;
	dis[s] = 0;

	for(int k = 1, is = 1; k < n && is; k++) {
		is = 0;
		for(int i = 1; i <= m; i++) {
			if(dis[v[i]] > dis[u[i]] + w[i]) {
				dis[v[i]] = dis[u[i]] + w[i];
				is		  = 1;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		printf("%lld ", dis[i]);

	return 0;
}