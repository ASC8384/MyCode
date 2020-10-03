/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-10-03 10:42:01
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int	   ans = 0;
string s;

void solve(int pos) {
	int	   cnt = 2;
	string ss  = s.substr(0, pos - 1);
	ss += s.substr(pos + 1);

	int len = ss.size();
	int now = 1;
	for(int i = 1; i < len; i++) {
		if(ss[i] == ss[i - 1]) {
			now++;
		} else {
			if(now >= 3) {
				ss	= ss.substr(0, i - now) + ss.substr(i);
				i	= 0;
				len = ss.size();
				cnt += now;
			}
			now = 1;
		}
	}
	if(now >= 3)
		cnt += now;

	ans = max(ans, cnt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n, c;
		cin >> n >> c;
		char cc = c - 1 + '0';
		ans		= 0;
		s		= "";
		for(int i = 0; i < n; ++i) {
			int tmp;
			cin >> tmp;
			s += tmp - 1 + '0';
		}
		int len = s.size();
		for(int i = 1; i < len; i++) {
			if(s[i] == s[i - 1] && s[i] == cc)
				solve(i);
		}
		cout << ans << '\n';
	}

	return 0;
}