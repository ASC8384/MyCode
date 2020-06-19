#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x;
ll di[55];
ll dp[55][3];

ll solve(ll len) {
	bool flag = false;
	ll	 ans  = 0;
	for(int i = len; i >= 1; i--) {
		ans += di[i] * dp[i - 1][2];
		if(flag) {
			ans += di[i] * dp[i - 1][0];
		} else if(di[i] > 4) {
			ans += dp[i - 1][1];
		}
		if(!flag && di[i + 1] == 4 && di[i] == 9) {
			flag = true;
		}
	}
	return ans;
}

ll cal(ll x) {
	ll cnt = 0;
	while(x) {
		di[++cnt] = x % 10;
		x /= 10;
	}
	di[cnt + 1] = 0;
	return cnt;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	dp[0][0] = 1;
	for(int i = 1; i <= 21; i++) {
		dp[i][0] = dp[i - 1][0] * 10 - dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
		dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][1];
	}

	ll t;
	cin >> t;
	while(t--) {
		cin >> x;
		ll len = cal(x + 1);
		cout << solve(len) << endl;
	}

	return 0;
}