#include <stdio.h>

const int mo = 1000000007;

int main()
{
	int n, i;
	unsigned __int64 ans, a[3];

	scanf("%d", &n);
	while(n != 0){
		ans = 0;
		a[0] = n / 3;
		if(n % 3 == 1){
			a[1] = a[0] + 1;
			a[2] = a[0];
		}else if(n % 3 == 2){
			a[1] = a[2] = a[0] + 1;
		}else{
			a[1] = a[2] = a[0];
		}
		ans = a[0] * a[1] % mo * a[2] % mo;
		for(i = 0; i < 3; i++)
			ans = (ans + a[i] * (a[i] - 1) * (a[i] - 2) / 6) % mo;
		printf("%I64d\n", ans);
		scanf("%d", &n);
	}
	return 0;
}