/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-20 12:50:21
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;
const ll  mod1 = 1e9 + 6;

int	 a[size];
bool f[size];
int	 ans[size];

int one(int n) {
	int ans = 0;
	while(n) {
		n &= (n - 1);
		++ans;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	// while(t--) {
	for(int n = 1; n <= 5; n++) {
		int tmp = 1;
		for(int i = 1; i <= n; i++)
			tmp <<= 1;
		for(int i = 0; i <= tmp; i++)
			ans[i] = 0;
		// int n;
		// cin >> n;
		for(int i = 1; i <= n; i++)
			a[i] = i;
		// for(int i = 1; i < n; i++)
		// 	cin >> f[i];
		// int ans = 0;
		do {
			bool ff	 = true;
			ll	 now = 0;
			for(int i = 1; i < n; i++)
				now = (now * 2 + (a[i] > a[i + 1])) % mod1;
			ans[now]++;
			// 	if(f[i] != (a[i] > a[i + 1])) {
			// 		ff = false;
			// 		break;
			// 	}
			// ans += ff;
			// if(now == 0)
			// 	for(int i = 1; i <= n; i++)
			// 		cout << a[i] << "\n";
		} while(next_permutation(a + 1, a + n + 1));
		for(int i = 0; i < tmp; i++)
			if(ans[i])
				cout << n << ":" << i << " " << ans[i] << "\twith " << one(i) << '\n';
	}

	return 0;
}