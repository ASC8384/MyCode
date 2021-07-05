#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

unordered_map<ll, ll>m;
ll a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        m.clear();
        ll ans = 0;
        for(ll i = 1; i <= n; i++){
            cin >> a;
			ans += m[a] * (n - i + 1);
			m[a] += i;
        }
        cout << ans << '\n';
    }

    return 0;
}
