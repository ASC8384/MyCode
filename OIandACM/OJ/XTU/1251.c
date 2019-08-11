#include <stdio.h>

int main()
{
	int k, n, t, a, f;
	register int i;
	scanf("%d", &k);

	while(k--){
		scanf("%d", &n);
		f = 0;
		if(n <= 100)
			t = 1;
		else
			t = n - 90;
		for(i = t; i < n; i++){
			t = i;
			a = 0;
			while(t){
				a += t % 10;
				t /= 10;
			}
			if(a + i == n){
				f = 1;
				break;
			}
		}
		if(f)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}