#include <bits/stdc++.h>
using namespace std;

int ans[100009];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	unsigned long long t, n;
	cin >> t;

	while(t--){
		cin >> n;
		if(n & 1)
			cout << n * (n + 1) << endl;
		else
			cout << "-" << n * (n + 1) << endl;
	}
	return 0;
}