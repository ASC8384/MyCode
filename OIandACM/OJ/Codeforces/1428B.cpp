/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-10-17 21:59:56
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cin >> s;
		bool isz = true;
		bool isy = true;
		int	 len = s.size();
		int	 cnt = 0;
		int	 ans = 0;
		for(int i = 0; i < n; i++) {
			if(s[i] == '<') {
				isz = false;
				if(cnt)
					ans += cnt + 1;
				cnt = 0;
			} else if(s[i] == '>') {
				isy = false;
				if(cnt)
					ans += cnt + 1;
				cnt = 0;
			} else
				cnt++;
		}
		if(s[0] == s[n - 1] && s[0] == '-')
			ans--;
		if(cnt)
			ans += cnt + 1;
		if(isz || isy || cnt == n)
			cout << n << '\n';
		else
			cout << ans << '\n';
	}

	return 0;
}