/*#include <bits/stdc++.h>
using namespace std;



unsigned long long mo = 998244353;

unsigned long long f[10];
int				   t[10] = {1};

int main() {
	int n;
	n = init();

	for(int i = 1; i <= 10; i++)
		t[i] = 10 * t[i - 1];

	int tmp = 0;

	for(int i = 1; i <= n; i++) {
		// if(i % t[1])
		f[i] = 1;
		for(int j = 1; j <= n; j++) {
			if(j & 1)
				f[i] = f[i] * 10 % mo;
			else
				f[i] = f[i] * 9 % mo;
		}
	}
	for(int i = n; i; i--)
		cout << f[i] << " ";

	return 0;
}*/
// dujiao banzi
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
const ll			   mod = 998244353;
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
	vector<int> v;
	v.push_back(10);
	v.push_back(180);
	v.push_back(2610);
	v.push_back(34200);
	v.push_back(423000);
	v.push_back(5040000);
	v.push_back(58500000);
	v.push_back(666000000);
	v.push_back(482289529);
	v.push_back(943963054);
	n = init();

	// VI{1,2,4,7,13,24}
	for(int i = n; i >= 1; i--) {
		putit(linear_seq::gao(v, i - 1));
		putchar(' ');
	}
	// printf("%d ", );

	return 0;
}
// O(n*n)
