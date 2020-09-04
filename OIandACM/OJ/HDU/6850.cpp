/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-11 14:57:06
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e2 + 9;
const ll  mod  = 1e9 + 7;

struct ohno {
	double v;
	int	   id;
} f[size][size];
ll	 x[size];
ll	 y[size];
bool is[size];

double dis(int a, int b) { return sqrt(1.0 * (x[a] - x[b]) * (x[a] - x[b]) + 1.0 * (y[a] - y[b]) * (y[a] - y[b])); }

bool cmp(ohno x, ohno y) {
	return x.v < y.v;
}

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		memset(is, 0, sizeof(is));
		for(int i = 1; i <= n; i++) {
			cin >> x[i] >> y[i];
		}
		// is[1] = false;
		for(int i = 1; i < n; i++) {
			for(int j = i; j <= n; j++) {
				f[i][j].v  = dis(i, j);
				f[i][j].id = j;
				f[j][i].v  = f[i][j].v;
				f[j][i].id = i;
			}
			sort(f[i] + 1, f[i] + n + 1, cmp);
		}
		sort(f[n] + 1, f[n] + n + 1, cmp);
		ll	d	= 0;
		int ok	= 0;
		is[1]	= true;
		int now = 1;
		while(true) {
			bool xk = false;
			for(int i = n; i; i--) {
				if(!is[i]) {
					d += f[now][i].v;
					is[i] = true;
					xk	  = true;
					for(int j = 1; j <= n; j++) {
						if(!is[f[i][j].id] && d < f[i][j].v) {
							xk = false;
							break;
						}
					}
					if(xk) {
						// ok = true;
						break;
					} else {
						// ok = false;
						d -= f[now][i].v;
						is[i] = false;
						break;
					}
				}
			}
			ok++;
			if(xk && (ok & 1)) {
				// ok = !ok;
				break;
			} else {
				// ok = !ok;
				int i;
				for(i = 1; i <= n; i++) {
					if(!is[f[now][i].id]) {
						is[f[now][i].id] = true;
						d += f[now][i].v;
						now = f[now][i].id;
						break;
					}
				}
				if(i == n + 1) {
					ok = 1;
					break;
				}
			}
		}
		cout << ok << endl;
		if(ok & 1) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}