#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

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

//ax + by = gcd(x, y)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll x, y;
        ll d = ex_gcd(a, b, x, y);
        if(c % d) {
            cout << "-1\n";
            continue;
        }
        x    = c / d * x;
        y    = c / d * y;
        ll i = b / d;
        ll j = a / d;
        ll k;
        if(x < 0) {
            k = ceil((1.0 - x) / i);
            x += i * k;
            y -= j * k;
        } else {
            k = (x - 1) / i;
            x -= i * k;
            y += j * k;
        }
        if(y > 0) {
            cout << (y - 1) / j + 1 << ' ';     // total
            cout << x << ' ';                   // min x
            cout << (y - 1) % j + 1 << ' ';     // min y
            cout << x + (y - 1) / j * i << ' '; // max x
            cout << y << '\n';                  // max y
        } else {
            cout << x << ' ';                    // min x
            cout << (long long)(y + j * ceil((1.0 - y) / j)) << '\n'; // min y
        }
    }

    return 0;
}

