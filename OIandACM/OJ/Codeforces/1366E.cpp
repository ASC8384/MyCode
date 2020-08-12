#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;

const ull size = 3e5 + 9;

ull a[size], b[size];
ull mod = 998244353;
ull ans = 1;

map<ull, int> c;

int main() {
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	if(a[1] < b[1]) {
		// cout << 0 << endl;
		ans = 0;
	} else {
		c[a[n]]++;
		for(int i = n - 1; i; i--) {
			a[i] = min(a[i], a[i + 1]);
			c[a[i]]++;
		}
		if(b[1] != a[1])
			ans = 0;
		else
			for(int i = 2; i <= m; i++)
				ans = (ans * c[b[i]]) % mod;
	}

	cout << ans << endl;
	return 0;
}