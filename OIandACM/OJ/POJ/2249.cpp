/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-08-14 11:02:54
*/
// #include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    while(cin >> n >> k && (n || k)){
        if(n - k < k)
            k = n - k;
        ll ans = 1;
        for(ll i = 1; i <= k; i++)
            ans = ans * (n + 1 - i) / i;
        cout << ans << '\n';
    }

    return 0;
}