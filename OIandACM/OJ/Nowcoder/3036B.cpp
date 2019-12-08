#include <bits/stdc++.h>
using namespace std;
 
int a[233333];
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    char a, b, c;
    cin >> a >> b >> c;
    if(c == 'B'){
        if(a == 'J' || b == 'J')
            cout << "pmznb" << endl;
        else
            cout << "lyrnb" << endl;
    }
    if(c == 'J'){
        if(a == 'S' || b == 'S')
            cout << "pmznb" << endl;
        else
            cout << "lyrnb" << endl;
    }
    if(c == 'S'){
        if(a == 'B' || b == 'B')
            cout << "pmznb" << endl;
        else
            cout << "lyrnb" << endl;
    }
 
    return 0;
}