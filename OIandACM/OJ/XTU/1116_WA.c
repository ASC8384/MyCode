#include <stdio.h>

int main()
{
	int a;
	int ans, t, n;
	scanf("%d", &a);

	while(a != 0){
		ans = 0;
		n = a;
		while(a){
			t = a % 10;
			ans += t * t * t;
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