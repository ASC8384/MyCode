#include <bits/stdc++.h>
#include <cmath>
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

    ll T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        ll a, b, c, p;
        cin >> a >> b >> c >> p;
        ll x, y;
        ll d = ex_gcd(a, b, x, y);
        ll ans = 0;
        for(int i = 0; i <= p; i += c){
            ll k = p - i;
            if(k % d)
                continue;
            ans += (floor(1.0 * x * k/d * d/b) - ceil(-1.0 * k/d * y * d/a) + 1);
        }
        cout << "Case " << t << ": " << ans << '\n';
    }

    return 0;
}

