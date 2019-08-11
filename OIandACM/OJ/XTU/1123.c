#include <stdio.h>

int main()
{
	int t, n, k, i, f;
	int a[1009];
	scanf("%d", &t);

	while(t--){
		f = 1;
		scanf("%d%d", &n, &k);
		for(i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		for(i = k + 1; i <= n; i++)
			if(a[i] != a[k]){
				printf("-1\n");
				f = 0;
				break;
			}
		if(f){
			for(i = k - 1; i > 0; i--)
				if(a[i] != a[k]){
					printf("%d\n", i);
					f = 0;
					break;
				}
		}
		if(f)
			printf("0\n");
	}
	return 0;
}