#include <stdio.h>

int main()
{
	int n, x;
	int i, ans;
	scanf("%d", &n);

	while(n--){
		scanf("%d", &x);
		for(i = 2; i <= x; i++){
			ans = 0;
			while(x % i == 0 && x){
				++ans;
				x /= i;
			}
			if(ans){
				printf("%d", i);
				if(ans != 1)
					printf("^%d", ans);
				if(x != 1)
					printf("*");
			}
		}
		putchar('\n');
	}
	return 0;
}