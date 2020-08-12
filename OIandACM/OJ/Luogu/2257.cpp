/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-15 23:26:24
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 1e7 + 9;
const ll  mod  = 1e9 + 7;

int	 mu[size], p[size], tmp[size];
bool flag[size];
int	 top = 0;
int	 sum[size];
int	 n, m, k;

void getmu() {
	mu[1] = 1;
	// cout << mu[1] << '\n';
	int k = size;
	for(int i = 2; i <= k; i++) {
		// cout << i << endl;
		if(!flag[i])
			p[++top] = i, mu[i] = -1;
		for(int j = 1; j <= top && i * p[j] <= k; j++) {
			flag[i * p[j]] = 1;
			if(i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = -mu[i];
		}
	}
	for(int i = 1; i <= top; i++)
		for(int j = 1; j * p[i] <= k; j++)
			tmp[j * p[i]] += mu[j];
	for(int i = 1; i <= k; i++)
		sum[i] = sum[i - 1] + tmp[i];
	// mu[i] = mu[i - 1] + mu[i];
	// mu[i] = (mu[i - 1] + 1LL * i * i % mod * (mu[i] + mod)) % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	getmu();
	ll t = 1;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		int k	= min(n, m);
		ll	ans = 0;
		for(int i = 1, j; i <= k; i = j + 1) {
			j = min(n / (n / i), m / (m / i));
			ans += 1LL * (n / i) * (m / i) * (sum[j] - sum[i - 1]);
		}
		cout << ans << '\n';
	}

	return 0;
}