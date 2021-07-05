/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-05-20 22:36:20
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

ll a[60];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	a[0] = 1;
	for(int i = 1; i <= 56; i++)
		a[i] = a[i - 1] << 1;

	int t = 1;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		ll top = 0;
		while(a[top] <= n)
			top++;
		cout <<  a[top - 1] - 1 << '\n';
	}

	return 0;
}