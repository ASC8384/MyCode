/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-17 15:55:28
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e3 + 9;
const ll  mod  = 1e9 + 7;

int t;

int a[size], b[size];

void solve(int *a, int *b, int n, bool flag) {
	for(int i = 0; i < n; i++) {
		if(a[0] == b[i]) {
			solve(a + 1, b, i, false);
			solve(a + i + 1, b + i + 1, n - i - 1, false);
			if(flag)
				cout << a[0] << '\n';
			else
				cout << a[0] << ' ';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while(cin >> t) {
		for(int i = 0; i < t; i++)
			cin >> a[i];
		for(int i = 0; i < t; i++)
			cin >> b[i];
		solve(a, b, t, true);
	}

	return 0;
}