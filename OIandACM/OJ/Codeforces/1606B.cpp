/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-10-29 22:44:02
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
		ll n, k;
		cin >> n >> k;
		if(k == 1) {
			cout << n - 1 << '\n';
			continue;
		}
		ll m   = 0;
		ll tmp = 1;
		while(tmp < k) {
			tmp <<= 1;
			m++;
		}
		// tmp /= 2;
		n -= tmp;
		if(n > 0) {
			m += n / k + ((n % k) > 0);
		}
		cout << m << '\n';
	}

	return 0;
}