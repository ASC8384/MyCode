#include <stdio.h>

int main()
{
	int n;
	int i, j, ans;
	ans = 0;
	scanf("%d", &n);

	while(n != 0){
		ans++;
		printf("Case %d:\n", ans);
		for(i = 1; i <= 3*n; i++){
			for(j = 1; j <= n; j++)
				printf("XTU");
			putchar('\n');
		}
		scanf("%d", &n);
	}
	return 0;
}