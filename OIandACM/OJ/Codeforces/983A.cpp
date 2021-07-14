#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll p, q, b;
        cin >> p >> q >> b;
        q /= __gcd(p, q);
        while(true){
            b = __gcd(b, q);
            if(b == 1){
                if(q == 1)
                    cout << "Finite\n";
                else
                    cout << "Infinite\n";
                break;
            }
            while (q % b == 0) {
                q /= b;
            }
        }
    }

    return 0;
}

