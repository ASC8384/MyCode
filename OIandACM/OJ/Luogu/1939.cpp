/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-11-19 21:18:37
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// const int size = 2e5 + 9;
const ll mod = 1e9 + 7;

//typedef long long ll;

// const ll  mod  = 1e9 + 7;
// ll mod;

const int size = 16;

struct mat {
	// n 行 m 列
	ll	a[size][size];
	int n, m;
	mat(int x = 0, int y = 0) {
		this->n = x;
		this->m = y;
		memset(this->a, 0, sizeof(this->a));
	}
	void prt() {
		cout << n << ' ' << m << '\n';
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	void init() { memset(a, 0, sizeof(a)); }
	mat	 operator*(const mat &x) const { // 矩阵乘法
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

	int t = 1;
	cin >> t;
	mat a(3, 3);
	// a.init();
	a.a[1][1] = a.a[1][3] = a.a[2][1] = a.a[3][2] = 1;
	// a.prt();
	mat b(3, 1);
	// b.prt();
	b.a[1][1] = b.a[2][1] = b.a[3][1] = 1;
	while(t--) {
		int n;
		cin >> n;
		if(n <= 3)
			cout << "1\n";
		else
			// mat x = (mat)(a ^ (n - 3)) * b;
			cout << ((mat)(a ^ (n - 3)) * b).a[1][1] << '\n';
	}

	return 0;
}