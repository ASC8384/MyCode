#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[55], b[55];
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
			cin >> b[i];
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		int ans = 0;
		int bi, ai;
		bi = n;
		ai = n;
		for(int i = n; i > 0; i--) {
			if(k && b[bi] > a[ai]) {
				k--;
				ans += b[bi];
				bi--;
			}
			//ans += a[ai--];
			else {
				ans += a[ai--];
			}
		}
		cout << ans << endl;
	}
	return 0;
}