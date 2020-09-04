#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 1e5 + 9;
const int mod  = 1e9 + 7;

int	 dp[size][3];
bool ff[size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		memset(ff, 0, sizeof(ff));
		memset(dp, 0, sizeof(dp));
		string s1;
		cin >> s1;
		for(int i = 2; i <= n; i++) {
			string s2;
			cin >> s2;
			if(s1 == s2) {
				ff[i - 1] = true;
			} else {
				ff[i - 1] = false;
				s1		  = s2;
			}
		}
		dp[0][0] = 1;
		for(int i = 1; i <= n; i++) {
			dp[i][0] = dp[i - 1][0];
			if(i >= 3)
				dp[i][0] = (dp[i][0] + dp[i - 2][1]) % mod;
			if(ff[i]) {
				dp[i][1] = 0;
			} else
				dp[i][1] = dp[i][0];
		}
		cout << (dp[n][0] + dp[n - 1][1]) % mod << '\n';
	}

	return 0;
}