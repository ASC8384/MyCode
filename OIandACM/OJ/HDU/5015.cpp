#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// ll mod = 1e9+7;
const ll mod = 10000007;

struct mat {
    // n 行 m 列
    ll  a[23][23];
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

    int n, m;
    while (cin >> n >> m ) {
        mat a(n+2, 1);
        mat b(n+2, n+2);
        a.a[n+2][1] = 3;
        a.a[1][1] = 23;
        for(int i = 2; i <= n + 1; i++) {
            cin >> a.a[i][1];
        }
        for(int i = 1; i <= n + 1; i++)
            b.a[i][1] = 10;
        for(int i = 1; i <= n + 2; i++)
            b.a[i][n+2] = 1;
        for(int i = 2; i <= n + 1; i++)
            for(int j = 2; j <= i; j++)
                b.a[i][j] = 1;
        cout << ((b^m)*a).a[n+1][1] << '\n';
    }

    return 0;
}

