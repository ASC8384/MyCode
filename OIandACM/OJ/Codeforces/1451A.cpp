/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-11-21 22:39:04
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
		ll n;
		cin >> n;
		if(n <= 3) {
			cout << n - 1 << '\n';
			continue;
		}
		if(n & 1) {
			cout << 3 << '\n';
		} else {
			cout << 2 << '\n';
		}
	}

	return 0;
}