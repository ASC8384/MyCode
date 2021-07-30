#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;

int x[233], y[233], d[233][233];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            d[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(max(d[i][k], d[k][j]), d[i][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            d[0][0] = max(d[0][0], d[i][j]);
        }
    }

    cout << (d[0][0] + 1) / 2 << endl;

    return 0;
}

