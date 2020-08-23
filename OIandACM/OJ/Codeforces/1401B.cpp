/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-23 19:57:22
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int x1, x2, y1, y2, z1, z2;
		cin >> x1 >> y1 >> z1;
		cin >> x2 >> y2 >> z2;
		int tmp = min(x1, z2);
		x1 -= tmp;
		z2 -= tmp;
		tmp = min(z1, z2);
		z1 -= tmp;
		z2 -= tmp;
		cout << ((min(z1, y2) - min(y1, z2)) * 2) << '\n';
	}

	return 0;
}