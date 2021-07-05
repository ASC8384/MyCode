#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
        int ans = 2;
        int a[233];
		for(int i = 2; i <= 233; i++) {
			// unordered_map<int, int> a;
            memset(a, 0, sizeof(a));
            ll x = n;
            while(x){
                if(++a[x%i] == 2)
                    break;
                x /= i;
            }
            if(x == 0){
                ans = i;
                break;
            }
		}
        cout << ans << '\n';
	}

	return 0;
}