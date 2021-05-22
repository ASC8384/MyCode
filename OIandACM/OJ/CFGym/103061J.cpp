#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 998244353;

ll a[1000006], b[1000006];
ll d[1000006][3];

ll dfs(ll n, ll k){
    if(d[n][k] != 0)
        return d[n][k];
    if(n < 5)
        return 0;
    if(k == 0){
        d[n][k] = dfs(n-1, 1) * 2 % mod;
    }else{
        d[n][k] = dfs(n-2, 1) + dfs(n-2, 0);
        d[n][k] %= mod;
    }
    // cout << n << ' ' << k << '\t' << d[n][k] << '\n';
    return d[n][k];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n;
    cin >> n;

    d[2][1] = 1;
    d[4][1] = 1;
    d[5][1] = 2;
    d[3][0] = 2;

    cout << dfs(n, 1) << '\n';

    return 0;
}

