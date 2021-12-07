/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-08-15 23:02:10
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int a[size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if(a[1] == 1) {
			cout << n + 1;
			for(int i = 1; i <= n; i++)
				cout << " " << i;
		} else {
			int now = 0;
			for(int i = 1; i <= n; i++)
				if(a[i] != a[i + 1]) {
					now = i;
					break;
				}
			if(now == 0) {
				for(int i = 1; i <= n + 1; i++)
					cout << i << ' ';
			} else {
				for(int i = 1; i <= now; i++)
					cout << i << ' ';
				cout << n + 1;
				for(int i = now + 1; i <= n; i++)
					cout << " " << i;
			}
		}
		cout << '\n';
	}

	return 0;
}