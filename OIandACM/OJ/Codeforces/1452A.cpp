/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-11-19 22:36:45
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
		int x, y;
		cin >> x >> y;
		if(x < y)
			swap(x, y);
		if(x - y - 1 >= 0)
			cout << x + y + x - y - 1 << '\n';
		else
			cout << x + y << '\n';
	}

	return 0;
}