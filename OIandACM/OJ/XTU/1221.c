#include <stdio.h>

int main()
{
	__int64 n, k;
	scanf("%I64d", &k);

	while(k--){
		scanf("%I64d", &n);
		__int64 max = 0, ans = 0;
		while(n){
			if(n & 1)
				ans++;
			else{
				if(ans > max)
					max = ans;
				ans = 0;
			}
			n >>= 1;
		}
		if(ans > max)
			max = ans;
		ans = 0;
		printf("%I64d\n", max);
	}
	return 0;
}