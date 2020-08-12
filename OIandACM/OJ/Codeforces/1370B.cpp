#include <bits/stdc++.h>
using namespace std;

int a1[1999];
int a2[1999];
int cnt1, cnt2;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		int tmp;
		cin >> n;
		int k = n - 1;
		cnt1 = cnt2 = 0;
		for(int i = 1; i <= 2 * n; i++) {
			cin >> tmp;
			if(tmp & 1)
				a1[++cnt1] = i;
			else
				a2[++cnt2] = i;
		}
		for(unsigned int i = 2; i <= cnt1; i += 2)
			if(k == 0)
				break;
			else {
				cout << a1[i - 1] << " " << a1[i] << endl;
				k--;
			}
		for(unsigned int i = 2; i <= cnt2; i += 2)
			if(k == 0)
				break;
			else {
				cout << a2[i - 1] << " " << a2[i] << endl;
				k--;
			}
		// cout << (n >> 1) << endl;
	}
}
