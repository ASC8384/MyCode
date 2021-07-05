#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		ll n, m, k;
		cin >> n >> m >> k;
		ll	c = n;
		ll	r = m;
		int a[233], b[233];
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		while(k--) {
			int x, y;
			cin >> x >> y;
			if(++a[x] == 1) {
				c--;
			}
			if(++b[y] == 1) {
				r--;
			}
		}
		cout << c * m + r * n - c * r << '\n';
	}

	return 0;
}