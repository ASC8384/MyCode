/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-08-15 22:36:51
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

ll a[size];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        // vector<int> v;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        ll ans = a[1];
        for(int i = 2; i <= n; i++)
            ans &= a[i];
        cout << ans << '\n';
    }

    return 0;
}