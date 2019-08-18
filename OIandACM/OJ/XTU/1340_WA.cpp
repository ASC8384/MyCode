#include <bits/stdc++.h>
using namespace std;

inline int init(void){
	int x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

unsigned long long a[49][49];

int main()
{
	int t = init();

	while(t--){
		int n = init();
	// for(int n = 1; n <= 42; n++){
		memset(a, 0, sizeof(a));
		a[0][0] = 0;
		a[0][1] = 1;
		for(int j = 1; j <= n >> 1; j++)
			a[j][j] = 1;

		for(int j = 2; j <= (n+1) >> 1; j++){
			for(int i = 1; i <= j - 1; i++)
				a[i][j] = a[i - 1][j - 1] + a[i][j - 1] + a[i + 1][j - 1];
			a[0][j] = a[0][j - 1] + a[1][j - 1];
		}
		for(int j = 1 + ((n+1) >> 1); j <= n; j++){
			for(int i = 1; i <= n - j; i++)
				a[i][j] = a[i - 1][j - 1] + a[i][j - 1] + a[i + 1][j - 1];
			a[0][j] = a[0][j - 1] + a[1][j - 1];
		}

		printf("%I64d\n", (a[0][n] << 1) - 1);
	}
	return 0;
}