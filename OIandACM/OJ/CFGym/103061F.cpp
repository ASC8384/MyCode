#include <bits/stdc++.h>
using namespace std;

double le[112345], ri[112345], tt[112345];

int main()
{
    int n;
    double m;
    scanf("%d%lf", &n, &m);

    for(int i = 1; i <= n; i++){
        scanf("%lf%lf", &le[i], &ri[i]);
        tt[i] = ri[i] - le[i];
    }
    double minn = le[1];
    double maxx = ri[n];
    for(int i = 1; i <= n; i++){
        minn = min(le[i], minn);
        maxx = max(ri[i], maxx);
    }

    double ans = (minn + maxx) / 2.0;
    double ll = minn;
    double rr = maxx;
    double now;
    for(int i = 1; rr - ll >= 1e-6; i++){
        ans = (ll + rr) / 2.0;
        now = 0;
        for(int j = 1; j <= n; j++){
            if(ans >= ri[j]){
                now += 1.0;
            }else if(ans <= le[j]){
                continue;
            }else{
                now += (ans - le[j])/(tt[j]);
           }
        }
        if(now < m){
            ll = ans;
        }else{
            rr = ans;
        }
    }
    printf("%.10lf\n", ans);
    // printf("%lf\n", now);

    return 0;
}
/*

3 2

1.5 3.0

2.4 5.0

1.919810 1.919810
*/

