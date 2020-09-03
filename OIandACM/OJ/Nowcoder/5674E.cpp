#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
#define maxn 100005
#define mod 998244353
ll	 p[2][maxn], c0[2][maxn], p1[maxn], c1[2][maxn], m, ansc[maxn];
void divide(ll n, ll x) {
	m = 0;
	for(ll i = 2; i <= sqrt(n); ++i) {
		if(n % i == 0) {
			p[x][++m] = i;
			c0[x][m]  = 0;
			while(n % i == 0) {
				n /= i;
				c0[x][m]++;
			}
		}
	}
	if(n > 1) {
		p[x][++m] = n;
		c0[x][m]  = 1;
	}
	//for(int i=1;i<=m;++i){
	//	cout<<p[i]<<"^"<<c[i]<<end1;
	//}
}
ll qpow(ll a, ll b) {
	ll res = 1;
	a %= mod;
	while(b) {
		if(b & 1)
			res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}
ll	num[1000000];
int main() {
	ll i, n, j, k, t, a, b, c, d, x, y, ans = 0, x1, y1;
	scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &x, &y);
	divide(x, 0);
	x1 = m;
	divide(y, 1);
	y1 = m;
	i = 1, j = 1, t = 1;
	while(i <= x1 && j <= y1) {
		if(p[0][i] == p[1][j])
			p1[t] = p[0][i], c1[0][t] = c0[0][i], c1[1][t] = c0[1][j], i++, j++, t++;
		else if(p[0][i] < p[1][j])
			i++;
		else
			j++;
	}
	if(b == 0 || d == 0) {
		printf("1\n");
		return 0;
	}
	a = max(1ll, a);
	c = max(1ll, c);
	for(i = 1; i < t; i++) {
		for(j = a; j <= b; j++) {
			ll tmp = c1[0][i] * j, tmp2 = c1[1][i] * c;
			ll bei = 0;
			if(tmp > tmp2) {
				if(c1[1][i] * d <= tmp) {
					ansc[i] += (b - j + 1) * (c1[1][i] * c + c1[1][i] * d) * (d - c + 1) / 2;
					break;
				}
				bei = (tmp - tmp2) / c1[1][i]; //+((tmp-tmp2)%c[1][i]!=0);
				bei++;
				ansc[i] += (tmp2 + tmp2 + c1[1][i] * (bei - 1)) * bei / 2;
			}
			ansc[i] += tmp * (d - c + 1 - bei);
		}
	}
	ll ttt = 1;
	for(i = 1; i < t; i++) {
		ttt = (ttt * qpow(p1[i], ansc[i])) % mod;
	}
	printf("%lld\n", ttt);
}
