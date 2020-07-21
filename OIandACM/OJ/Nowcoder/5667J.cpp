/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-20 09:36:19
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 1e5 + 9;
const ll  mod  = 1e9 + 7;

int n, k;

int	 a[size], ans[size];
bool v[size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++) {
		if(v[i])
			continue;
		vector<int> cir;
		int			pos = i;
		while(!v[pos]) {
			cir.push_back(pos);
			v[pos] = true;
			pos	   = a[pos];
		}
		int len = cir.size();
		int inv  = 0;
		while(inv < len) {
			if(1LL * inv * k % len == 1)
				break;
			inv++;
		}
		for(int i = 0; i < len; i++)
			ans[cir[i]] = cir[(i + inv) % len];
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' ';

	return 0;
}