#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 1e6 + 19;
const ll  mod  = 666623333;

bool isp[size];
ll	 phi[size], pos[size];

vector<ll> pri;

void ux() {
	for(int i = 2; i < size; i++) {
		if(!isp[i])
			pri.push_back(i);
		for(int j = 2; i * j < size; j++)
			isp[i * j] = true;
	}
}

ll le, ri;

void oula() {
	for(auto i : pri) {
		for(ll j = max(2ll, (le - 1ll) / i + 1ll); i * j <= ri; j++)
		{
			ll x   = i * j - le;
			phi[x] = phi[x] / i * (i - 1ll);
			while(pos[x] % i == 0)
				pos[x] /= i;
		}
	}
}

int main() {
	cin >> le >> ri;

	ux();
	for(ll i = le; i <= ri; i++)
		phi[i - le] = pos[i - le] = i;
	oula();
	ll ans = 0;
	for(ll i = le; i <= ri; i++) {
		ll x = i - le;
		if(pos[x] != 1ll)
			phi[x] = phi[x] / pos[x] * (pos[x] - 1ll);
		ans = (ans + (i - phi[x])) % mod;
	}
	cout << ans << endl;

	return 0;
}