#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
    int t;
    int n, k;
    cin >> t;

    while(t--){
        cin >> n >> k;
        if(k == 0){
            cout << "Yes" << endl;
        }else{
            if(k == 1){
                if(n & 1){
                    cout << "Yes" << endl;
                }else{
                    cout << "No" << endl;
                }
            }else{
                if((n+1) % k){
                    cout << "No" << endl;
                }else{
                    cout << "Yes" << endl;
                }
            }
            // int tmp = 1;
            // for(int i = 0; i < n+n; i++){
            //     tmp += 1+k;
            //     if(tmp > n)
            //         tmp -= n;
            //     cout << tmp << " ";
            // }
            // cout << endl;
            // tmp = 1+n;
            // for(int i = 0; i < n+n; i++){
            //     tmp -= 1+k;
            //     if(tmp < 1)
            //         tmp += n;
            //     cout << tmp << " ";
            // }
            // cout << endl;
        }
    }
    return 0;
}

// 1 1+k 1+2k 1+ak 1+ak+k-n
// n+1-k n+1-2k