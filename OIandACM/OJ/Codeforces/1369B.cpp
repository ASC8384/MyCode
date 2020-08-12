#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int		  size = 2e5 + 9;
const ll		  mod  = 19260817;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s;
		int len	 = s.length();
		int pos0 = len - 1;
		int pos1 = 0;
		int cnt1 = 0;
		int cnt0 = 0;
		for(int i = len - 1; i >= 0; i--) {
			if(s[i] == '1')
				cnt1++;
			else {
				pos1 = i;
				break;
			}
		}
		for(int i = 0; i < len; i++)
			if(s[i] == '0')
				cnt0++;
			else {
				pos0 = i;
				break;
			}
		if(pos0 > pos1) {
			cout << s;
		} else {
			for(int i = 0; i < pos0; i++)
				cout << s[i];
			for(int i = pos1; i < len; i++)
				cout << s[i];
		}
		// if(cnt0 == 0 && cnt1 == 0) {
		// 	cout << 0;
		// 	continue;
		// }
		// for(int i = 1; i <= cnt0; i++)
		// 	cout << 0;
		// for(int i = 1; i <= cnt1; i++)
		// 	cout << 1;
		cout << endl;
	}
}
