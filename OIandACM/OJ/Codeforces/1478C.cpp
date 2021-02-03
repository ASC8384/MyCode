#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

ll	a[size];
int n;

void init() {
	cin >> n;
	n <<= 1;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		init();
		bool is = false;
		for(int i = 1; i <= n; i++) {
			if(a[i] & 1) {
				is = true;
				break;
			}
			a[i] >>= 1;
			if(a[i] == 0) {
				is = true;
				break;
			}
		}
		if(is) {
			cout << "NO\n";
			continue;
		}
		sort(a + 1, a + n + 1);
		ll sum	= 0;
		ll maxx = 0x7ffffffffffffff;
		for(int i = n; i; i -= 2) {
			if(a[i] != a[i - 1] || a[i] == a[i - 2]) {
				is = true;
				break;
			}
			ll li  = (i >> 1);
			ll now = a[i] - sum;
			if(now <= 0 || now % li != 0) {
				is = true;
				break;
			}
			ll k = now / li;
			if(k >= maxx) {
				is = true;
				break;
			}
			sum += k;
			maxx = k;
		}
		if(is) {
			cout << "NO\n";
			continue;
		} else {
			cout << "YES\n";
		}
	}

	return 0;
}
