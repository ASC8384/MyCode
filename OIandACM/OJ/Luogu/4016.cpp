/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-05 23:36:49
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

ll a[size], s[size], sum, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sum = sum / n;
	for(int i = 1; i <= n; i++) {
		a[i] -= sum;
		s[i] = a[i] + s[i - 1];
	}
	sort(s + 1, s + n + 1);
	sum	   = 0;
	ll mid = s[n / 2 + 1];
	for(int i = 1; i <= n; i++)
		sum += abs(mid - s[i]);
	cout << sum << endl;

	return 0;
}