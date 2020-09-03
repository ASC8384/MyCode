#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

ll a[size];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		// sort(a + 1, a + n + 1, cmp);
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			s += a[i];
			if(s % i)
				now = s / i + 1;
			else
				now = s / i;

			ans = max(ans, now);
		}
		cout << ans << '\n';
	}

	return 0;
}