/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-06-26 15:36:50
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
	while(t--) {
		int a0, a1, b0, b1;
		cin >> a0 >> a1 >> b0 >> b1;
		int ans = 0;
		for(int i = 1; i * i <= b1; i++) {
			if(b1 % i)
				continue;
			if(i % a1 == 0 && __gcd(i / a1, a0 / a1) == 1 && __gcd(b1 / i, b1 / b0) == 1)
				ans++;
			int x = b1 / i;
			if(x % a1 || x == i)
				continue;
			if(__gcd(x / a1, a0 / a1) == 1 && __gcd(b1 / x, b1 / b0) == 1)
				ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}