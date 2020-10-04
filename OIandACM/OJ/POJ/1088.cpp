/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-10-04 08:58:42
*/
// #include <bits/stdc++.h>
#include <algorithm>
#include <cstring>
#include <iostream>
typedef long long ll;
using namespace std;
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e2 + 9;
const ll  mod  = 1e9 + 7;

int r, c;

int xx[] = {0, 0, 1, -1};
int yy[] = {1, -1, 0, 0};

int a[size][size];
int f[size][size];

int dfs(int x, int y) {
	if(f[x][y] > 0)
		return f[x][y];
	int ret = 1;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if((x + xx[i] > 0) && (x + xx[i] <= r) && (y + yy[i] > 0) && (y + yy[i] <= c) && (a[x + xx[i]][y + yy[i]] < a[x][y]))
				ret = max(ret, dfs(x + xx[i], y + yy[i]) + 1);
		}
	}
	f[x][y] = ret;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while(cin >> r && cin >> c) {
		memset(a, 0, sizeof(a));
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c; j++)
				cin >> a[i][j];
		int ans = 1;
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c; j++)
				ans = max(ans, dfs(i, j));
		cout << ans << '\n';
	}

	return 0;
}