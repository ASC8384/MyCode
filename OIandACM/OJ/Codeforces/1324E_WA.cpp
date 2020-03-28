#include <bits/stdc++.h>
using namespace std;

int a[2333];
int dp[2333][2333];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, h, ll, rr;
	cin >> n >> h >> ll >> rr;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 1; i <= n; i++)
		for(int j = 0; j < h; j++)
			dp[i][j] = max(dp[i - 1][(j + a[i] + h) % h], dp[i - 1][(j + a[i] - 1 + h) % h]) +
					   (ll <= j && j <= rr);

	int ans = 0;
	for(int i = ll; i <= rr; i++)
		ans = max(ans, dp[n][i]);
	cout << ans << endl;

	return 0;
}