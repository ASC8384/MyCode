/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-10-29 22:36:32
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
        string s;
        cin >> s;
        int len = s.size();
        if(s[0] == s[len - 1]) {
            cout << s << '\n';
        }else{
            cout << s[len-1] << s.substr(1) << '\n';
        }
    }

    return 0;
}