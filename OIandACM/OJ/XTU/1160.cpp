#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, k;
int b[233][233], a[233];
int x[233], y[2333];
int ret[23443][233];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while(cin >> n) {
		if(n == 0)
			return 0;
		cin >> k;
		for(int i = 1; i <= k; i++) {
			for(int j = 1; j <= 4; j++) {
				cin >> b[i][j];
			}
			cin >> x[i] >> y[i];
		}
		int ans = 0;
		for(a[1] = 1; a[1] <= n; a[1]++) {
			for(a[2] = 1; a[2] <= n; a[2]++) {
				for(a[3] = 1; a[3] <= n; a[3]++) {
					for(a[4] = 1; a[4] <= n; a[4]++) {
						if(a[1] == a[2] || a[1] == a[3] || a[1] == a[4] || a[2] == a[3] || a[2] == a[4] || a[3] == a[4])
							continue;
						bool flg = true;
						for(int i = 1; i <= k; i++) {
							int xx = 0;
							int yy = 0;
							for(int j = 1; j <= 4; j++) {
								if(b[i][j] == a[j])
									yy++;
								for(int t = 1; t <= 4; t++) {
									if(b[i][j] == a[t] && t != j)
										xx++;
								}
							}
							if(xx != y[i] || yy != x[i]) {
								flg = false;
								break;
							}
						}
						if(flg) {
                            ans++;
                            for(int i = 1; i<= 4; i++)
                                ret[ans][i] = a[i];
						}
					}
				}
			}
		}
		for(int i = 1; i <= ans; i++) {
			for(int j = 1; j <= 3; j++)
				cout << ret[i][j] << ' ';
			cout << ret[i][4] << '\n';
		}
		cout << ans << '\n';
	}

	return 0;
}