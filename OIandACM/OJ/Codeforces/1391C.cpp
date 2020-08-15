#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

ll qpow(ll a, ll b) {
	ll ret = 1;
	while(b > 0) {
		if(b & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret % mod;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	ll n;
	cin >> n;

	ll tmp = 1;
	for(int i = 1; i <= n; i++)
		tmp = tmp * i % mod;
	cout << (tmp - qpow(2, n - 1) + mod) % mod << '\n';

	return 0;
}
