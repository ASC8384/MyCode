/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-04-17 12:58:53
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        ll n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;
        ll ans = ((x1 + x2) * (x2 - x1 + 1) / 2) % mod;
        ans = ans * ((y1 + y2) * (y2 - y1 + 1) / 2) % mod;
        cout << ans % mod << '\n';
    }

    return 0;
}