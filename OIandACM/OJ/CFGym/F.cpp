#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, p, q;
ll m, b, c, t;

struct LL{
    ll a;
    int id;
}a[31234567];

bool cmp(LL x, LL y){
    // if(x.a == y.a)
    //     return x.id < y.id;
    return x.a < y.a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p >> q;
    cin >> m >> b >> c >> t;
    for(int i = 1; i <= m; i++){
        cin >> a[i].a;
        a[i].id = i;
    }

    ll top = min(n, 323456ll);
    for(int i = m+1; i <= n; i++){
        a[i].a = ((b * a[i-1].a + c) % t) + 1ll;
        a[i].id = i;
        // if(i <= 20)
        // cout << i << ' ' << a[i].a << '\n';
    }
    // cout << "st\n";

    sort(a+1, a+top+1, cmp);
    bool flg = true;

    // double le = 1.0 * p / (1.0 * q);
    // double ri = 1.0 * q / (1.0 * p);

    for(int i = 2; i <= top; i++){
        // cout << a[i - 1].a << ' ';
        if((p * a[i].a <= q * a[i-1].a) && (a[i-1].a * p <= a[i].a * q)){
        // double tmp = (1.0*a[i-1].a) / (1.0*a[i].a);
        // if(le <= tmp && tmp <= ri){
            if(a[i-1].id >= a[i].id)
                cout << a[i].id << ' ' << a[i-1].id << '\n';
            else
                cout << a[i-1].id << ' ' << a[i].id << '\n';
            // cout << a[i-1].a << ' ' << a[i].a << '\n';
            flg = false;
            break;
        }
        // if(p * a[i-1].a <= q * a[i].a && a[i].a * p <= a[i-1].a * q){
        //     cout << a[i].id << ' ' << a[i-1].id << '\n';
        //     cout << a[i].a << ' ' << a[i-1].a << '\n';
        //     flg = false;
        //     break;
        // }
    }
    if(flg){
        cout << -1 << '\n';
    }

    return 0;
}

