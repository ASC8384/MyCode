#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2509;
const ll  mod  = 998244353;

ll inv[size], fac[size], finv[size];
ll dp[size][size], g[size][size], C[size][size];

ll c(ll n, ll m) {
	if(m < 0 || m > n)
		return 0;
	return fac[n] * 1ll * finv[n - m] % mod * finv[m] % mod;
}

ll dfs(ll a, ll b) {
	if(a == 1)
		return 0;
	if(dp[a][b] == -1) {
		if(b <= a - 1) {
			dp[a][b] = (g[b][a] - g[b - 1][a] + mod) % mod;
		} else {
			dp[a][b] = dfs(a, b - a + 1);
			for(int i = 1; i <= a - 1; i++)
				dp[a][b] = (dp[a][b] + C[a][i] * g[a - 1][i] % mod * dfs(a - i, b - a + 1) % mod) % mod;
		}
	}
	return dp[a][b];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, x;
	cin >> n >> x;

	inv[1]	= 1;
	g[0][0] = 1;
	for(int i = 2; i < size - 2; i++) {
		inv[i] = (mod - mod / i) * 1ll * inv[mod % i] % mod;
	}
	fac[0] = finv[0] = 1;
	for(int i = 1; i < size - 2; i++) {
		g[i][0] = 1;
		fac[i]	= fac[i - 1] * 1ll * i % mod;
		finv[i] = finv[i - 1] * 1ll * inv[i] % mod;
	}
	for(ll i = 1; i < size - 2; i++)
		for(ll j = 1; j < size - 2; j++) {
			g[i][j] = g[i][j - 1] * i % mod;
			C[i][j] = c(i, j);
		}
	memset(dp, -1, sizeof(dp));
	ll ans = 0;
	if(n < x) {
		;
	} else if(n == x) {
		;
	} else {
		;
	}
	for(int i = 1; i <= x; i++)
		ans = (ans + dfs(n, i)) % mod;
	cout << ans << '\n';

	return 0;
}