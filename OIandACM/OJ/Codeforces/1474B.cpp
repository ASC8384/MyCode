/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-01-19 22:34:05
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

bool is(ll x) {
	if(x <= 1)
		return false;
	for(ll i = 2; i * i <= x; i++) {
		if(x % i == 0)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		ll d;
		cin >> d;
		ll ans = 0;
		for(ll i = 1 + d;; i++) {
			if(is(i)) {
				ans = i;
				break;
			}
		}
		for(ll i = ans + d;; i++) {
			if(is(i)) {
				ans *= i;
				break;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}