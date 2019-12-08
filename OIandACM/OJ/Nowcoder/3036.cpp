#include <bits/stdc++.h>
using namespace std;
 
unsigned long long mod(string a,unsigned long long b){
    unsigned long long ret = 0;
    for(char &c : a)
        ret = (10 * ret + c - '0')%b;
    return ret;
}
 
 unsigned long long quick_pow_mod(unsigned long long x, unsigned long long n, unsigned long long mod){
    unsigned long long res = 1;
    while (n > 0){
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
     
    unsigned long long t;
    unsigned long long p;
    string s;
    cin >> t;
    while(t--){
        cin >> p >> s;
        unsigned long long x = mod(s, p - 1);
        cout << quick_pow_mod(p - 1, x, p) << endl;
    }
    return 0;
}