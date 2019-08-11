#include <stdio.h>

int main()
{
	int k;
	int a, b, n, t, x;

	scanf("%d", &k);
	while(k--){
		scanf("%d%d%d", &a, &b, &n);
		int ans = 0;
		//x = 0;
		for(; a <= b; a++){
			t = a;
			x = 0;
			while(t){
				//x = t % 10;
				x += (t%10) * (t%10);
				t /= 10;
			}
			if(x % 10 == n)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}