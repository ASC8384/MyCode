#include <bits/stdc++.h>
using namespace std;

int main() {
	long long x1, x2, y1, y2;
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << (x2 - x1) * (y2 - y1) + 1 << endl;
	}

	return 0;
}
