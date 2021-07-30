#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

ll ex_gcd(ll a, ll b, ll &x, ll &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ll ret, tmp;
    ret = ex_gcd(b, a % b, x, y);
    tmp = x;
    x = y;
    y = tmp - a / b * y;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll x, y, n, m, len;
    cin >> x >> y >> m >> n >> len;
    ll a = x - y;
    ll b = n - m;
    if(b < 0){
        a *= -1;
        b *= -1;
    }
    ll d = ex_gcd(b, len, x, y);
    if(a % d){
        cout << "Impossible\n";
    }else{
        cout << (((a / d) * x) % (len / d) + (len / d)) % (len / d) << '\n';
    }

    return 0;
}

