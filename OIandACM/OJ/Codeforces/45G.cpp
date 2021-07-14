#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

ll ans[23333];
ll n;

bool is(ll x){
    if(x == 1)
        return false;
    for(ll i = 2; i*i <= x; i++)
        if(x % i == 0)
            return false;
    return true;
}

void solve(ll sum){
    for(int i = 2; i <= n; i++){
        if(ans[i] == 1 && is(i) && is(sum - i)){
            ans[i] = 2;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n) {
        ll sum = n * (n + 1) / 2;
        for(int i = 1; i <= n; i++)
            ans[i] = 1;
        if(is(sum))
            ;
        else if(sum & 1){
            if(is(sum - 2))
                ans[2] = 2;
            else{
                ans[3] = 3;
                solve(sum - 3);
            }
        }else {
            solve(sum);
        }

        for(int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}

