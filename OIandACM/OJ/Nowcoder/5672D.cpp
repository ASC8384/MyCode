#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 100001;
const ll  mod  = 1e9 + 7;

bool is(ll n) {
	// for(ll i = 1; n > 0; i += 2)
	// 	n -= i;
	// return 0 == n;
	ll m = floor(sqrt(n) + 0.5);
	return (m * m == n);
}

ll a[size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	// t = 100000;
	// for(ll i = 1; i <= t; i++)
	// 	a[i] = i * i + a[i - 1];
	while(t--) {
		ll n;
		cin >> n;
		if(n == 1 || n == 24) {
			cout << "Fake news!" << '\n';
		} else {
			cout << "Nobody knows it better than me!" << '\n';
		}
		// if(t % 1000 == 0)
		// 	cout << t << endl;
		// // ll ans = 0;
		// // for(ll i = 1; i <= t; i++)
		// // 	ans += i * i;
		// if(is(a[t])) {
		// 	cout << t << " " << a[t] << endl;
		// }
	}

	return 0;
}