/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-10-02 22:34:55
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
		string s;
		cin >> s;
		s = "9" + s;
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			swap(s[tmp + 1], s[tmp]);
			int len = s.size();
			if(len == 1) {
				cout << "Over\n";
				continue;
			}
			if(s[tmp + 1] == s[tmp]) {
				int i;
				for(i = tmp; i > 0; i--)
					if(s[tmp] != s[i - 1])
						break;
				int le = i;
				for(i = tmp + 1; i < len - 1; i++)
					if(s[tmp] != s[i + 1])
						break;
				int ri = i;
				if(ri - le >= 2)
					s = s.substr(0, le) + s.substr(ri + 1);
				//s = s.substr(1);
			} else {
				int i;
				for(i = tmp; i > 0; i--)
					if(s[tmp] != s[i - 1])
						break;
				string ss;
				if(tmp - i >= 2)
					ss = s.substr(0, i);
				else
					ss = s.substr(0, tmp + 1);
				for(i = tmp + 1; i < len - 1; i++)
					if(s[tmp + 1] != s[i + 1])
						break;
				if(i - tmp - 1 >= 2)
					s = ss + s.substr(i + 1);
				else
					s = ss + s.substr(tmp + 1);
			}
			/*for(int i = 1, now = 1; i < len; i++) {
				if(s[i] == s[i - 1]) {
					now++;
				} else {
					if(now >= 3) {
						s	= s.substr(0, i - now) + s.substr(i);
						i	= 0;
						len = s.size();
					}
					now = 1;
				}
			}*/
			len = s.size();
			if(len == 1) {
				cout << "Over\n";
				//continue;
			} else {
				cout << s.substr(1) << '\n';
			}
		}
		cout << '\n';
	}

	return 0;
}