#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

ll ans[1000000+9];
bool isp[1000000+9];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll maxx = 1000000+8;
    for(ll i = 2; i < maxx; i++){
        if(!isp[i]){
            ans[i] = i;
            for(ll j = i+i; j < maxx; j+=i)
                isp[j] = true;
            for(ll j = i*i; j < maxx; j*=i)
                ans[j] = i;
        }
        if(ans[i] == 0)
            ans[i] = 1;
    }
    for(int i = 4; i < maxx; i++)
        ans[i] += ans[i-1];
    int x;
    while (cin >> x) {
        cout << ans[x] << '\n';
    }

    return 0;
}

