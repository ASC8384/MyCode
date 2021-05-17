#include <bits/stdc++.h>
#include <cstdio>
using namespace::std;

int a[23];
int b[24324];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ans = 0;

    for(int i = 1; i <= 14; i++){
        cin >> a[i];
    }
    // sort(a+1, a+15);
    bool flg = false;
    bool fff = true;
    for(int i = 1; i <= 14; i++){
        if(a[i] <= 13){
            if(b[a[i]] == 0){
                b[a[i]] = 1;
                ans++;
            }else{
                fff = false;
            }
        }else{
            flg = true;
        }
    }
    if(flg && fff)
        cout << 14 - ans << '\n';
    else
        cout << 13 - ans << '\n';

    return 0;
}

