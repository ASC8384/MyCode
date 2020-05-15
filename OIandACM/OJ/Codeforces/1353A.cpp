#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		long long n, m;
		cin >> n >> m;
		if(n == 1)
			cout << 0 << endl;
		else if(n == 2)
			cout << m << endl;
		else
			cout << m * 2 << endl;
	}
	return 0;
}