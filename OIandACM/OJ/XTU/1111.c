#include <stdio.h>

int main()
{
	int n, ans;
	int t, i;
	scanf("%d", &n);
	while(n != 0){
		ans = 0;
		for(i = 0; i < n; i++){
			scanf("%d", &t);
			if((t & 1) == 0)
				ans += t;
		}
		printf("%d\n", ans);
		scanf("%d", &n);
	}
	return 0;
}