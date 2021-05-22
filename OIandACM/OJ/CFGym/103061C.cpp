#include <bits/stdc++.h>
using namespace::std;

std::stack<int> s;

int le[112345], ri[112345];
int ans[112345];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        ri[x] = y;
        le[y] = x;
    }
    for(int i = n; i; i--){
        s.push(i);
    }
    for(int i = 1; i <= n; i++){
        if(le[i]){
            ans[i] = ans[le[i]];
            if(!ri[i])
                s.push(ans[i]);
        }else{
            ans[i] = s.top();
            if(ri[i])
                s.pop();
        }
    }
    
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }

    return 0;
}
// 10 6 1 3 3 7 2 10 4 6 6 9 5 8
