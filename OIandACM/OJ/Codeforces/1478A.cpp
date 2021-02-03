/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-01-28 22:38:22
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int a[size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			a[tmp]++;
		}
		int ans = 0;
		for(int i = 200; i; i--) {
			ans = max(ans, a[i]);
		}
		cout << ans << '\n';
	}

	return 0;
}