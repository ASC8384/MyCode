typedef long long ll;

const int size = 16;
// const ll  mod  = 1e9 + 7;
ll mod;

struct mat {
	// n 行 m 列
	ll	a[size][size];
	int n, m;
	mat(int x = 0, int y = 0) : n(x), m(y) {}
	void prt() {
		printf("%lld %lld\n", n, m);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				printf("%lld ", a[i][j]);
			}
			putchar('\n');
		}
	}
	void init() { memset(a, 0, sizeof(a)); }
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