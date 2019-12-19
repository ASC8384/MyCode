#include <bits/stdc++.h>
using namespace std;

int ans[100009];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t, n;
	cin >> t;

	while(t--){
		cin >> n;
		if(n & 1)
			cout << n * (n + 1) << endl;
		else
			cout << -1 * n * (n + 1) << endl;
	}
	return 0;
}