/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-10-06 19:23:06
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

struct xx {
	int tim;
	int val;
} a[size];

bool v[size];

bool cmp(xx a, xx b) {
	if(a.tim == b.tim)
		return a.val > b.val;
	return a.tim < b.tim;
}

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
			cin >> a[i].tim;
		for(int i = 1; i <= n; i++)
			cin >> a[i].val;
		for(int i = 1; i <= n; i++)
			v[i] = true;
		sort(a + 1, a + n + 1, cmp);
		int ans = 0;
		int now = 1;
		for(int i = 1; i <= n; i++) {
			if(a[i].tim >= now) {
				now++;
				continue;
			}
			int tmp = a[i].val;
			int pos = i;
			for(int j = 1; j < i; j++)
				if(a[j].val < tmp && v[j]) {
					tmp = a[j].val;
					pos = j;
				}
			ans += tmp;
			v[pos] = false;
		}
		cout << ans << '\n';
	}

	return 0;
}