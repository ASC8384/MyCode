#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 1e6 + 9;
const ll  mod  = 1e9 + 7;

int a[size];
int f[size];
int g[size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
        if(a[i] == 0) {
            a[i] = 1;
        }
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		f[i] = (f[i] + f[i - 1]) % mod;
		g[i] = (g[i] + g[i - 1]) % mod;
		if(a[i] + i > n) {
            ans = (ans + g[i] + f[i]) % mod;
		}else{
            f[i + a[i]] = (f[i + a[i]] + f[i] + g[i]) % mod;
			g[i + a[i]] = (g[i + a[i]] + 1) % mod;
        }
	}
    cout << (ans + f[n]) % mod << '\n';
	return 0;
}