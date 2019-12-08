#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    unsigned long long n, k;
    cin >> n >> k;
    string str, s;
    cin >> str;
 
    s = str;
    reverse(s.begin(), s.end());
    str += s;
    n <<= 1;
    k %= n;
    if(k == 0)
        k += n;
    cout << str[k-1];
 
    return 0;
}