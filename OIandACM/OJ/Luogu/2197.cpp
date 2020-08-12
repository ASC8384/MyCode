/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-02 12:42:06
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
		int n;
		cin >> n;
		int tmp;
		cin >> tmp;
		int ans = tmp;
		for(int i = 1; i < n; i++) {
			cin >> tmp;
			ans ^= tmp;
		}
		if(ans)
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}

	return 0;
}