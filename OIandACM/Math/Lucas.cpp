ll C(ll n, ll m) {
	if(n < m)
		return 0;
	return (jc[n] % mod * qpow(jc[m] * jc[n - m] % mod, mod - 2) % mod) % mod;
}

ll lucas(ll n, ll m) {
	if(m == 0)
		return 1;
	else
		return (lucas(n / mod, m / mod) * C(n % mod, m % mod)) % mod;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll n, m;
		cin >> n >> m >> mod;
		jc[0] = 1;
		for(ll i = 1; i <= mod; i++) {
			jc[i] = (jc[i - 1] * i) % mod;
		}
		cout << lucas(n + m, m) << endl;
	}
	return 0;
}