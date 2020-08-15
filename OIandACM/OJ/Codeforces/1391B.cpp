#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 19260817;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		string s[105];
		for(int i = 1; i <= n; i++)
			cin >> s[i];
		ll ans = 0;
		for(int i = 1; i <= n; i++) {
			if(s[i][m - 1] == 'R')
				ans++;
		}
		for(int i = 0; i < m; i++)
			if(s[n][i] == 'D')
				ans++;
		cout << ans << '\n';
	}
	return 0;
}
