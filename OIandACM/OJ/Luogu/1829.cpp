/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-11 18:47:49
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 1e7 + 9;
const int mod  = 20101009;

int	 mu[size], sum[size], p[size];
bool flag[size];
int	 top = 0;
int	 n, m, k;

void getmu() {
	mu[1] = 1;
	// cout << mu[1] << '\n';
	for(int i = 2; i <= k; i++) {
		// cout << i << endl;
		if(!flag[i])
			p[++top] = i, mu[i] = -1;
		for(int j = 1; j <= top && i * p[j] <= n; ++j) {
			flag[i * p[j]] = 1;
			if(i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = -mu[i];
		}
	}
	for(int i = 1; i <= k; i++)
		mu[i] = (mu[i - 1] + 1LL * i * i % mod * (mu[i] + mod)) % mod;
}

int f(int x, int y) {
	return (1LL * x * (x + 1) / 2 % mod) * (1LL * y * (y + 1) / 2 % mod) % mod;
}

int func(int x, int y) {
	int ret = 0;
	int k	= min(x, y);
	for(int i = 1, j; i <= k; i = j + 1) {
		j	= min(x / (x / i), y / (y / i));
		ret = (ret + 1LL * (mu[j] - mu[i - 1] + mod) * f(x / i, y / i) % mod) % mod;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// cout << mu[1] << endl;
	cin >> n >> m;
	k = min(n, m);
	// cout << mu[1] << endl;
	getmu();
	int ans = 0;
	for(int i = 1, j; i <= k; i = j + 1) {
		// cout << i << endl;
		j	= min(n / (n / i), m / (m / i));
		ans = (ans + 1LL * (j - i + 1) * (i + j) / 2 % mod * func(n / i, m / i) % mod) % mod;
	}
	cout << ans << endl;

	return 0;
}