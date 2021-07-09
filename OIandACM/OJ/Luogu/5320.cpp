#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long ll;
ll mod = 998244353;
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

ll T, m;
ll inv2, sqr;
ll fac;
ll s[2333][2333], C[2333][2333];
Complex bb, aa, A, B;

ll calc(ll n, ll k) {
    ll ans = 0;
    for(ll j = 0, fu = (k % 2 ? mod - 1 : 1); j <= k; j++, fu = mod - fu) {
        Complex now = Complex(0, 0);
        for(ll d = 0; d <= j; d++) {
            Complex tmm = (bb ^ d) * (aa ^ (j - d));
            Complex tpp = (tmm ^ (n + 1));
            if(tmm.a == 1 && tmm.b == 0)
                tpp = Complex((n + 1) % mod ,0);
            else {
                tmm = (Complex(1, 0)  - tmm).inv();
                tpp = (Complex(1, 0)  - tpp) * tmm;
            }
            tpp = tpp * (B ^ d) * (A ^ (j - d));
            tpp = tpp * C[j][d];
            now = now + tpp;
        }
        ans = (ans + s[k][j] * fu % mod * now.a % mod) % mod;
    }
    return ans * fac % mod;
}

int main() {
    scanf("%lld%lld", &T, &m);
    s[0][0] = C[0][0] = 1;
    for(ll i = 1; i <= 502; i++) {
        C[i][0] = 1;
        for(ll j = 1; j <= 502; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
            s[i][j] = (s[i - 1][j] * (i - 1) % mod + s[i - 1][j - 1]) % mod;
        }
    }
    inv2 = qpow(2, mod - 2);
    if(m == 2) {
        CC = 5;
        aa = Complex(inv2, inv2);
        bb = Complex(inv2, mod - inv2);
        A  = Complex(0, qpow(5, mod - 2));
        B  = Complex(0, mod - qpow(5, mod - 2));
    } else {
        CC = 3;
        aa = Complex(2, mod - 1);
        bb = Complex(2, 1);
        A  = Complex(inv2, mod - qpow(6, mod - 2));
        B  = Complex(inv2, qpow(6, mod - 2));
    }
    while(T--) {
        ll le, ri, k;
        scanf("%lld%lld%lld", &le, &ri, &k);
        fac = 1;
        for(ll i = 1; i <= k; i++)
            fac = fac * i % mod;
        fac = qpow(fac, mod - 2);
        ll inv = qpow(ri - le + 1, mod - 2);
        if(m == 2) {
            ri++;
        } else {
            le = (le - 1) / 2;
            ri = ri / 2;
        }
        // cout << "now\t:" << (calc(ri, k) - calc(le, k) + mod) % mod << endl;
        // cout << calc(le, k) << endl;
        ll ans = (calc(ri, k) - calc(le, k) + mod) % mod * inv % mod;
        printf("%lld\n", ans);
    }
    return 0;
}
