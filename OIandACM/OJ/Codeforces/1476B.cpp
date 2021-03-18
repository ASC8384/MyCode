/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-01-29 22:47:00
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

ll p[size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++) {
			cin >> p[i];
		}
		ll ans = 0;
		ll now = p[1];
		for(int i = 2; i <= n; i++) {
			// if(p[i] * 100 <= k * (now)) {
			if((double)((double)p[i] / (double)now) <= (double)((double)k / 100.0)) {
				now += p[i];
			} else {
				// ll x = (100 * p[i] - k * now - k * p[i]) / k;
				// ll x = (100 * p[i] - k * now) / k;
				// cout << x << endl;
				// if(x == 0)
				// x++;
				ll ri  = 1e18;
				ll le  = 0;
				ll mi  = 0;
				ll ret = 0;
				// for(int i = 1; i <= 80; i++) {
				while(le <= ri) {
					mi = (ri + le) / 2;
					// if(p[i] * 100 <= k * mi) {
					if(((double)((double)p[i] / (double)mi) <= (double)((double)k / 100.0))) {
						ret = mi;
						ri	= mi - 1;
					} else {
						le = mi + 1;
					}
				}
				ll x = ret - now;
				now	 = ret;
				now += p[i];
				ans += x;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}