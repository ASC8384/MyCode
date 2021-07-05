#include <bits/stdc++.h>
using namespace std;

// vector<int> a, b;
int a[100009];
int b[100009];

int main() {
	int t;
	// scanf("%d", &t);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--) {
		// a.clear();
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		// b.clear();
		int n, m;
		// scanf("%d%d", &n, &m);
		cin >> n >> m;
		for(int i = 1; i <= n; i++) {
			// scanf("%d", &a[i]);
			cin >> a[i];
		}
		for(int i = 1; i <= m; i++) {
			// scanf("%d", &b[i]);
			cin >> b[i];
		}
		int ans = 0x7fffffff;
		// sort(a.begin(), a.end());
		sort(a + 1, a + n + 1);
		sort(b + 1, b + m + 1);
		// sort(b.begin(), b.end());
		int i = 1;
		int j = 1;
		while(i <= n && j <= m) {
			if(a[i] != b[j]) {
				ans = min(ans, abs(a[i] - b[j]));
				if(a[i] > b[j])
					j++;
				else
					i++;
			} else {
				// printf("0\n");
				ans = 0;
				break;
			}
		}
		// printf("%d\n", ans);
		cout << ans << '\n';
	}
}