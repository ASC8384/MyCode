#include <bits/stdc++.h>
using namespace std;

long long a[109][109];
long long f[109][109];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> a[i][j];
		long long ans = 0;
		memset(f, 0, sizeof(f));
		for(int i = n; i > 0; i--) {
			for(int j = n; j > 0; j--) {
                f[i][j] = 
			}
		}
	}
	return 0;
}