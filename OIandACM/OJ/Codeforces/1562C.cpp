/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-08-26 22:36:29
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

ll sum[size];
ll a, b, c, d;

void prt() {
	if(sum[d] - sum[c - 1] == 0) {
		swap(a, c);
		swap(b, d);
	}
	cout << a << " " << b << " " << c << " " << d << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		ll	   n;
		string s;
		cin >> n;
		cin >> s;
		s = " " + s;
		a = 1;
		b = n - 1;
		c = a + 1;
		d = b + 1;
		for(ll i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + (s[i] == '1');
		for(ll i = 1; i <= n; i++) {
			if(s[i] != '0')
				continue;
			if(i > n / 2) {
				a = 1;
				b = i;
				c = 1;
				d = i - 1;
			} else {
				a = i;
				b = n;
				c = i + 1;
				d = n;
			}
			break;
		}
		prt();
	}

	return 0;
}