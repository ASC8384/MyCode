typedef long long ll;

ll mod = 1e9 + 7;
ll i2  = 0;

struct com {
	ll a, b; // a 是实部，b 是虚部
	ll i2;	 // i^2
	com(ll a = 0, ll b = 0, ll i2 = 0) : a(a), b(b), i2(i2) {}
	com operator*(const com &x) const {
		return com((a * x.a % mod + b * x.b % mod * i2 % mod + mod) % mod,
				   (b * x.a % mod + a * x.b % mod + mod) % mod, x.i2);
	}
	bool operator==(const com &x) const {
		return (a == x.a && b == x.b);
	}
	friend com operator^(com &x, ll t) {
		com ret = 1;
		ret.i2	= x.i2;
		while(t) {
			if(t & 1)
				ret = ret * x;
			x = x * x;
			t >>= 1;
		}
		return ret;
	}
};