#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 3e5 + 9;
const ll  mod  = 1e9 + 7;

ll a[size];

void solve(ll q) {
	while(q--) {
		ll le, ri;
		cin >> le >> ri;
		ll x = a[ri] - a[le - 1];
		x	 = abs(x);
		if(x == 0)
			cout << 0 << '\n';
		else {
			cout << ((x & 1) ? 1 : 2) << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		string s;
		ll	   n, q;
		cin >> n >> q;
		cin >> s;
		if(s[0] == '-')
			a[1] = -1;
		else
			a[1] = 1;
		for(ll i = 1; i < n; i++) {
            ll k = (i & 1) ? -1 : 1;
			if(s[i] == '-') {
				a[i + 1] = a[i] - k;
			} else {
				a[i + 1] = a[i] + k;
			}
		}
		solve(q);
	}

	return 0;
}