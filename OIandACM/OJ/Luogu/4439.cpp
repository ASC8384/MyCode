#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char a, b;
    int ans = 2;
    if(n == 1)
        cout << ans;
    else{
        cin >> a;
        for(int i = 1; i < n; i++){
            cin >> b;
            if(a != b){
                ans++;
                a = b;
            }
        }
        cout << ans;
    }
    return 0;
}