/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-18 12:00:30
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	if(s.size() < 6) {
		cout << "ugly" << endl;
	} else {
		if((s[0] == 'L' || s[0] == 'l') && (s[1] == 'O' || s[1] == 'o') && (s[2] == 'V' || s[2] == 'v') && (s[3] == 'E' || s[3] == 'e') && (s[4] == 'L' || s[4] == 'l') && (s[5] == 'Y' || s[5] == 'y'))
			cout << "lovely" << endl;
		else
			cout << "ugly" << endl;
	}

	return 0;
}