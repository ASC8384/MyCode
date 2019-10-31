#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int res[N][N];
int a[N][N];

void mul(int a[][N], int b[][N], int mo){
	int tmp[N][N];
	memset(tmp, 0, sizeof(tmp));
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				tmp[i][j] += a[i][k] * b[k][j] % mo;
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			a[i][j] = tmp[i][j] % mo;
		}
	}
}

void pow(int a[][N], int n, int mo){
	//int res[N][N];
	memset(res, 0, sizeof(res));
	for(int i = 0; i < N; i++){
		res[i][i] = 1;
	}
	while(n){
		if(n & 1)
			mul(res, a, mo);
		mul(a, a, mo);
		n >>= 1;
	}
}

int main()
{
	int k, mo;

	while(scanf("%d%d", &k, &mo) == 2){
		if(k < 10){
			printf("%d", k % mo);
			continue;
		}
		memset(a, 0, sizeof(a));
		for(int i = 0; i < N; i++)
			scanf("%d", &a[0][i]);
		for(int i = 1; i < N; i++)
			a[i][i - 1] = 1;
		pow(a, k - 9, mo);
		int ans = 0;
		for(int i = 0; i < N; i++)
			ans += res[0][i] * (9-i) % mo;
		printf("%d\n", ans % mo);
	}
	return 0;
}