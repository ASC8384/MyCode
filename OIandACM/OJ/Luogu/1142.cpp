/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-11-18 21:52:13
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e3 + 9;
const ll  mod  = 1e9 + 7;

struct LL {
	int x, y;
} node[size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> node[i].x >> node[i].y;
	}
	int ans = 0;
	if(n == 1)
		cout << 1;
	else {
		for(int i = 1; i < n; i++) {
			for(int j = i + 1; j <= n; j++) {
				int now = 2;
				for(int k = 1; k <= n; k++) {
					if(k == i || k == j)
						continue;
					if((node[k].x - node[i].x) * (node[i].y - node[j].y) == (node[k].y - node[i].y) * (node[i].x - node[j].x))
						now++;
				}
				ans = max(ans, now);
			}
		}
		cout << ans;
	}

	return 0;
}