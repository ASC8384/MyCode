/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-06-26 17:11:59
*/
#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) x &(-x)
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, k;
	cin >> n >> k;
	bitset<65> a(n);
	ll		   ans = 0;
	while(k < a.count()) {
		ans += lowbit(n);
		n += lowbit(n);
		a = n;
	}
	cout << ans << endl;

	return 0;
}