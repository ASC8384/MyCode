/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-11-12 22:52:27
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

string s;

bool is2() {
	if(s.find("aa") != string::npos)
		return true;
	return false;
}

bool is3() {
	if(s.find("aba") != string::npos)
		return true;
	else if(s.find("aca") != string::npos)
		return true;
	return false;
}

bool is4() {
	if(s.find("abca") != string::npos)
		return true;
	else if(s.find("acba") != string::npos)
		return true;
	return false;
}

bool is7() {
	if(s.find("abbacca") != string::npos)
		return true;
	else if(s.find("accabba") != string::npos)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n >> s;
		ll ans = -1;
		if(is2()) {
			ans = 2;
		} else if(is3()) {
			ans = 3;
		} else if(is4()) {
			ans = 4;
		} else if(is7()) {
			ans = 7;
		}
		cout << ans << '\n';
	}

	return 0;
}