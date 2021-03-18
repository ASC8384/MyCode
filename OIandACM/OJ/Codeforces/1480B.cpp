/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-02-07 22:44:21
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll size = 2e5 + 9;
const ll mod  = 1e9 + 7;

struct LL {
	ll a, b;
} x[size];

// ll a[size], b[size];
ll A, B, n, y;

bool cmp(LL xx, LL yy) {
	// if(xx.a == yy.a)
	// 	return xx.b < yy.b;
	return xx.a < yy.a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t = 1;
	cin >> t;
	while(t--) {
		cin >> A >> B >> n;
		for(ll i = 1; i <= n; i++) {
			cin >> x[i].a;
		}
		for(ll i = 1; i <= n; i++) {
			cin >> x[i].b;
		}
		bool is = false;
		sort(x + 1, x + n + 1, cmp);
		for(ll i = 1; i <= n; i++) {
			ll cnt = x[i].b / A;
			if(x[i].b % A)
				cnt++;
			if(B > x[i].a * (cnt - 1)) {
				x[i].b -= A * cnt;
				B -= x[i].a * cnt;
			}
		}
		for(ll i = 1; i <= n; i++) {
			if(x[i].b > 0) {
				is = true;
				// break;
			}
		}
		if(!is) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}