/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-30 13:09:42
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

typedef struct str {
	int v, t;
} jqgz;

jqgz a[size];

int f[size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int minn = 0x7fffffff;
		for(int i = 1; i <= n; i++) {
			cin >> a[i].v;
			cin >> a[i].t;
			if((100 - a[i].v) % a[i].v == 0)
				f[i] = a[i].t * ((100 - a[i].v) / a[i].v);
			else
				f[i] = a[i].t * (1 + (100 - a[i].v) / a[i].v);
		}
		for(int i = 1; i <= n; i++)
			minn = min(minn, f[i]);
		double ans	= 0.0;
		int	   loss = 0;
		for(int i = 1; i <= n; i++) {
			if(minn == f[i])
				ans += 0.5;
			else
				ans++;
		}
		cout << 1.0 * (ans) / (n) << '\n';
	}

	return 0;
}