#include <stdio.h>
#include <string.h>

unsigned long long a[44][44];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	for(int i = 0; i <= 33; i++)
		a[i][0] = 1;
	for(int j = 0; j <= 33; j++)
		a[0][j] = 1;
	for(int i = 1; i <= 33; i++)
		for(int j = 1; j <= 33; j++)
			a[i][j] = a[i - 1][j] + a[i][j - 1];

	while(n + m != 0){
		printf("%I64d\n", a[n][m]);
		scanf("%d%d", &n, &m);
	}
	return 0;
}