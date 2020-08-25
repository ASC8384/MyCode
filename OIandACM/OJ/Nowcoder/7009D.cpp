/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-25 20:18:59
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 1e6 + 9;
const ll  mod  = 1e9 + 7;

bool ff[size];
int	 n;
int	 mm;
int	 ans = 0;

void dfs(int j, int x, int oh) {
	// int m = min(oh, mm);
	for(int i = j + 1; i <= oh; i++) {
		if(n % i == 0) {
			cout << i << " " << n / i << '\n';
			ans = min(ans, x + n / i + i);
			dfs(i, x + i, n / i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	mm	  = sqrt(n);
	ans	  = n + 1;
	ff[1] = ff[n] = true;
	dfs(1, 0, n - 1);
	cout << ans << endl;

	return 0;
}