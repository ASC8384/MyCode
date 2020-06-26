/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-06-26 13:55:46
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
	// t = 1;
	// cin >> t;
	while(t--) {
		int n;
		int a;
		cin >> n;
		int cntl = n;
		int cntr = 1;
		for(int i = 1; i <= n; i++) {
			cin >> a;
			if(a == 0) {
				cntl = min(i, cntl);
				cntr = max(i, cntr);
			}
		}
		if((cntl - 1) & 1 || (n - cntr) & 1)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}