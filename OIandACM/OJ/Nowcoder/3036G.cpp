#include <bits/stdc++.h>
using namespace std;
 
int a[333];
int c2[343];
int c3[343];
int c4[343];
 
bool cmp(int x, int y){
    return x > y;
}
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    for(int i = 2; i <= 17; i++)
        c2[i] = i * (i - 1) / 2;
    for(int i = 4; i <= 17; i++)
        c4[i] = i * (i - 1) / 2 * (i - 2) / 3 * (i - 3) / 4;
    for(int i = 3; i <= 17; i++)
        c3[i] = i * (i - 1) / 2 * (i - 2) / 3;
 
    string s;
    int t;
    cin >> t;
 
    while(t--){
        cin >> s;
        memset(a, 0, sizeof(a));
        int n = 18;
        for(int i = 0; i < 17; i++){
            if(s[i] == 'J')
                s[i] = 11;
            if(s[i] == 'Q')
                s[i] = 12;
            if(s[i] == 'K')
                s[i] = 13;
            if(s[i] == 'A')
                s[i] = 14;
            if(s[i] == '2')
                s[i] = 15;
            if(s[i] == '0')
                s[i] = 10;
            if('3' <= s[i] && s[i] <= '9')
                s[i] = s[i] - '0';
            a[s[i]]++;
            // if(a[s[i]] == 1)
                // n++;
        }
        //sort(s.begin(), s.end());
        //sort(a, a+333, cmp);
        int ans = 17; // 1
        for(int i = 0; i < n; i++){
            if(a[i] >= 2)
                ans += c2[a[i]];
        } // 2
        for(int i = 0; i < n; i++){
            if(a[i] >= 4)
                ans += c4[a[i]];
        } //  4
        for(int i = 0; i < n; i++){
            if(a[i] >= 3)
                ans += c3[a[i]] * (17 - a[i]);
        }
        for(int i = 0; i < n; i++){
            if(a[i] >= 3)
                for(int j = 0; j < n; j++){
                    if(i != j && a[j] >= 2)
                        ans += c3[a[i]] * c2[a[j]];
                }
        }
        for(int i = 3; i <= 13; i++){
            if(a[i] && a[i+1] && a[i+2] && a[i+3] && a[i+4])
                ans += a[i] * a[i+1] * a[i+2] * a[i+3] * a[i+4];
        }
        cout << ans << endl;
    }
 
    return 0;
}