/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-06 12:08:18
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
		ll b, x;
		cin >> b >> x;
		// if(b - 1 >= x)
		if(b % x == 1 && b > x)
			cout << 'T' << '\n';
		else
			cout << 'F' << '\n';
	}

	return 0;
}