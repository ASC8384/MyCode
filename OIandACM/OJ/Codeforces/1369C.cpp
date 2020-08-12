#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int		  size = 2e5 + 9;
const ll		  mod  = 19260817;

int a[size], w[size];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		ll ans	= 0;
		ll maxx = 0;
		ll minn = 0;
		ll cnt	= 0;
		for(ll i = 1; i <= k; i++) {
			cin >> w[i];
			if(w[i] == 1) {
				cnt++;
			} else {
				minn++;
				maxx++;
			}
		}
		sort(w + 1, w + 1 + k);
		sort(a + 1, a + 1 + n);
		int pos = n;
		for(int i = 1; i <= cnt; i++) {
			ans += (a[pos--] << 1);
		}
		for(int i = 1; i <= maxx; i++) {
			ans += a[pos--];
		}
		pos = 1;
		for(int i = k; i; i--) {
			if(w[i] != 1) {
				ans += a[pos];
				pos += w[i] - 1;
			}
		}
		cout << ans << '\n';
	}
	// cout << end;
	return 0;
}