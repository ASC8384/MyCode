#include <stdio.h>

int main()
{
	int x;
	int i, ans;
	//scanf("%d", &n);

	while(scanf("%d", &x) == 1){
		ans = 0;
		while(x % 2 == 0){
			++ans;
			x /= 2;
		}
		if(ans){
			printf("%d", 2);
			if(ans != 1)
				printf("^%d", ans);
			if(x != 1)
				printf("*");
		}
		//scanf("%d", &x);
		for(i = 3; x != 1; i += 2){
			ans = 0;
			while(x % i == 0){
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