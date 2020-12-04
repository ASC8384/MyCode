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
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		s = " " + s;
		while(q--) {
			int x, y;
			cin >> x >> y;
			bool flg = false;
			for(ll i = 1; i < x; i++)
				if(s[i] == s[x])
					flg = true;
			for(ll i = y + 1; i <= n; i++)
				if(s[i] == s[y])
					flg = true;
			if(flg)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}