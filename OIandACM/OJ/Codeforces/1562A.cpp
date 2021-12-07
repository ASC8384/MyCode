/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-08-26 22:40:44
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
		ll le, ri;
		cin >> le >> ri;
		if(ri - le >= le)
			cout << (ll)(ri / 2 - (ri % 2 == 0)) << '\n';
		else
			cout << ri - le << '\n';
	}

	return 0;
}