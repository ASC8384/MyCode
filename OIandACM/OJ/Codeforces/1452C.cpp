/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-11-19 22:51:20
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
		cin >> s;
		int len = s.size();
		int ans = 0;
		int tmm = 0;
		int tpp = 0;
		for(int i = 0; i < len; i++) {
			if(s[i] == '(') {
				tmm++;
			} else if(s[i] == ')') {
				if(tmm) {
					tmm--;
					ans++;
				}
			} else if(s[i] == '[') {
				tpp++;
			} else if(s[i] == ']') {
				if(tpp) {
					tpp--;
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}