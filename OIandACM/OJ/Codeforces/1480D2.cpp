#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

// int a[size];
// int b[size];
// // unordered_map<int> b;
// int c[size];
vector<int> a, b, c;

void init(int n) {
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = n; i; i--) {
		c[i]	= b[a[i]];
		b[a[i]] = i;
	}
}

int ans(int n) {
	int ret = 0;
	int x, y;
	x = y = 0;
	c[0]  = 0x7fffffff;
	for(int i = 1; i <= n; i++) {
		if(a[i] == a[x]) {
			x = i;
			continue;
		}
		if(a[i] == a[y]) {
			y = i;
			continue;
		}
		ret++;
		if(c[x] < c[y]) {
			int tmp = x;
			x		= y;
			y		= tmp;
		}
		x = i;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while(t--) {
		int n;
		cin >> n;
		a.resize(n + n);
		b.resize(n * 2, 0x7fffffff);
		c.resize(n << 1, 0);
		init(n);
		cout << ans(n) << '\n';
	}

	return 0;
}