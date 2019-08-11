#include <stdio.h>
#include <ctype.h>

inline int init(void){
	char c;
	int x;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

int main()
{
	int n = init();
	int i, a[133][123], j;//k;
	//scanf("%d", &n);

	while(n){
		for(i = 1; i <= n; i++)
			a[1][i] = init() % 2013;
			//scanf("%d", &a[1][i]);
		for(i = 2; i <= n; i++)
			for(j = 1; j <= n + 1 - i; j++)
				//for(k = 1; k <= )
				a[i][j] = (a[i-1][j+1] + a[i-1][j]) % 2013;
		printf("%d\n", a[n][1]);
		// scanf("%d", &n);
		n = init();
	}
	return 0;
}