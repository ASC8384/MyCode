#include <stdio.h>

int main()
{
	int n;

	while(scanf("%d", &n) == 1){
		int ans = 0;
		if(n >= 0){
			while(n){
				if(n & 1)
					ans++;
				n >>= 1;
			}
			printf("%d\n", ans);
		}else{
			__int64 x = 4294967296 + n;
			while(x){
				if(x & 1)
					ans++;
				x >>= 1;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
//错误： 程序中有游离的'\xxx'