/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-22 23:31:50
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e3 + 9;
const ll  mod  = 1e9 + 7;

int a[size][size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		a[x1][y1]++;
		a[x2 + 1][y1]--;
		a[x1][y2 + 1]--;
		a[x2 + 1][y2 + 1]++;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j)
			cout << (a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]) << " ";
		cout << '\n';
	}
	return 0;
}