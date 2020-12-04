/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-11-13 22:45:07
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

unordered_map<int, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		m.clear();
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			m[tmp]++;
		}
		bool is = false;
		for(auto &i : m) {
			if(i.second > 1) {
				is = true;
				break;
			}
		}
		if(is)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}