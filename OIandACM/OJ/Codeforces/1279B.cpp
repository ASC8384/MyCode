#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

// int a[233333];

int main() {
	FAST;
	int t, n, s;
	// cin >> n >> s;
	cin >> t;
	while(t--) {
		// vector<int> a;
		int	 maxx = 0;
		int	 sum  = 0;
		int	 ans  = 0;
		bool flag = false;
		cin >> n >> s;
		// for(int i = 0; i < n; i++) {
		// 	int tmp;
		// 	cin >> tmp;
		// 	a.push_back(tmp);
		// }
		// for(auto i : a) {
		for(int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			sum += tmp;
			if(!flag && tmp >= maxx) {
				maxx = tmp;
				ans	 = i;
			}
			if(sum > s) {
				flag = true;
				// break;
			}
		}
		if(flag)
			cout << ans + 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}