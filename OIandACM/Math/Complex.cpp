typedef long long ll;
ll mod = 1e9+7;
ll CC;

ll qpow(ll x, ll n){
    ll ret = 1;
    x %= mod;
    while(n){
        if(n & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

struct Complex { // 扩域
    ll a, b;// a + b * c
    ll c;
    // Complex(ll a = 0, ll b = 0) : a(a), b(b) {}
    Complex(ll a = 0, ll b = 0, ll c = CC) : a(a), b(b), c(c) {}

    Complex operator+(const Complex &x) const {
        Complex res;
        res.a = a + x.a;
        res.b = b + x.b;
        if(res.a >= mod)
            res.a -= mod;
        if(res.b >= mod)
            res.b -= mod;
        return res;
    }
    Complex operator-(const Complex &x) const {
        Complex res;
        res.a = a - x.a + mod;
        res.b = b - x.b + mod;
        if(res.a >= mod)
            res.a -= mod;
        if(res.b >= mod)
            res.b -= mod;
        return res;
    }
    Complex operator*(const Complex &x) const {
        Complex res;
        res.a = (a * x.a + c * b % mod * x.b) % mod;
        res.b = (a * x.b + x.a * b) % mod;
        return res;
    }
    Complex operator*(const ll &x) const {
        return Complex(this->a * x % mod, this->b * x % mod);
    }
    Complex operator^(ll t) const {
        Complex res = Complex(1, 0);
        Complex a = *this;
        a.a %= mod;
        a.b %= mod;
        while(t) {
            if(t & 1)
                res = res * a;
            a = a * a;
            t >>= 1;
        }
        return res;
    }
    Complex inv(){
        ll down = (this->a * this->a % mod - this->b * this->b % mod * this->c % mod + mod) % mod;
        down = qpow(down, mod - 2);
        return Complex(this->a, mod - this->b) * down;
    }
    Complex operator/(Complex &x) const {
        return *this * (x.inv());
    }
};
