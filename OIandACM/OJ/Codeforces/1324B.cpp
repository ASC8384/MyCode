#include <bits/stdc++.h>
using namespace std;

int a[9999];
int b[9999];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t;

	cin >> t;
	while(t--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			b[a[i]]++;
		}
		bool flag = false;
		for(int i = 1; i <= n; i++)
			if(b[i] >= 3) {
				flag = true;
				break;
			}
		if(flag == false) {
			for(int i = 1; i <= n; i++) {
				if(b[a[i]] == 2) {
					for(int j = n; j > i; j--)
						if(a[j] == a[i] && (j - i) > 1) {
							flag = true;
							goto exit;
						}
				}
			}
		}
	exit:
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}