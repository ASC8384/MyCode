/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-06-28 20:29:53
*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const int size = 2e3 + 9;
const ll  mod  = 1e9 + 7;

ll k;
ll f[size][size], c[size][size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	cin >> k;

	c[0][0] = 1;
	c[1][0] = c[1][1] = 1;
	for(int i = 2; i <= 2008; i++) {
		c[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % k;
			f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
			if(c[i][j] == 0)
				f[i][j]++;
		}
		f[i][i + 1] = f[i][i];
	}

	while(t--) {
		int n, m;
		cin >> n >> m;
		cout << f[n][min(n, m)] << '\n';
	}

	return 0;
}