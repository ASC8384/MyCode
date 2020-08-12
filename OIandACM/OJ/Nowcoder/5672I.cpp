/*#include <algorithm>
#include <cstdio>
#include <cstring>
#define O 1ll
#define ll long long
using namespace std;
const ll N	 = 5009;
ll		 mod = 1e9 + 7;
ll		 n, k, x[N], y[N], num[N], tmp[N], res[N], inv[N];
void	 Add(ll &x, ll y) {
	x += y;
	if(x >= mod)
		x -= mod;
}
void exGCD(ll a, ll b, ll &x, ll &y) {
	if(!b)
		x = 1, y = 0;
	else
		exGCD(b, a % b, y, x), y -= a / b * x;
}
ll Inv(ll x) {
	ll xx, yy;
	exGCD(x, mod, xx, yy);
	Add(xx, mod);
	return xx;
}
void Lagrange() {
	for(ll i = 1; i <= n; i++) {
		ll den = 1, lst = 0;
		for(ll j = 1; j <= n; j++)
			if(i != j)
				den = O * den * (x[i] - x[j] + mod) % mod;
		den = O * y[i] * Inv(den) % mod;
		for(ll j = 0; j < n; j++) {
			tmp[j] = O * (num[j] - lst + mod) * inv[i] % mod;
			Add(res[j], O * den * tmp[j] % mod), lst = tmp[j];
		}
	}
}
void Pre() {
	num[0] = 1;
	for(ll i = 1; i <= n; swap(num, tmp), i++) {
		tmp[0] = 0;
		inv[i] = Inv(mod - x[i]);
		for(ll j = 1; j <= i; j++)
			tmp[j] = num[j - 1];
		for(ll j = 0; j <= i; j++)
			Add(tmp[j], O * num[j] * (mod - x[i]) % mod);
	}
}
ll Calc(ll x) {
	ll ret = 0, var = 1;
	for(ll i = 0; i < n; var = O * var * x % mod, i++)
		Add(ret, O * var * res[i] % mod);
	return ret;
}

int main() {
	// scanf("%lld", &n); //, &mod);
	n	 = 5;
	x[1] = 2;
	x[2] = 3;
	x[3] = 4;
	x[4] = 5;
	x[5] = 107;
	y[1] = 2;
	y[2] = 24;
	y[3] = 264;
	y[4] = 3240;
	y[5] = 736935633;
	// for(ll i = 1; i <= n; i++)
	// scanf("%lld%lld", &x[i], &y[i]);
	// x[1] = 2, y
	Pre(),
		Lagrange();
	for(ll k = 1; k <= 10; k++)
		printf("%lld,", Calc(k));
	printf("%lld ", Calc(107));
	return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define per(i, a, n) for(int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int>	   VI;
typedef long long	   ll;
typedef pair<int, int> PII;
ll					   mod = 998244353;
ll					   powmod(ll a, ll b) {
	ll res = 1;
	a %= mod;
	assert(b >= 0);
	for(; b; b >>= 1) {
		if(b & 1)
			res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}
// head
int _, n;

inline int init(void) {
	int	 x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar())
		;
	for(x = 0; isdigit(c); c = getchar())
		x = (x << 1) + (x << 3) + c - '0';
	return x;
}

namespace linear_seq {
const int N = 10010;
ll		  res[N], base[N], _c[N], _md[N];

vector<int> Md;
void		mul(ll *a, ll *b, int k) {
	   rep(i, 0, k + k) _c[i]						= 0;
	   rep(i, 0, k) if(a[i]) rep(j, 0, k) _c[i + j] = (_c[i + j] + a[i] * b[j]) % mod;
	   for(int i = k + k - 1; i >= k; i--)
		   if(_c[i])
			   rep(j, 0, SZ(Md)) _c[i - k + Md[j]] = (_c[i - k + Md[j]] - _c[i] * _md[Md[j]]) % mod;
	   rep(i, 0, k) a[i] = _c[i];
}
int solve(ll n, VI a, VI b) {
	ll	ans = 0, pnt = 0;
	int k = SZ(a);
	assert(SZ(a) == SZ(b));
	rep(i, 0, k) _md[k - 1 - i] = -a[i];
	_md[k]						= 1;
	Md.clear();
	rep(i, 0, k) if(_md[i] != 0) Md.push_back(i);
	rep(i, 0, k) res[i] = base[i] = 0;
	res[0]						  = 1;
	while((1ll << pnt) <= n)
		pnt++;
	for(int p = pnt; p >= 0; p--) {
		mul(res, res, k);
		if((n >> p) & 1) {
			for(int i = k - 1; i >= 0; i--)
				res[i + 1] = res[i];
			res[0]						 = 0;
			rep(j, 0, SZ(Md)) res[Md[j]] = (res[Md[j]] - res[k] * _md[Md[j]]) % mod;
		}
	}
	rep(i, 0, k) ans = (ans + res[i] * b[i]) % mod;
	if(ans < 0)
		ans += mod;
	return ans;
}
VI BM(VI s) {
	VI	C(1, 1), B(1, 1);
	int L = 0, m = 1, b = 1;
	rep(n, 0, SZ(s)) {
		ll d			   = 0;
		rep(i, 0, L + 1) d = (d + (ll)C[i] * s[n - i]) % mod;
		if(d == 0)
			++m;
		else if(2 * L <= n) {
			VI T = C;
			ll c = mod - d * powmod(b, mod - 2) % mod;
			while(SZ(C) < SZ(B) + m)
				C.pb(0);
			rep(i, 0, SZ(B)) C[i + m] = (C[i + m] + c * B[i]) % mod;
			L						  = n + 1 - L;
			B						  = T;
			b						  = d;
			m						  = 1;
		} else {
			ll c = mod - d * powmod(b, mod - 2) % mod;
			while(SZ(C) < SZ(B) + m)
				C.pb(0);
			rep(i, 0, SZ(B)) C[i + m] = (C[i + m] + c * B[i]) % mod;
			++m;
		}
	}
	return C;
}

int gao(VI a, ll n) {
	VI c = BM(a);
	c.erase(c.begin());
	rep(i, 0, SZ(c)) c[i] = (mod - c[i]) % mod;
	return solve(n, c, VI(a.begin(), a.begin() + SZ(c)));
}
}; // namespace linear_seq
void putit(int x) {
	if(x / 10)
		putit(x / 10);
	putchar(x % 10 + '0');
}
int main() {
	vector<int> v{1, 2, 24, 264, 3240, 333105751, 665498870, 996467951, 658392622, 316746799};
	// v.push_back(10);
	// v.push_back(180);
	// v.push_back(2610);
	// v.push_back(34200);
	// v.push_back(423000);
	// v.push_back(5040000);
	// v.push_back(58500000);
	// v.push_back(666000000);
	// v.push_back(482289529);
	// v.push_back(943963054);
	n	= init();
	mod = init();

	// VI{1,2,4,7,13,24}
	for(int i = n; i >= 1; i--) {
		int tmp = init();
		putit(linear_seq::gao(v, tmp - 1));
		putchar('\n');
	}
	// printf("%d ", );

	return 0;
}

// O(n*n)