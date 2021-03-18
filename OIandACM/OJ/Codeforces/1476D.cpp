/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-01-30 00:00:43
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 3e5 + 9;
const ll  mod  = 1e9 + 7;

string s;
int	   n;

int a[size];

ll f[size][5][5];

void dfs(int a, int b, bool c) {
	if(!c && f[a][b][0] == -1) {
		if(a > 0 && (b + (s[a - 1] == 'L')) == 1) {
			dfs(a - 1, (b + 1) & 1, 0);
			f[a][b][0] = f[a - 1][(b + 1) & 1][0] + 1;
		} else
			f[a][b][0] = 1;
	} else if(c && f[a][b][1] == -1) {
		if(a < n && b + (s[a] == 'R') == 1) {
			dfs(a + 1, (b + 1) & 1, 1);
			f[a][b][1] = f[a + 1][(b + 1) & 1][1] + 1;
		} else
			f[a][b][1] = 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		// ll n;
		cin >> n >> s;
		memset(f, -1, sizeof(f));
		for(int i = 0; i <= n; i++) {
			dfs(i, 0, true);
			dfs(i, 0, false);
		}
		cout << f[0][0][1] + f[0][0][0] - 1;
		for(int i = 0; i <= n; i++)
			cout << ' ' << f[i][0][1] + f[i][0][0] - 1;
		cout << '\n';
	}

	return 0;
}