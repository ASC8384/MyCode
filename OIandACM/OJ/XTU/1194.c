#include <stdio.h>

const int mo = 1000000007;
unsigned long long f[1001];
unsigned long long c[1001][1001];

int main()
{
	int k, n;
	scanf("%d%d", &n, &k);

	f[1] = 0;
	f[2] = 1;
	for(int i = 3; i <= 1000; i++)
		f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % mo;
	
	c[0][0] = 1;
	for(int i = 1; i <= 1000; i++){
		c[i][i] = c[i][0] = 1;
		c[i][1] = i;
	}
	for(int i = 2; i <= 1000; i++)
		for(int j = 2; j < i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mo;

	while(n + k != 0){
		if(k == 0)
			printf("1\n");
		else if(k == 1)
			printf("0\n");
		else
			printf("%I64d\n", c[n][k] * f[k] % mo);
		scanf("%d%d", &n, &k);
	}
	return 0;
}