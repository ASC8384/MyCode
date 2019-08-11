#include <stdio.h>

unsigned long long a[41][2];

int main()
{
	int n;
	scanf("%d", &n);
	a[1][0] = a[1][1] = 1;
	for(int i = 2; i <= 40; i++){
		a[i][0] = a[i - 1][1] + a[i - 1][0];
		a[i][1] = a[i - 1][0];
	}

	while(n){
		printf("%I64d\n", a[n][0] + a[n][1]);
		scanf("%d", &n);
	}
	return 0;
}