#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

vector<ll> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b;
    cin >> a >> b;
    ll d = __gcd(a, b);
    for(int i = 1; i*i <= d; i++){
        if(d % i == 0){
            v.push_back(i);
            v.push_back(d/i);
        }
    }
    ll t;
    cin >> t;
    sort(v.begin(), v.end());
    while (t--) {
        ll x, y;
        cin >> x >> y;
        int pos = upper_bound(v.begin(), v.end(), y) - v.begin() - 1;
        if(v[pos] < x)
            cout << "-1\n";
        else
            cout << v[pos] << '\n';
    }

    return 0;
}

