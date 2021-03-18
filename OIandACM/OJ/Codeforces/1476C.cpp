#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int n;
int a[size], b[size], c[size];
ll	ans;

ll f[size];

void solve() {
	ans	 = 0;
	f[0] = 0;
	f[1] = 2;
	f[1] += abs(a[2] - b[2]);
	if(f[1] + c[2] - 1 > ans)
		ans = f[1] + c[2] - 1;
	for(int i = 2; i < n; i++) {
		if(a[i + 1] == b[i + 1]) {
			f[i] = 2;
		} else {
			ll x = min(a[i + 1], b[i + 1]);
			ll y = max(a[i + 1], b[i + 1]);
			f[i] = max(f[i - 1] + x - 1 + c[i] - y + 2, y - x + 2);
		}
		ans = max(ans, f[i] + c[i + 1] - 1);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> c[i];
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
			cin >> b[i];
		solve();
		cout << ans << '\n';
	}

	return 0;
}