#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		v.clear();
		int n;
		cin >> n;
		v.resize(n);
		for(int i = 0; i < n; i++) {
			cin >> v[i];
		}
        int now = 2;
        int ans = 2;
		for(int i = 2; i < n; i++) {
			if(v[i] == v[i-1] + v[i-2]){
                now++;
            }else{
                ans = max(ans, now);
                now = 2;
            }
		}
        ans = max(ans, now);
        cout << ans << '\n';
	}

	return 0;
}