/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-01-19 22:30:20
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int	   ans[size], b[size];
int	   n;
string s;

void solve() {
	cin >> n >> s;
	b[0]   = s[0] - '0';
	ans[0] = 1;
	for(int i = 1; i < n; i++) {
		b[i] = s[i] - '0';
		if(i == 0) {
			ans[i] = 1;
		} else if(b[i] + 1 != b[i - 1] + ans[i - 1])
			ans[i] = 1;
		else
			ans[i] = 0;
	}
	for(int i = 0; i < n; i++)
		cout << ans[i];
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}