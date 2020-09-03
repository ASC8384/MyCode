#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

ll p, f, cnts, cntw, s, w;
ll ans;

void dfs(int i) {
	ll cnt1 = i;
	ll cnt2 = min(cntw, (p - s * i) / w);
	ll tmps = cnts - cnt1;
	ll tmpw = cntw - cnt2;

	ll cnt3 = min(tmps, f / s);
	ll cnt4 = min(tmpw, (f - cnt3 * s) / w);
	ll cnt5 = min(tmpw, f / w);
	ll cnt6 = min(tmps, (f - cnt5 * w) / s);

	ans = max(cnt1 + cnt2 + cnt3 + cnt4, ans);
	ans = max(cnt1 + cnt2 + cnt5 + cnt6, ans);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		cin >> p >> f;
		cin >> cnts >> cntw;
		cin >> s >> w;
		if(s > w) {
			swap(s, w);
			swap(cnts, cntw);
		}
		ans = 0;

		for(int i = 0; i <= cnts && s * i <= p; i++) {
			dfs(i);
		}

		cout << ans << '\n';
	}

	return 0;
}