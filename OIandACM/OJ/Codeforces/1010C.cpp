#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin >> n >> k;
    ll d = 0;
    for(int i = 1; i <= n; i++){
        ll a;
        cin >> a;
        d = __gcd(d, a%k);
    }
    if(d == 0)
        d = 1;
    cout << k / d << '\n';
    for(int i = 0; i < k / d; i++){
        cout << i * d << ' ';
    }

    return 0;
}

