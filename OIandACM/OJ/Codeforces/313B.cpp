#include <bits/stdc++.h>
using namespace std;

int ans[100009];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    int m, a, b;
    cin >> s >> m;
    s = " " + s;
    int ll = s.size();
    // if(s[1] == s[2]) ans[1]++;
    for(int i = 1; i < ll; i++){
        if(s[i] == s[i-1])
            ans[i] = ans[i-1] + 1;
        else
            ans[i] = ans[i-1];
    }

    while(m--){
        cin >> a >> b;
        cout << ans[b] - ans[a] << endl;
    }

    return 0;
}