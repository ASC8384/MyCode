#include <bits/stdc++.h>
using namespace std;

int a[33];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t;
	int a[2333];
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		bool flag = true;
		sort(a + 1, a + n + 1);
		for(int i = 2; i <= n; i++)
			if((a[i] - a[i - 1]) % 2 != 0) {
				flag = false;
				break;
			}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}