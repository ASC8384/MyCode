#include <bits/stdc++.h>
using namespace::std;

class MatrixWithMod
{
    typedef int64_t ll;
    public:
        ll mod;
        ll row, col;
        vector<vector<int>> Mat;
        ll exgcd(ll a, ll b, ll &x, ll &y){
            if(b == 0){
                x = 1;
                y = 0;
                return a;
            }
            ll ret, tmp;
            ret = exgcd(b, a%b, x, y);
            tmp = x;
            x = y;
            y = tmp - a / b * y;
            return ret;
        }
        ll qpow(ll x, ll t){
            ll ret = 1;
            while(t){
                if(t & 1)
                    ret = ret * x % mod;
                x = x * x % mod;
                t >>= 1;
            }
            return ret;
        }
        vector<int> guess(){ // 高斯约旦消元法
            row = Mat.size();
            col = Mat[0].size() - 1;
            vector<int> ret(col, -1);
            vector<int> vis(col, -1);
            for (int n(0), m(0); m < col && n < row; m++) {
                int pos = n; // 选主元
                for (int i(n); i < row; i++){ // 选最大系数
                    if (Mat[i][m] > Mat[pos][m])
                        pos = i;
                }
                if (Mat[pos][m] == 0)
                    continue; 
                for (int i(m); i<=col; i++) // 交换
                    swap(Mat[pos][i], Mat[n][i]);
                vis[m] = n; // 记录解的位置
                for (int i(0); i < row; i++){ // 消去其它方程中主元系数
                    if (i != n) {
                        ll tmp = Mat[i][m] * qpow(Mat[n][m], mod - 2) % mod;
                        for (int j(m); j <= col; j++)
                            Mat[i][j] = (Mat[i][j] - Mat[n][j] * tmp % mod + mod) % mod;
                    }
                }    
                n++;
            }
            for (int i(0); i < col; i++){ // 除以该项系数
                if(vis[i] != -1)
                    ret[i] = Mat[vis[i]][col] * qpow(Mat[vis[i]][i], mod - 2) % mod;
            }
            return ret;
        }
        MatrixWithMod(vector<vector<int>> mat): Mat(mat){};
        ~MatrixWithMod(){};
        MatrixWithMod(){};
};

int calc(int x, int mod, vector<int> ans){
    int ret = 0;
    int now = 1;
    for(auto i : ans){
        ret = (ret + (long long)now * i % mod) % mod;
        now = ((long long)now * x) % mod;
    }
    return ret;
}

int main (int argc, char *argv[])
{
    int k = 11;
    vector<int>f;
    f.resize(k+1);
    vector<vector<int>> a(k, vector<int>(k + 1));
    for(int i(0); i < k; i++){
        cout << "? " << i << endl;
        cout.flush();
        a[i][0] = 1;
        for(int j(1); j < k; j++)
            a[i][j] = a[i][j-1] * i % ((int)1e6+3);
        cin >> a[i][k];
    }
    MatrixWithMod solver(a);
    solver.mod = 1e6+3;
    vector<int> ans = solver.guess(); // 模意义下的高斯消元

    int flag = -1;
    for(int x = 0; x < solver.mod; x++){
        if(calc(x, solver.mod, ans) == 0){
            flag = x;
            break;
        }
    }
    cout<<"! "<< flag << endl;
    return 0;
}
