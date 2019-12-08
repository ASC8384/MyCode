#include <bits/stdc++.h>
using namespace std;
 
int a[233333];
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        cout << a[n-1] << endl;
    }
    return 0;
}