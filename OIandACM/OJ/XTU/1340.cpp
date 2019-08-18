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
	for(int i = 0; i <= 21; i++)
		a[i][21 - i] = a[i][21 + i] = 1;
	for(int i = 1; i <= 21; i++)
		for(int j = 22 - i; j <= 20 + i; j++)
			a[i][j] = a[i-1][j-1] + a[i-1][j] + a[i-1][j+1];
	for(int i = 22; i <= 42; i++)
		for(int j = i - 21; j <= 63 - i; j++)
			a[i][j] = a[i-1][j-1] + a[i-1][j] + a[i-1][j+1];

	while(t--){
		printf("%I64d\n", a[init()][21]);
	}
	return 0;
}