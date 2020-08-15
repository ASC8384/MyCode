/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-12 22:38:45
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
		int r, g, b, w;
		cin >> r >> g >> b >> w;
		int cnt = (r & 1) + (g & 1) + (b & 1);
		if(cnt == 3 || cnt == 0)
			cout << "Yes" << '\n';
		else if(cnt == 1) {
			if((w & 1) == 0)
				cout << "Yes" << '\n';
			else
				cout << "No" << '\n';
		} else if(cnt == 2)
			if((w & 1) && (r != 0 && g != 0 && b != 0))
				cout << "Yes" << '\n';
			else
				cout << "No" << '\n';
	}

	return 0;
}