/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-01-28 22:47:35
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int a;
int d;
int f[23][23];

bool is(int x) {
	if(x >= 10 * d)
		return true;
	// x %= 10;
	for(int i = 1; i <= 10; i++)
		if(x % 10 == f[d][i] % 10) {
			if(x < f[d][i])
				return false;
			else
				return true;
		}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for(int i = 1; i <= 10; i++)
		for(int j = 1; j <= 10; j++)
			f[i][j] = f[i][j - 1] + i;

	int t = 1;
	cin >> t;
	while(t--) {
		int q;
		cin >> q >> d;
		for(int i = 1; i <= q; i++) {
			cin >> a;
			if(is(a))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}