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
		else {
			int ans = 0;
			for(int i = ll - 1; i >= wei; i--)
				if(s[i] == 'R') {
					ans = i - wei;
					break;
				}
			cout << (ans ? ans : 1) << endl;
		}
	}

	return 0;
}