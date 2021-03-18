/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-01-26 21:00:35
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e6 + 9;
const ll  mod  = 1e9 + 7;

ll n;
ll a[size];
ll t[size];

unordered_map<string, ll> m;

inline ll lowbit(ll n) {
	return n & -n;
}

ll que(ll x) {
	ll ret = 0;
	while(x) {
		ret += t[x];
		x -= lowbit(x);
	}
	return ret;
}

void add(ll x) {
	while(x <= n) {
		t[x]++;
		x += lowbit(x);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		m[s] = i;
	}
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		a[i] = m[s];
	}
	ll ans = 0;
	for(int i = n; i; i--) {
		ans += que(a[i] - 1);
		add(a[i]);
	}
	cout << ans;

	return 0;
}