#include <stdio.h>

int main()
{
	int n;
	int i, j;
	int ans = 0;
	scanf("%d", &n);

	while(n != 0){
		printf("case %d:\n", ++ans);
		for(i = 1; i <= n; i++){
			for(j = n-i; j > 0; j--)
				putchar(' ');
			for(j = 1; j <= 2*i - 1; j++)
				printf("%d", i);
			putchar('\n');
		}
		scanf("%d", &n);
	}
	return 0;
}