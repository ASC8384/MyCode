#include <stdio.h>

int main()
{
	int n;
	int x, y;
	scanf("%d", &n);

	while(n--){
		scanf("%d%d", &x, &y);
		int ans = 0;
		if(x < y){
			int t = y;
			y = x;
			x = t;
		}
		if(x == y)
			printf("0\n");
		else{
			while(x){
				if(y){
					if((x&1) != (y&1)){
						ans++;
						x >>= 1;
						y >>= 1;
					}else{
						x >>= 1;
						y >>= 1;
					}
				}else{
					x >>= 1;
					ans++;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}