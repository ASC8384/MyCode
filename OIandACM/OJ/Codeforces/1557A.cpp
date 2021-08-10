/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-08-09 22:36:37
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int a[size];

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	int t = 1;
	// cin >> t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
        ll sum = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
            sum += a[i];
		}
		sort(a + 1, a + n + 1);
        printf("%lf\n", a[n] * 1.0 + (sum - a[n]) / (n - 1.0));
	}

	return 0;
}