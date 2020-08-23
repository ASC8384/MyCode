/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-23 18:29:26
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 11;
const ll  mod  = 1e8;

struct mat {
	// n 行 m 列
	ll	a[size][size];
	int n, m;
	mat(int x = 0, int y = 0) : n(x), m(y) {}
	void prt() {
		printf("%d %d\n", n, m);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				printf("%d ", a[i][j]);
			}
			putchar('\n');
		}
	}
	mat operator*(const mat &x) const { // 矩阵乘法
		mat ret;
		ret.n = n;
		ret.m = x.m;
		memset(ret.a, 0, sizeof(ret.a));
		for(int i = 1; i <= ret.n; i++)
			for(int j = 1; j <= ret.m; j++)
				for(int k = 1; k <= m; k++)
					ret.a[i][j] = (ret.a[i][j] + a[i][k] * x.a[k][j] % mod) % mod;
		return ret;
	}
	friend mat operator^(mat &y, ll t) { // 矩阵快速幂
		mat x	= y;
		mat ret = mat(x.n, x.n);
		memset(ret.a, 0, sizeof(ret.a));
		for(int i = 1; i <= x.n; i++) {
			ret.a[i][i] = 1;
		}
		while(t) {
			if(t & 1)
				ret = ret * x;
			x = x * x;
			t >>= 1;
		}
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	mat fib = mat(2, 2);
	memset(fib.a, 0, sizeof(fib.a));
	fib.a[2][2] = 0;
	fib.a[1][1] = fib.a[1][2] = fib.a[2][1] = 1;

	mat nn = mat(2, 1);
	memset(nn.a, 0, sizeof(nn.a));
	nn.a[1][1] = 1;
	nn.a[2][1] = 1;

	// mat fibb = fib;
	n = __gcd(n, m);

	if(n <= 2)
		cout << 1;
	else
		cout << ((fib ^ (n - 2)) * nn).a[1][1];

	return 0;
}