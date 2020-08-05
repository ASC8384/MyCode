/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-05 13:54:48
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

ll a[size], n, nn;
ll sum[size << 2];
ll lazy[size << 2];

void build(int n) {
	nn = 1;
	while(nn < n + 2)
		nn <<= 1;
	for(int i = 1; i <= n; i++)
		sum[nn + i] = a[i];
	for(int i = nn - 1; i > 0; i--) {
		sum[i]	= sum[i << 1] + sum[i << 1 | 1];
		lazy[i] = 0;
	}
}

void update(int L, int R, int C) {
	int s, t, Ln = 0, Rn = 0, x = 1;
	for(s = nn + L - 1, t = nn + R + 1; s ^ t ^ 1; s >>= 1, t >>= 1, x <<= 1) {
		sum[s] += C * Ln;
		sum[t] += C * Rn;
		if(~s & 1)
			lazy[s ^ 1] += C, sum[s ^ 1] += C * x, Ln += x;
		if(t & 1)
			lazy[t ^ 1] += C, sum[t ^ 1] += C * x, Rn += x;
	}
	for(; s; s >>= 1, t >>= 1) {
		sum[s] += C * Ln;
		sum[t] += C * Rn;
	}
}

ll query(int L, int R) {
	int s, t, Ln = 0, Rn = 0, x = 1;
	ll	ret = 0;
	for(s = nn + L - 1, t = nn + R + 1; s ^ t ^ 1; s >>= 1, t >>= 1, x <<= 1) {
		if(lazy[s])
			ret += lazy[s] * Ln;
		if(lazy[t])
			ret += lazy[t] * Rn;
		if(~s & 1)
			ret += sum[s ^ 1], Ln += x;
		if(t & 1)
			ret += sum[t ^ 1], Rn += x;
	}
	for(; s; s >>= 1, t >>= 1) {
		ret += lazy[s] * Ln;
		ret += lazy[t] * Rn;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> n >> t;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(n);
	for(int i = 1; i <= t; i++) {
		int num;
		cin >> num;
		if(num == 1) {
			int x, y, k;
			cin >> x >> y >> k;
			update(x, y, k);
		} else {
			int x, y;
			cin >> x >> y;
			cout << query(x, y) << '\n';
		}
	}

	return 0;
}