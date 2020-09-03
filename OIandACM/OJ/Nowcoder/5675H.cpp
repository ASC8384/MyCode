/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-10 13:00:00
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e3 + 9;
const ll  mod  = 1e9 + 7;

bool a[size][size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n & 1) {
			for(int i = 1; i <= n; i++) {
				if(i & 1) {
					for(int j = 1; j <= n; j++) {
						cout << j & 1;
					}
					cout << '\n';
				} else {
					for(int j = 1; j <= n; j++) {
						cout << 0;
					}
					cout << '\n';
				}
			}
		} else {
			memset(a, 0, sizeof(a));
			for(int j = 1; j < n; j++)
				a[j][j] = 1;
			for(int j = 1; j <= n; j++) {
				;
			}
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++)
					cout << a[i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}