/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-31 17:29:37
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5;
const ll  mod  = 1e9 + 7;

int	 a[size];
bool is[size];
bool no[size];
// int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		memset(is, 0, sizeof(is));
		memset(no, 0, sizeof(no));
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			is[a[i]] = true;
		}
		sort(a + 1, a + n + 1);
		int minn = a[1];
		int maxx = a[n];
		int ans	 = 0;
		for(int i = 1; i <= n; i++) {
			if(no[a[i]])
				continue;
			ans++;
			no[a[i]] = true;
			for(int j = a[i]; j <= maxx; j++) {
				if(no[j - a[i]])
					no[j] = true;
				// if(no[j])
				// 	no[j + a[i]] = true;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}