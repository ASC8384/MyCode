#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 7;

struct mat {
    // n 行 m 列
    ll  a[5][5];
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

    ll a, b, n;
    while (cin >> a >> b >> n, a|b|n) {
        if(n <= 2){
            cout << 1 << '\n';
            continue;
        }
        mat x(2, 2);
        mat y(2, 1);
        x.a[1][1] = a;
        x.a[1][2] = b;
        x.a[2][1] = 1;
        y.a[1][1] = 1;
        y.a[2][1] = 1;
        n -= 2;
        cout << ((x^n)*y).a[1][1] << '\n';
    }

    return 0;
}

