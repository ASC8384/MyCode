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

    ll a, b, c;
    while (cin >> a >> b >> c) {
         ll x, y;
         ll d = ex_gcd(a, b, x, y);
         if(c % d)
             cout << "-1\n";
         else
             cout << -c/d*x << ' ' << -c/d*y << '\n';
    }

    return 0;
}

