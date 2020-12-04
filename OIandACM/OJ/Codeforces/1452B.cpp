#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

ll a[size];

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	int t = 1;
	// cin >> t;
	scanf("%d", &t);
	while(t--) {
		int n;
		// cin >> n;
		scanf("%d", &n);

		ll cnt = 0;
		for(int i = 1; i <= n; i++) {
			// cin >> a[i];
			scanf("%lld", &a[i]);
			cnt += a[i];
		}
		if(n == 2) {
			printf("0\n");
			continue;
		}
		sort(a + 1, a + n + 1);
		ll ans = 0;
		cnt	   = n * a[n] - cnt;
		cnt	   = cnt - a[n] + a[1];
		n	   = n - 1;
		if(a[1] > cnt)
			cnt += ((a[1] - cnt) % n == 0) ? (a[1] - cnt) / n * n : (a[1] - cnt) / n * n + n;
		// while(a[1] > cnt)	cnt += n;
		//cout << cnt - a[1] << '\n';
		printf("%lld\n", cnt - a[1]);
	}

	return 0;
}