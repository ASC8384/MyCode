/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-11-12 22:35:40
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
        ll a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        ll ans = a1 + a2 + a3;
        if(ans % 3){
            cout << 1 << '\n';
        }else{
            cout << 0 << '\n';
        }
    }

    return 0;
}