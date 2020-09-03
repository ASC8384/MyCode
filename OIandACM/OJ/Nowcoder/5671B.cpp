#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define inf 0x7fffffff
#define ll unsigned long long
#define maxn 100005
#define mod 1000000007
ll f[20000001], ans[20000001], b[20000001];
ll qpow(ll a, ll b) {
	ll res = 1;
	a %= mod;
	while(b) {
		if(b & 1) {
			res = (res * a) % mod;
		}
		b >>= 1;
		a = (a * a) % mod;
	}
	return res;
}
//f(n)=f(n-1)*pow(2,n)-1/pow(2,n)
int main() {
	ll i, j, k, t, n, m;
	ans[1] = f[1] = 1ll * qpow(2, mod - 2);
	//b[0]=1,b[1]=2;
	//for(i=1;i<=20000000;i++) b[i]=b[i-1]*2%
	ll tmp = 2, inv = ans[1], ni = ans[1];
	for(i = 2; i <= 20000000; i++) {
		tmp	 = 2 * tmp % mod;
		ni	 = inv * ni % mod;
		f[i] = (f[i - 1] * ((tmp - 1 + mod) % mod) % mod * ni) % mod;
		//f[i]=((f[i-1]*(tmp-1))%mod*(qpow(tmp,mod-2)%mod))%mod;
		ans[i] = (f[i] ^ ans[i - 1]);
	}
	scanf("%llu", &t);
	while(t--) {
		scanf("%llu", &n);
		printf("%llu\n", ans[n] % mod);
	}
}

/*
/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-27 14:24:26

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int			  a[size];
map<int, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		bool ok = true;
		int	 pos;
		m.clear();
		int top = 0;
		for(pos = 1; pos <= n; pos++) {
			if(++m[a[pos]] == 3)
				break;
			else
				top = 0;
			if(m[a[pos]] == 2) {
				;
			}
		}
		m.clear();
		top = 0;
		if(ok && pos < n) {
			for(pos; pos <= n; pos++) {
				if(m[a[pos]] == 0) {
					top++;
					m[a[pos]]++;
				} else {
					if(top == k) {
						;
					}
				}
			}
		}
		if(ok) {
			cout << "YES" << '\n';
		} else {
		}
	}

	return 0;
}
*/