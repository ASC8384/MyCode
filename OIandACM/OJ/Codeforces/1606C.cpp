#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 25 + 9;
const ll  mod  = 1e9 + 7;

ll a[size], b[size];

ll calc(int x) {
	return (b[a[x + 1]] - b[a[x]]) / b[a[x]];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	b[0] = 1;
	for(int i = 1; i <= 12; i++) {
		b[i] = b[i - 1] * 10;
	}

	int t = 1;
	cin >> t;
	while(t--) {
		ll n, k;
		ll ans = 0;
		cin >> n >> k;
        k++;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for(int i = 2; i <= n; i++) {
            int tm = i - 1;
			ans += min(k, calc(tm)) * b[a[tm]];
			k -= min(k, calc(tm));
		}
		cout << ans + k * b[a[n]] << '\n';
	}
	return 0;
}
