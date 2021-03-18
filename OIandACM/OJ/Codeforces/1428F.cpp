/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-10-17 22:22:20
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

	int n;
	cin >> n;
	cin >> s;
	a[0] = s[0] - '0';
	for(int i = 1; i < n; i++) {
		a[i] = a[i - 1] + s[i] - '0';
	}
	ll ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			;
		}

	return 0;
}