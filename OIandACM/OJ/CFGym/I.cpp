#include <bits/stdc++.h>
#include <vector>
using namespace::std;
typedef long long ll;

int a[23333];

struct LL{
    ll pos;
    ll val;
};

vector<LL> v[23333];

ll dp[2333][2333];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++){
        ll ho = a[i];
        ll an = a[i];
        ll now = ho ^ an;
        v[i].push_back({i, now});
        for(int j = i - 1; j >= 1; j--){
            ho |= a[j];
            an &= a[j];
            if(now < (ho ^ an)){
                now = ho ^ an;
                v[i].push_back({j, now});
            }
        }
    }

    for(int kk = 1; kk <= k; kk++){
        for(int i = kk; i <= n; i++){
            for(auto j:v[i]){
                ll pos = j.pos;
                if(pos >= kk)
                    dp[i][kk] = max(dp[i][kk], dp[pos - 1][kk -1] + j.val);
            }
        }
    }
    cout << dp[n][k] << endl;

    return 0;
}

