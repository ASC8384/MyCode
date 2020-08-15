#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const int mod  = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, sx, sy;
	int now, tmp;
	cin >> n >> m >> sx >> sy;
	cout << sx << ' ' << sy << '\n';
	for(int i = 1; i <= m; i++)
		if(i != sy)
			cout << sx << ' ' << i << '\n';
	now = tmp = m;
	for(int i = 1; i <= n; i++) {
		if(i != sx) {
			cout << i << ' ' << tmp << '\n';
			for(int j = 1; j <= m; j++)
				if(j != tmp) {
					now = j;
					cout << i << ' ' << j << '\n';
				}
			tmp = now;
		}
	}

	return 0;
}