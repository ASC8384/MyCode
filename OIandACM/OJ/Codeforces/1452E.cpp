/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-11-20 00:25:05
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

struct LL {
	int x, y;
} a[size];

bool cmp(LL a, LL b) {
	return a.x < b.x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		cin >> a[i].x >> a[i].y;
	}
	sort(a + 1, a + n + 1, cmp);
	int tppn = n - k;
	int tmmn = tppn - k;
	int ans	 = 0;
	int now	 = 0;
	for(int i = 1; i <= tppn; i++) {
		for(int j = 1 + k; j <= tmmn; j++) {
			now = 0;
			for(int kk = 1; kk <= m; kk++) {
				if(a[kk].y <= i + k) {
					if(i < a[kk].x)
						now += ;
				} else if(a[kk].y <= j + k) {
					;
				} else {
					;
				}
			}
			ans = max(ans, now);
		}
	}
	cout << ans << '\n';

	return 0;
}