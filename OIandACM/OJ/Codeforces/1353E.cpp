#include <bits/stdc++.h>
using namespace std;

const int size = 1e6+9;
int qm[size];
int f[size];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int k, n;
		cin >> n >> k;
		// cin >> k >> n;
		string s;
		cin >> s;
		int ans = n;
		// k++;
		// k--;
		qm[0] = s[0] - '0';
		for(int i = 1; i < n; i++){  
            qm[i] = qm[i-1] + s[i] - '0';
        }
		for(int i = 0; i < n; i++){
			f[i] = qm[i] - (s[i] == '1');
			if(i - k >= 0){
				f[i] = min(f[i],
						f[i - k] + (s[i] != '1') + qm[i - 1] - qm[i - k]);
			}
			ans = min(ans, f[i] + qm[n-1] - qm[i]);
		}
		// for(int i = 0; i < n; i++)printf("%d:f_%d q_%d\n", i, f[i], qm[i]);
		cout << ans << endl;
	}
	return 0;
}
