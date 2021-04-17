/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-04-17 13:06:07
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 1e6 + 9;
const ll  mod  = 1e9 + 7;

int n;

int			a[size];
vector<int> v;
bool		flg;
int			now;

int an(void) {
	if(flg)
		return v[0];
	else {
		if(now == 1)
			return v[1];
		else
			return v[0];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	int aa;
	while(t--) {
		cin >> n;
		ll ans = 0;
		v.clear();
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++) {
			cin >> aa;
			if(a[aa] == 0) {
				v.push_back(aa);
			}
			a[aa]++;
		}
		sort(v.begin(), v.end());
		int cnt = 0;
		int m	= v.size();
		now		= 0;
		flg		= false;
		for(int i = 0; i < m; i++) {
			if(a[v[i]] > 1) {
				if(now)
					flg = true;
				now = i + 1;
			}
		}
		for(auto i : v) {
			ans += i;
			cnt += a[i] - 1;
		}
		if(cnt & 1) {
			ans -= an();
		}
		cout << ans << '\n';
	}

	return 0;
}