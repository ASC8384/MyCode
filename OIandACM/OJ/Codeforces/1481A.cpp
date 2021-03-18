/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-02-05 22:36:23
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int px, py;
		cin >> px >> py;
		string s;
		cin >> s;
		int	 ll = s.size();
		bool is = false;
		int	 u, d, r, l;
		u = d = r = l = 0;
		for(int i = 0; i < ll; i++) {
			if(s[i] == 'U') {
				u++;
			}
			if(s[i] == 'D') {
				d--;
			}
			if(s[i] == 'R') {
				r++;
			}
			if(s[i] == 'L') {
				l--;
			}
		}
		if(px >= l && px <= r && py >= d && py <= u) {
			is = true;
		} else {
			is = false;
		}
		if(is) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}