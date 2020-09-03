#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int a[size];
char s[size];
// string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int x;
		cin >> s;
		cin >> x;
		// int n = s.size();
		int n = strlen(s);
		memset(a, 0, sizeof(a));
		bool ff = true;
		for(int i = 0; i < x; i++) {
			if(s[i] == '0') {
				a[i + x] = 1;
			}
		}
		for(int i = x; i <= n - x; i++) {
			if(s[i] == '0') {
				a[i - x] = a[i + x] = 1;
			}
		}
		for(int i = n - x + 1; i < n; i++) {
			if(s[i] == '0') {
				a[i - x] = 1;
			}
		} //
		for(int i = 0; i < x; i++) {
			if(s[i] == '1') {
				if(a[i + x] == 1) {
					ff = false;
					break;
				} else
					a[i + x] = 2;
			}
		}
		for(int i = x; ff && i <= n - x; i++) {
			if(s[i] == '1') {
				if(a[i - x] == 1 && a[i + x] == 1) {
					ff = false;
					break;
				} else {
					if(a[i - x] != 1)
						a[i - x] = 2;
					if(a[i + x] != 1)
						a[i + x] == 2;
				}
			}
		}
		for(int i = n - x + 1; ff && i < n; i++) {
			if(s[i] == '1') {
				if(a[i - x] == 1) {
					ff = false;
					break;
				} else
					a[i - x] = 2;
			}
		}
		if(ff)
			for(int i = 0; i < n; i++) {
				if(a[i])
					cout << (a[i] - 1);
				else
					cout << 0;
			}
		else
			cout << -1;
		cout << '\n';
	}

	return 0;
}