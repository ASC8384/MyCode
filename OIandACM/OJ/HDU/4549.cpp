#include <bits/stdc++.h>
using namespace std;

const unsigned long long N = 2;
unsigned long long res[N][N];
unsigned long long a[N][N];

void mul(unsigned long long a[][N], unsigned long long b[][N], unsigned long long mo){
	unsigned long long tmp[N][N];
	memset(tmp, 0, sizeof(tmp));
	for(unsigned long long i = 0; i < N; i++){
		for(unsigned long long j = 0; j < N; j++){
			for(unsigned long long k = 0; k < N; k++){
				tmp[i][j] += a[i][k] * b[k][j] % mo;
			}
		}
	}
	for(unsigned long long i = 0; i < N; i++){
		for(unsigned long long j = 0; j < N; j++){
			a[i][j] = tmp[i][j] % mo;
		}
	}
}

unsigned long long pown(unsigned long long n, unsigned long long k, unsigned long long mo){
	unsigned long long res = 1;
	while(k){
		if(k & 1)
			res = res *n % mo;
		n = n * n % mo;
		k >>= 1;
	}
	return res;
}

void powa(unsigned long long a[][N], unsigned long long n, unsigned long long mo){
	//unsigned long long res[N][N];
	memset(res, 0, sizeof(res));
	for(unsigned long long i = 0; i < N; i++){
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
	unsigned long long x, y, k, mo;
	mo = 1000000007;

	while(scanf("%lld%lld%lld", &x, &y, &k) == 3){
		if(k == 0){
			printf("%lld\n", x % mo);
			continue;
		}
		if(k == 1){
			printf("%lld\n", y % mo);
			continue;
		}
		//memset(a, 0, sizeof(a));
		a[1][1] = 0;
		a[1][0] = a[0][0] = a[0][1] = 1;
		powa(a, k - 1, mo - 1);
		unsigned long long aa = res[1][0] % (mo-1);
		unsigned long long bb = res[0][0] % (mo-1);
		// printf("%lld %lld\n", aa, bb);
		//for(unsigned long long i = 0; i < N; i++)
			// ans += res[0][i] * (9-i) % mo;
		printf("%lld\n", pown(x, aa, mo) * pown(y, bb, mo) % mo);
	}
	return 0;
}