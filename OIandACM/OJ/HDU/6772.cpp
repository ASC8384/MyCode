/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-23 12:30:00
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC		  optimize(2)

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

ll n, k;
ll ki, ai, bi, ci, di;
ll aa, bb, cc, dd;

typedef struct xxxx {
	ll a, b, c, d;
} xxxx;

vector<xxxx> a[55];

// bool v[55][105];

ll ans;

ll sum(ll aa, ll bb, ll cc, ll dd) {
	return 1ll * (100 + aa) * (100 + bb) * (100 + cc) * (100 + dd);
}

void dfs(ll now, ll aa, ll bb, ll cc, ll dd) {
	if(now > k) {
		ans = max(ans, sum(aa, bb, cc, dd));
		return;
	}
	int len = a[now].size();
	if(len == 0) {
		dfs(now + 1, aa, bb, cc, dd);
		return;
	}
	// len >>= 1;
	// if(len > 4)
	// 	len /= 2;
	len = min(len, 2);
	for(int i = 0; i < len; i++) {
		// if(!v[now][i]) {
		// v[now][i] = false;
		// aa += a[now][i].a;
		// bb += a[now][i].b;
		// cc += a[now][i].c;
		// dd += a[now][i].d;
		dfs(now + 1, aa + a[now][i].a, bb + a[now][i].b, cc + a[now][i].c, dd + a[now][i].d);
		// v[now][i] = true;
		// aa -= a[now][i].a;
		// bb -= a[now][i].b;
		// cc -= a[now][i].c;
		// dd -= a[now][i].d;
		// }
	}
}

bool cmp(const xxxx &x, const xxxx &y) {
	// return sum(x.a, x.b, x.c, x.d) > sum(y.a, y.b, y.c, y.d);
	return (x.a + x.b + x.c + x.d) > (y.a + y.b + y.c + y.d);
}

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	ll t = 1;
	// cin >> t;
	scanf("%d", &t);
	while(t--) {
		// cin >> n >> k;
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= k; i++)
			a[i].clear();
		ans = 0;
		aa = bb = cc = dd = 0;
		for(int i = 1; i <= n; i++) {
			// cin >> ki >> ai >> bi >> ci >> di;
			scanf("%d%d%d%d%d", &ki, &ai, &bi, &ci, &di);
			a[ki].push_back(xxxx{ai, bi, ci, di});
		}
		for(int i = 1; i <= k; i++)
			sort(a[i].begin(), a[i].end(), cmp);
		// sort(a + 1, a + n + 1, cmp);
		dfs(1, 0, 0, 0, 0);
		// cout << ans << '\n';
		printf("%lld\n", ans);
	}

	return 0;
}