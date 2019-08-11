#include <stdio.h>

int main()
{
	int n;
	int x, y;
	scanf("%d", &n);

	while(n--){
		scanf("%d%d", &x, &y);
		int ans = 0;
		x = x ^ y;
		while(x){
			if(x & 1)
				ans++;
			x >>= 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}