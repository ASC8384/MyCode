#include <bits/stdc++.h>
#include <cctype>
#include <cstdio>
using namespace std;
typedef long long ll;
ll mod = 19260817;

ll qpow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

ll read(){
    ll x = 0;
    char c;
    for(c = getchar(); !isdigit((c)); c = getchar());
    for(x = 0; isdigit(c); c= getchar())
        x = (x * 10 + c - '0') % mod;
    return x;
}

int main()
{
    ll a = read();
    ll b = read();
    printf("%lld\n", a * qpow(b, mod - 2) % mod);
    return 0;
}

