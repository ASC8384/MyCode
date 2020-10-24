/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-10-03 23:26:23
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e3 + 9;
const ll  mod  = 1e9 + 7;

int a[size];
int dp[size][size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	while(cin >> n >> k) {
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		a[n + 1] = 0;
		for(int i = 1; i <= n; i++)
			a[i] = (a[i] - a[i + 1]) * (a[i] - a[i + 1]);
		memset(dp, 0x3f, sizeof(dp));
		for(int i = 0; i <= n; i++)
			dp[i][0] = 0;
		// dp[1][1] = a[1];
		for(int i = 2; i <= n; i++) {
			for(int j = 1; j <= k; j++) {
				// for(int j = 1; j <= (i >> 1); j++) {
				dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + a[i - 1]);
			}
		}
		cout << dp[n][k] << '\n';
	}

	return 0;
}