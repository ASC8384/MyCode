#include <bits/stdc++.h>
#include <cstdio>
using namespace::std;

int a[112345];
// int b[24324];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    // for(int i = 1; i <= n; i++){
    //     cin >> a[i];
    // }
    for(int i = 1; i <= n; i++){
        cout << i << ' ';
    }
    cout << '\n';
    for(int i = 1; i <= n; i++){
        cout << 1 << ' ';
    }
    cout << '\n';

    return 0;
}

