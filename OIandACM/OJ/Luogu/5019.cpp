/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-31 16:58:44
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	int a1, a2;
	cin >> a1;
	ll ans = a1;
	for(int i = 2; i <= t; i++) {
		cin >> a2;
		if(a2 > a1)
			ans += a2 - a1;
		a1 = a2;
	}
	cout << ans << endl;

	return 0;
}