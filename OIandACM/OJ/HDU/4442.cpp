/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-17 17:44:18
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 100000 + 9;
const ll  mod  = 365 * 24 * 60 * 60;

typedef struct {
	ll a, b;
} pd;

pd	a[size];
int n;

bool cmp(const pd a, const pd b) {
	return a.a * b.b < a.b * b.a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// int t = 1;
	// cin >> t;
	// while(t--) {
	while(cin >> n && n) {
		for(int i = 1; i <= n; i++)
			cin >>
				a[i].a >> a[i].b;
		sort(a + 1, a + n + 1, cmp);
		ll ans = a[1].a;
		for(int i = 2; i <= n; i++) {
			ans = (ans + a[i].a + (ans * a[i].b) % mod) % mod;
		}
		cout << ans << '\n';
	}

	return 0;
}