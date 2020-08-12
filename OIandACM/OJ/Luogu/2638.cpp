/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-06-28 10:32:43
*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const int size = 508 + 9;
const ll  mod  = 1e9 + 7;

ll c[size][size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, a, b;
	cin >> n >> a >> b;
	for(int i = 0; i <= 66; i++)
		c[i][0] = c[i][i] = 1;
	for(int i = 2; i <= 66; i++)
		for(int j = 1; j <= n; j++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	ll ansa = 0;
	ll ansb = 0;
	for(int i = 0; i <= a; i++)
		ansa += c[n][i] * c[a][i];
	for(int i = 0; i <= b; i++)
		ansb += c[n][i] * c[b][i];
	ll ans = ansa * ansb;
	cout << ans << endl;
	return 0;
}