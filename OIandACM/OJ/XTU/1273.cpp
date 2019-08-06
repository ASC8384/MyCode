#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int k, n;
    int a, b, c, d;
    set<int> ans;
    //bool f;
    int x, y, z;
    int size;
    set<int>::iterator it;
    //cin >> k;
    scanf("%d", &k);

    while(k--){
        ans.clear();
        //cin >> n;
        scanf("%d", &n);

        while(n--){
            //cin >> a;
            scanf("%d", &a);
            ans.insert(a);
        }
        size = ans.size();
        if(size <= 3)
            cout << "Yes" << endl;
        else if(size > 4)
            cout << "No" << endl;
        else{
            it = ans.begin();
            a = *it; it++;
            b = *it; it++;
            c = *it; it++;
            d = *it;
            x = b - a;
            y = c - a;
            z = d - a;
            if(x == y-z || x == y+z || x == z-y ||
                y == x+z || y == x-z || y == z-x ||
                z == x+y || z == x-y || z == y-x)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}