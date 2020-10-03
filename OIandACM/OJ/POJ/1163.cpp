#include <cstdio>
#include <cstdlib>
#include <cstring>

int a[233][233];
int f[233][233];

int max(int x, int y) {
	return (x > y) ? x : y;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= i; j++) {
				scanf("%d", &a[i][j]);
				f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + a[i][j];
			}
		int ans = 0;
		for(int i = 1; i <= n; i++)
			if(f[n][i] > ans)
				ans = f[n][i];
		printf("%d\n", ans);
	}

	return 0;
}