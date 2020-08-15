#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 19260817;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cout << i << " ";
		cout << '\n';
	}
	return 0;
}
