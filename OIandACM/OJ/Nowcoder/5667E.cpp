/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-13 12:27:31
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 1 << 18 | 1;
const int pp   = 998244353;
const int n	   = 1 << 18;
const ll  mod  = 1e9 + 7;

int a[size], b[size], ans[size];
// int n;

void get() {
	for(int i = 0; i < n; i++)
		a[i] *= b[i];
}

void XOR(int *f, int x = 1) {
	for(int o = 2, k = 1; o <= n; o <<= 1, k <<= 1)
		for(int i = 0; i < n; i += o)
			for(int j = 0; j < k; j++)
				f[i + j] += f[i + j + k],
					f[i + j + k] = f[i + j] - f[i + j + k] - f[i + j + k],
							  f[i + j] *= x, f[i + j + k] *= x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// int n;
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int tmp;
		cin >> tmp;
		a[tmp] = b[tmp] = 1;
		ans[1]			= max(tmp, ans[1]);
	}
	// sort(a + 1, a + n + 1);
	// n = 1 << 18;
	XOR(b, 1);
	for(int i = 2; i <= 20; i++) {
		XOR(a, 1);
		get();
		XOR(a, (pp + 1) >> 1);
		for(int j = 0; j < n; j++)
			if(a[j]) {
				a[j]   = 1;
				ans[i] = max(ans[i], j);
			}
	}
	for(int i = 21; i <= t; i++)
		ans[i] = ans[i - 2];
	for(int i = 1; i <= t; i++)
		cout << ans[i] << " ";

	return 0;
}