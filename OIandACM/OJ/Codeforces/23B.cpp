#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << (n <= 2 ? 0 : n - 2) << '\n';
    }

    return 0;
}

