#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 25 + 9;
const ll  mod  = 1e9 + 7;

char a[size][size];

int how(int x, int y) {
	int ret = 0;
	for(int i = x - 1; i <= x + 1; i++)
		for(int j = y - 1; j <= y + 1; j++)
			if(a[i][j] == 'X')
				ret++;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int s;
		cin >> s;
		int n, m;
		memset(a, 0, sizeof(a));
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
		// for(int j = 1; j <= m; j++)
		{
			cin >> a[i] + 1;
			// a[i][0] = '0';
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) {
				if(a[i][j] == '.') {
					ans += how(i, j);
				}
			}
		if(s == ans)
			cout << "Newbie\n";
		else
			cout << s << "\t!=\t" << ans << '\n';
	}

	return 0;
}