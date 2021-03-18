/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-02-07 22:36:36
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
		int len = s.size();
		for(int i = 0; i < len; i++) {
			if((i + 1) & 1) {
				if(s[i] == 'a')
					s[i] = 'b';
				else
					s[i] = 'a';
			} else {
				if(s[i] == 'z')
					s[i] = 'y';
				else
					s[i] = 'z';
			}
		}
		cout << s << '\n';
	}

	return 0;
}