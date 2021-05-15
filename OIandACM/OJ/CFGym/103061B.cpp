#include <bits/stdc++.h>
using namespace::std;

string s;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> s;

    int n = s.size();

    bool flg = true;
    for(int i = 1; i < n; i++){
        if(s[i] != s[0])
            flg = false;
    }
    if(flg){
        cout << "-1\n";
    }else{
        cout << "2\n";
    }

    return 0;
}

