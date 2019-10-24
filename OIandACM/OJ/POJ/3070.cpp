#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <cstdio>
#define mo 10000
using namespace std;

int n;

void multiply(int a[][2], int b[][2]){
	int tmp[2][2];
	memset(tmp, 0, sizeof(tmp));
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			for(int k = 0; k < 2; k++)
				tmp[i][j] = (tmp[i][j] + a[i][k]*b[k][j]) % mo;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			a[i][j] = tmp[i][j];
}

int quick_pow_mod(int x[][2], int n){
	int res[2][2];
	res[0][0] = res[1][1] = 1;
	res[0][1] = res[1][0] = 0;
	while(n){
		if(n & 1)
			multiply(res, x);
		multiply(x, x);
		n >>= 1;
	}
	return res[0][1];
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	// while(cin >> n && n != -1){
	while(~scanf("%d", &n) && n != -1){
		int a[2][2];
		a[0][0] = a[0][1] = a[1][0] = 1;
		a[1][1] = 0;
		printf("%d\n", quick_pow_mod(a, n));
		//cout << quick_pow_mod(a, n) << endl;
	}

	return 0;
}