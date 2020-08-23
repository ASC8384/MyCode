/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-21 22:37:01
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
		int n, k;
		cin >> n >> k;
		if(n <= k) {
			cout << k - n << '\n';
		} else if((n - k) % 2 == 0) {
			cout << "0\n";
		} else {
			cout << "1\n";
		}
	}

	return 0;
}