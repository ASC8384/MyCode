#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e6 + 9;
const ll  mod  = 19260817;

int a[5][size];
int f[5][5];
int b[size];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	if(n > 3 && m > 3) {
		cout << -1 << '\n';
		return 0;
	} else if(n == 1 || m == 1) {
		cout << 0 << '\n';
		return 0;
	} else {
		if(n == 2) {
			for(int i = 1; i <= m; i++)
				cin >> a[1][i];
			for(int i = 1; i <= m; i++)
				cin >> a[2][i];
			for(int i = 1; i <= m; i++) {
				// f[i] = a[1][i] + a[2][i];
				f[i & 1][(a[1][i] + a[2][i]) & 1]++;
			}
			int ans = 0;
			if(f[0][0] + f[1][1] > f[0][1] + f[1][0]) {
				for(int i = 1; i <= m; i++) {
					if((i & 1) && ((a[1][i] + a[2][i]) & 1)) {
						ans++;
					} else if((i & 1) == 0 && ((a[1][i] + a[2][i]) & 1) == 0) {
						ans++;
					}
				}
			} else {
				for(int i = 1; i <= m; i++) {
					if((i & 1) && ((a[1][i] + a[2][i]) & 1) == 0) {
						ans++;
					} else if((i & 1) == 0 && ((a[1][i] + a[2][i]) & 1)) {
						ans++;
					}
				}
			}
			cout << ans << '\n';
		} else if(n == 3) {
			for(int i = 1; i <= m; i++)
				cin >> a[1][i];
			for(int i = 1; i <= m; i++)
				cin >> a[2][i];
			for(int i = 1; i <= m; i++)
				cin >> a[3][i];
			bool is	 = (a[1][1] + a[2][1]) & 1;
			int	 ans = 0;
			for(int i = 2; i <= m; i++) {
				if(is & 1) {
					if((a[1][i] + a[2][i]) & 1) {
						ans++;
						b[i] = 1;
					}
				} else {
					if(((a[1][i] + a[2][i]) & 1) == 0) {
						ans++;
						b[i] = 1;
					}
				}
				is = !is;
			}
			is = (a[3][1] + a[2][1]) & 1;
			for(int i = 2; i <= m; i++) {
				if(is & 1) {
					if(((a[3][i] + a[2][i]) & 1) && !b[i]) {
						ans++;
						// b[i] = 1;
					}
				} else {
					if(((a[3][i] + a[2][i]) & 1) == 0 && !b[i]) {
						ans++;
						// b[i] = 1;
					}
				}
				is = !is;
			}
			cout << ans << endl;
		}
	}

	return 0;
}
