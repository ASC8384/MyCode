/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-02-05 22:46:58
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
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int ans = -1;
		for(int i = 1; i <= k; i++) {
			int j;
			for(j = 1; j < n; j++) {
				if(a[j] < a[j + 1]) {
					a[j]++;
					ans = j;
					break;
				}
			}
			if(j == n)
				ans = -1;
			if(i > 10009)
				break;
		}
		cout << ans << '\n';
	}

	return 0;
}