#include <bits/stdc++.h>
using namespace std;

int a[110000];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + 1 + n);
		int ans = 1;
		for(int i = n; i; i--)
			if(a[i] <= i) {
				ans = i + 1;
				break;
			}
		printf("%d\n", ans);
	}

	return 0;
}
