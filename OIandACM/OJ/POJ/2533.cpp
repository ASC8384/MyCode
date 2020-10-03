#include <cstdio>

int main() {
	int n;
	int f[2333];
	int a[2333];
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		f[i] = 1;
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++)
			if(a[j] < a[i])
				if(f[j] + 1 > f[i])
					f[i] = f[j] + 1;
	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(f[i] > ans)
			ans = f[i];
	printf("%d\n", ans);

	return 0;
}