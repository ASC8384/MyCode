#include <bits/stdc++.h>
using namespace std;

long long a[200009];
long long b[200009];
// string s;

// inline int init()

int main() {
	// int tim = clock();
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int j = 1; j <= n; j++) {
		cin >> b[j];
		a[j] -= b[j];
	}
	sort(a + 1, a + n + 1);
	unsigned long long ans = 0;
	for(int i = 1; i <= n; i++) {
		int ll = i + 1;
		int rr = n;
		while(ll <= rr) {
			int mid = (ll + rr) / 2;
			if(a[i] + a[mid] > 0) {
				rr = mid - 1;
			} else
				ll = mid + 1;
		}
		ans += n - ll + 1;
	}
	// printf()
	cout << ans << endl;
	// cout << clock() - tim << endl;

	return 0;
}