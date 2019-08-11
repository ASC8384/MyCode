#include <stdio.h>

const int mo = 1000000007;

int main()
{
	int n;
	int ans, i;

	scanf("%d", &n);
	while(n != 0){
		ans = 0;
		for(i = 1; n - 2 * i > 0; i++)
			ans = (ans + n - 2 * i) % mo;
		printf("%d\n", ans);
		scanf("%d", &n);
	}
	return 0;
}
// t = n >> 1;
// ans = t * (n - t - 1) % mo;