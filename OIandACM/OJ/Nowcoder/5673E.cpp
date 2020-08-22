/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-03 14:37:34
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 1e5 + 8;
const ll  mod  = 1e9 + 7;

ll add[300000];
ll sum[300000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for(int m = 3; m < size; m++)
		for(int a = m; a < size; a += m) { // a = a * m
			add[a + 3]++;
			add[a + m + 1]--;
			add[a + m + 2]--;
			add[a + (m << 1)]++;
		}
	for(int i = 3; i < size; i++)
		add[i] += add[i - 2];
	for(int i = 1; i < size; i++)
		add[i] += add[i - 1];
	sum[1] = add[1];
	for(int i = 2; i < size; i++)
		sum[i] = sum[i - 1] + add[i];

	int T = 1;
	cin >> T;
	// while(t--) {
	for(int t = 1; t <= T; t++) {
		int le, ri;
		cin >> le >> ri;
		cout << "Case #" << t << ": " << sum[ri] - sum[le - 1] << '\n';
	}

	return 0;
}