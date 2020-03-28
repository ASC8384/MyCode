#include <bits/stdc++.h>
using namespace std;

int	a[9999];
int	b[9999];
string s;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t;

	cin >> t;
	while(t--) {
		cin >> s;
		int ll = s.size();
		int wei;
		for(wei = 0; wei < ll; wei++) {
			if(s[wei] == 'R')
				break;
		}
		if(wei == ll)
			cout << (ll ? ll + 1 : 1) << endl;
		else if(wei == ll - 1)
			cout << ll << endl;
		else {
			s  = "R" + s + "R";
			ll = s.size();

			int ans = 0;
			wei		= 0;
			for(int i = 1; i < ll; i++)
				if(s[i] == 'R') {
					ans = max(ans, i - wei);
					wei = i;
					// cout << i << ' ';
					// break;
				}
			cout << (ans ? ans : 1) << endl;
		}
	}

	return 0;
}