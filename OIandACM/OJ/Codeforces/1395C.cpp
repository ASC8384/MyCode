/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-12 23:16:17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e3 + 9;
const ll  mod  = 1e9 + 7;

ll ha = 19260817;

// bool is[size][size];
int a[size];
int b[size];

// bitset<20> c[size][size];
int c[size][size];

unordered_map<ll, bool> mp;

bool flag;
int	 mid;
int	 n, m;

void dfs(ll sum, ll now) {
	if(mp[sum * ha + now])
		return;
	else
		mp[sum * ha + now] = true;
	if(now == n + 1)
		flag = true;
	if(flag)
		return;
	for(int i = 1; i <= m; i++)
		if((sum | c[now][i]) <= mid)
			dfs(sum | c[now][i], now + 1);
}

void init() {
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			c[i][j] = a[i] & b[j];
}

int le, ri;

void solve() {
	le = 0;
	ri = 1 << 10;
	while(le <= ri) {
		mp.clear();
		// mid	 = (le + ri) >> 1;
		mid	 = le;
		flag = false;
		dfs(0, 1);
		if(flag) {
			return;
		} else
			le++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int now = n;

	init();
	solve();

	cout << le << '\n';
	return 0;
}
