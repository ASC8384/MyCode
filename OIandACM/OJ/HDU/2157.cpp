#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int mod = 1000;

struct mat {
    // n 行 m 列
    int a[25][25];
    int n, m;
    mat(int x = 0, int y = 0) {
        this->n = x;
        this->m = y;
        memset(this->a, 0, sizeof(this->a));
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
                     ret.a[i][j] = (ret.a[i][j] + a[i][k] * x.a[k][j]) % mod;
         return ret;
    }
    friend mat operator^(mat &y, int t) { // 矩阵快速幂
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
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int n, m;
    // while(cin >> n >> m){
    while (scanf("%d%d", &n, &m) == 2) {
        if(n == 0 && m == 0)
            break;
        mat a(n, n);
        for(int i = 1; i <= m; i++){
            int s, t;
            // cin >> s >> t;
            scanf("%d%d", &s, &t);
            a.a[s + 1][t + 1] = 1;
        }
        int T;
        // cin >> T;
        scanf("%d", &T);
        while(T--){
            int x, y, k;
            // cin >> x >> y >> k;
            // cout << (a^k).a[x + 1][y + 1] << '\n';
            scanf("%d%d%d", &x, &y, &k);
            printf("%d\n", (a^k).a[x + 1][y + 1]);
        }
    }

    return 0;
}

