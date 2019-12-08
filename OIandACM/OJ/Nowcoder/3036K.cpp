#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    int t;
    cin >> t;
 
    while(t--){
        unsigned long long p;
        cin >> p;
        if((p-1) % 3)
            cout << "NO" << endl;
        else{
            p = (p-1) / 3;
            bool f = 0;
            unsigned long long t = sqrt(p);
            for(unsigned long long i = 1; i <= t; i++)
                if(i * (i+1) == p){
                    f = 1;
                    break;
                }
            if(f)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
 
    return 0;
}