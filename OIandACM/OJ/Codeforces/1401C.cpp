/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-23 20:52:50
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int a[size];
int b[size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i], b[i] = a[i];
		sort(a + 1, a + n + 1);
		int	 minn = a[1];
		bool ff	  = true;
		for(int i = 1; i <= n; i++) {
			if(a[i] != b[i] && b[i] % minn)
				ff = false;
		}
		if(ff)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}