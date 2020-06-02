#include <bits/stdc++.h>
using namespace std;

long long a[109][109];
long long f[109][109];
int n, m;

long long solve(long long now){
	// memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			f[i][j] = 0x7ffffffffffffff;
	f[1][1] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(now + i + j <= a[i][j]){
				f[i][j] += a[i][j] - now - i - j;
				if(i + 1 <= n)
					f[i + 1][j] = min(f[i][j], f[i + 1][j]);
				if(j + 1 <= m)
					f[i][j + 1] = min(f[i][j], f[i][j + 1]);
			}else {
				f[i][j] = 0x7ffffffffffffff;
			}
	return f[n][m];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> a[i][j];
		long long ans = 0x7ffffffffffffff;
		// memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				ans = min(ans, solve(a[i][j] - i - j));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
