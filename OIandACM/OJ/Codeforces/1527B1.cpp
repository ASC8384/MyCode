/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-05-20 22:46:39
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
		ll n;
		cin >> n;
		string s;
		cin >> s;
		int len = s.length();
		int flg = 0;
		int cnt = 0;
		for(int i = 0; i < len; i++)
			cnt += (s[i] == '0');
		if(cnt == 0)
			cout << "DRAW\n";
		else if(n % 2 == 1 && s[n / 2] == '0') {
			if(cnt == 1)
				cout << "BOB\n";
			else if(cnt == 2)
				cout << "DRAW\n";
			else
				cout << "ALICE\n";
		} else {
			cout << "BOB\n";
		}
	}

	return 0;
}