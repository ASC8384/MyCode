#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 2147493647;

struct mat {
    // n 行 m 列
    ll  a[16][16];
    int n, m;
    mat(int x = 0, int y = 0) {
        this->n = x;
        this->m = y;
        memset(this->a, 0, sizeof(this->a));
    }
    void prt() {
        cout << n << ' ' << m << '\n';
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    void init() { memset(a, 0, sizeof(a)); }
    mat  operator*(const mat &x) const { // 矩阵乘法
         mat ret;
         ret.n = n;
         ret.m = x.m;
         memset(ret.a, 0, sizeof(ret.a));
         for(int i = 1; i <= ret.n; i++)
             for(int j = 1; j <= ret.m; j++)
                 for(int k = 1; k <= m; k++)
                     ret.a[i][j] = (ret.a[i][j] + a[i][k] * x.a[k][j] % mod) % mod;
         return ret;
    }
    friend mat operator^(mat &y, ll t) { // 矩阵快速幂
        mat x   = y;
        mat ret = mat(x.n, x.n);
        memset(ret.a, 0, sizeof(ret.a));
        for(int i = 1; i <= x.n; i++) {
            ret.a[i][i] = 1;
        }
        while(t) {
            if(t & 1)
                ret = ret * x;
            x = x * x;
            t >>= 1;
        }
        return ret;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        ll  a, b, n;
        mat x(7, 7);
        mat y(7, 1);
        // cin >> a >> b >> n;
        cin >> n >> a >> b;
        if(n == 1){
            cout << a << '\n';
            continue;
        }else if(n == 2){
            cout << b << '\n';
            continue;
        }
        x.a[1][1] = x.a[1][3] = x.a[1][7] = 1;
        x.a[1][4] = x.a[1][6] = 4;
        x.a[3][3] = x.a[3][7] = 1;
        x.a[3][4] = x.a[3][6] = 4;
        x.a[4][4] = x.a[4][7] = 1;
        x.a[4][5] = x.a[4][6] = 3;
        x.a[5][5] = x.a[5][7] = 1;
        x.a[6][6] = x.a[6][7] = 1;
        x.a[1][5] = 6;
        x.a[1][2] = 2;
        x.a[7][7] = 1;
        x.a[3][5] = 6;
        x.a[5][6] = 2;
        x.a[2][1] = 1;
        x = (x ^ (n - 2));
        ll ans = x.a[1][1] * b % mod;
        ans    = (ans + x.a[1][2] * a % mod) % mod;
        ans    = (ans + x.a[1][3] * 16 % mod) % mod;
        ans    = (ans + x.a[1][4] * 8 % mod) % mod;
        ans    = (ans + x.a[1][5] * 4 % mod) % mod;
        ans    = (ans + x.a[1][6] * 2 % mod) % mod;
        ans    = (ans + x.a[1][7]) % mod;
        cout << ans << '\n';
    }

    return 0;
}
