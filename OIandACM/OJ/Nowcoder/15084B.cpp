/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-04-17 12:34:37
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

string s;
bool flg;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    int len = s.size();
    int n = len / 2;
    flg = true;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == s[len - i - 1]){
            ;
        }else{
            ans++;
        }
    }
    if(ans)
        flg = false;

    int q;
    cin >> q;

    while(q--){
        // cout << ans << '\n';
        int x;
        char c;
        cin >> x >> c;
        x--;
        int y = len - x - 1;
        if(x != y){
			if(s[x] != s[y] && s[y] == c)
                ans--;
            if(s[x] == s[y] && s[x] != c)
                ans++;
        }
        // s[x-1] = c;
        // string tmp = (ans <= 0)?"Yes":"No";
        s[x] = c;
        if(ans){
            cout << "No\n";
        }else{
            cout << "Yes" << '\n';
        }
    }

    return 0;
}