#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 998244353;

ll PowerMod(ll a, ll b, ll c) {
	ll ans = 1;
	a	   = a % c;
	while(b > 0) {
		if(b % 2 == 1)
			ans = (ans * a) % c;
		b = b / 2;
		a = (a * a) % c;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t = 1;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		cout << PowerMod(26, n, mod) << '\n';
	}

	return 0;
}