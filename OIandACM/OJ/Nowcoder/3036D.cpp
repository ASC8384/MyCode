#include <bits/stdc++.h>
using namespace std;
 
unsigned long long a[233];
int ll, p, rr;
int tmp[233];
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
     
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    while(m--){
        cin >> p >> ll >> rr;
        if(p == 1){
            for(int i = ll; i <= rr; i++)
                a[i] = a[i] * 251 % 996 * 404 * 123;
        }else if(p == 2){
            // memset(ans, 0, sizeof(ans));
            for(int i = ll; i <= rr; i++)
                tmp[i] = a[i];
            sort(tmp + ll, tmp + rr + 1);
            int tt = 1;
            int ans = 0;
            for(int i = ll; i <= rr; i++){
                if(tmp[i] == tmp[i+1])
                    tt++;
                else{
                    if(tt > ans)
                        ans = tt;
                    tt = 1;
                }
            }
            cout << ans << endl;
                // ans[a[i]]++;
            // sort(ans, ans)
        }
    }
    return 0;
}