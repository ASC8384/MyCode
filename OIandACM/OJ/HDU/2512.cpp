#include <bits/stdc++.h>
using namespace std;

int a[2333][2333];

int main()
{
	int mo = 1000;
	int n;

	for(int i = 1; i <= 2000; i++){
		a[i][i] = i;
		a[i][1] = 1;
	}
	for(int i = 2; i <= 2000; i++){
		for(int j = 2; j <= i; j++)
			a[i][j] = (a[i-1][j-1] + j*a[i-1][j]) % mo;
	}

	scanf("%d", &n);
	//while(~scanf("%d", &n)){
	for(int i = 0; i < n; i++){
		int nn;
		scanf("%d", &nn);
		int sum = 0;
		for(int i = 1; i <= nn; i++){
			sum += a[nn][i];
		}
		printf("%d\n", sum % mo);
	}
	return 0;
}