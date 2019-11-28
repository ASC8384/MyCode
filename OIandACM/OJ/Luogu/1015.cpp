#include <bits/stdc++.h>
using namespace std;

int val(char c){
    if('0' <= c && c <= '9')
        return c - '0';
    else
        return c - 'A' + 10;
}

int main()
{
    vector <int> a, b;
    string s;
    //string a, b;
    int n, step;
    //cin >> n >> a;
    cin >> n >> s;
    int ll = s.size();
    for(int i = 0; i < ll; i++)
        a.push_back(val(s[i]));
    b = a;
    reverse(b.begin(), b.end());
    if(a == b)
        printf("STEP=0");
    else{
        int ans;
        for(ans = 1; ans <= 30; ans++){
            int ll = a.size();
            for(int i = 0; i < ll; i++){
                a[i] += b[i];
                if(a[i] >= n){
                    if(i != ll - 1)
                        a[i + 1] += a[i]/n;
                    else
                        if(a[i] >= n)
                            a.push_back(a[i]/n);
                    a[i] %= n;
                }
            }
            b = a;
            reverse(b.begin(), b.end());
            if(a == b)
                break;
        }
        if(ans <= 30)
            printf("STEP=%d", ans);
        else
            printf("Impossible!");
    }

    return 0;
}