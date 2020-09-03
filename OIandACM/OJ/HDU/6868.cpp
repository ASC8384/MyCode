/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-18 16:18:18
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

ll n, m;

const int	N = 1e7 + 5;
vector<int> prime_factor[N];

void init() {
	for(int i = 2; i < N; i++) {
		if(prime_factor[i].size() == 0) {
			for(int j = i; j < N; j += i) {
				prime_factor[j].push_back(i);
			}
		}
	}
}

int kk(ll x) {
	int ret = 0;
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0) {
			ret++;
			while(x % i == 0)
				x /= i;
		}
	if(x > 1)
		ret++;
	return ret;
}

ll qpow(ll x, int y) {
	ll res = 1;
	while(y > 0) {
		if(y & 1)
			res = res * x;
		x = x * x;
		y >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	init();
	cin >> t;
	while(t--) {
		cin >> n >> m;
		ll ans = 0;
		for(int jj = 2; jj <= m; jj++) {
			set<int> s;
			for(int i = 0; i < prime_factor[n].size(); i++)
				s.insert(prime_factor[n][i]);
			for(int i = 0; i < prime_factor[jj].size(); i++)
				s.insert(prime_factor[jj][i]);
			int ans = s.size();
			ans += qpow(2, ans);
		}
		cout << ans << '\n';
	}

	return 0;
}