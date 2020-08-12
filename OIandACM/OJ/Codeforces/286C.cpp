/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-17 20:37:48
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 1000000 + 9;
const ll  mod  = 1e9 + 7;

bool q[size];
int	 p[size], ans[size];
int	 stk[size];
int	 top = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, t;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> p[i];
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int tmp;
		cin >> tmp;
		q[tmp] = true;
	}
	for(int i = n; i >= 1; i--) {
		if(p[i] != stk[top] || q[i]) {
			stk[++top] = p[i];
			ans[i]	   = -1;
		} else {
			top--;
			ans[i] = 1;
		}
	}
	if(top) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
		for(int i = 1; i <= n; i++)
			cout << ans[i] * p[i] << ' ';
	}
	return 0;
}