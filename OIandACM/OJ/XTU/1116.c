#include <stdio.h>

int main()
{
	int a;
	int ans, t, n, w;
	scanf("%d", &a);

	while(a != 0){
		ans = 0;
		w = 0;
		n = a;
		while(a){
			t = a % 10;
			w++;
			//ans += t * t * t;
			a /= 10;
		}
		a = n;
		while(a){
			t = a % 10;
			int i, j = 1;
			for(i = 0; i < w; i++)
				j *= t;
			ans += j;
			a /= 10;
		}
		if(ans == n){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
		scanf("%d", &a);
	}
	return 0;
}