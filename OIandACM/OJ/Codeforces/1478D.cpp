/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-01-28 23:26:30
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

ll a[size];
// __int128 a[size];

// const __int128 li = 1;

// unordered_map<__int128, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		ll	k;
		cin >> n >> k;
		// m.clear();
		for(int i = 1; i <= n; i++) {
			ll tmp;
			cin >> tmp;
			a[i] = tmp;
			// a[i] = tmp * li;
			// m[tmp * 2 * li]++;
		}
		sort(a + 1, a + n + 1);
		ll	 d	= 0;
		bool is = false;
		for(int i = 1; i < n; i++) {
			d = __gcd(d, a[i + 1] - a[i]);
		}
		if((k - a[1]) % d == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		// sort(a + 1, a + n + 1);
	}

	return 0;
}