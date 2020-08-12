/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-10 14:11:06
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 5e4 + 9;
const ll  mod  = 1e9 + 7;

int	 mu[size], sum[size], p[size];
bool flag[size];
int	 top = 0;

void getmu(int n) {
	mu[1] = 1;
	for(int i = 2; i <= n; ++i) {
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
	for(int i = 1; i <= n; ++i)
		mu[i] += mu[i - 1];
}

int k;

int calc(int n, int m) {
	int ans = 0;
	int cnt = min(n, m);
	for(int i = 1, j; i <= cnt; i = j + 1) {
		j = min(n / (n / i), m / (m / i));
		ans += (mu[j] - mu[i - 1]) * (n / (i * k)) * (m / (i * k));
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	getmu(size);
	while(t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d >> k;
		cout << calc(b, d) - calc(b, c - 1) - calc(a - 1, d) + calc(a - 1, c - 1) << '\n';
	}

	return 0;
}