#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const int				   size = 1e6 + 10;
inline void				   qread() {}
template <class T1, class... T2>
inline void qread(T1 &IEE, T2 &... ls) {
	register T1	  __ = 0, ___ = 1;
	register char ch;
	while(!isdigit(ch = getchar()))
		___ = (ch == '-') ? -___ : ___;
	do {
		__ = (__ << 1) + (__ << 3) + (ch ^ 48);
	} while(isdigit(ch = getchar()));
	__ *= ___;
	IEE = __;
	qread(ls...);
	return;
}

ll prime[size], nprime;
ll vis[size];

void getprime() {
	nprime = 0;
	memset(vis, 0, sizeof(vis));
	ll len = sqrt(size - 9);
	for(ll i = 2; i <= len; i++) {
		ll t = len / i;
		for(ll j = 2; j <= t; j++)
			vis[i * j] = 1;
	}
	for(ll i = 2; i <= len; i++) {
		if(!vis[i])
			prime[++nprime] = i;
	}
}

ll pow_mod(ll a, ll n) {
	ll ans = 1;
	while(n) {
		if(n & 1)
			ans = (ans * a);
		n >>= 1;
		a = (a * a);
	}
	return ans;
}
// ll f[size];

ll	 f[1100000] = {0, 1};
void factor_sum(ll n) {
	for(int now = 2; now <= n; now++) {
		ll k   = sqrt(now * 1.0);
		ll ans = 1, sum;
		for(ll i = 1; prime[i] <= k; i++) {
			if(now % prime[i] == 0) {
				sum = 0;
				while(now % prime[i] == 0) {
					sum++;
					now /= prime[i];
				}
				ans *= (pow_mod(prime[i], sum + 1) - 1) / (prime[i] - 1);
			}
		}
		if(now > 1)
			ans *= (1 + now); //(now * now - 1) / (now - 1);
		f[now] = f[now - 1] + ans;
	}
	// return ans;
}

vector<ll> pri;

void solve(ll i) {
	ll ans = 1, s = i;
	for(int j = 0; j < pri.size() && pri[j] * pri[j] <= s; j++)
		if(s % pri[j] == 0) {
			int k = 0;
			while(s % pri[j] == 0) {
				k++;
				s /= pri[j];
			}
			ans *= (pow_mod(pri[j], k + 1) - 1) / (pri[j] - 1); //kk(pri[j], k);
		}
	if(s == i)
		pri.push_back(i);
	if(s != 1)
		ans = ans * (1 + s);
	f[i] = f[i - 1] + ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i = 2; i <= 1000000; i++)
		solve(i);
	int n;
	qread(n);
	while(n--) {
		int ri, le;
		qread(le, ri);
		cout << f[ri] - f[le - 1] << endl;
	}
}