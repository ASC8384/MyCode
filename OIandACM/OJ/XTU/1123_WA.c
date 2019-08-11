#include <stdio.h>

int main()
{
	int t, n, k, i;
	int a[1009];
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &k);
		for(i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		for(i = k + 1; i <= n; i++)
			if(a[i] != a[k]){
				printf("-1\n");
				i = n + 2;
			}
		if(i <= n + 1){
			for(i = k - 1; i > 0; i--)
				if(a[i] != a[k]){
					printf("%d\n", i);
					break;
				}
		}

	}
	return 0;
}