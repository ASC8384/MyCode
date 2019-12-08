#include <bits/stdc++.h>
using namespace std;
 
int a[233333];
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ll = s.size();
        int ans = 0;
        int n = 0;
        int y = 0;
        for(int i = 0; i < ll; i++){
            if(s[i] == 'Y' || s[i] == 'y'){
                y++;
                // ans++;
            }
            else if(s[i] == 'N' || s[i] == 'n'){
                n++;
                // ans++;
            }
        }
        if(y >= (ll >> 1))
            cout << "pmznb" << endl;
        else if(n >= (ll >> 1))
            cout << "lyrnb" << endl;
        else
            cout << "wsdd" << endl;
    }
    return 0;
}