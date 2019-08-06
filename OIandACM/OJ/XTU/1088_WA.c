#include <stdio.h>

int main()
{
	int n;
	register int i;
	int a[10010];
	a[0] = 0;
	a[1] = 1;
	for(i = 2; i <= 10000; i++){
		a[i] = a[i-1] * i % 10007;
	}
	scanf("%d", &n);
	while(n != -1){
		printf("%d\n", a[n]);
		scanf("%d", &n);
	}
	return 0;
}