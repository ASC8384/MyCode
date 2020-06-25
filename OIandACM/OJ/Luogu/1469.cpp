#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		ans ^= a;
	}
	cout << ans << endl;
	return 0;
}