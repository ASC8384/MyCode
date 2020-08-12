/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-06-27 19:35:35
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int f[size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	int n = 1;
	for(int n = 1; n <= t; n++) {
		int tmp = n;
		for(int i = 2; i * i <= n; i++) {
			if(tmp % i)
				continue;
			int cnt = 0;
			while(tmp % i == 0) {
				cnt++;
				tmp /= i;
			}
			f[i] += cnt;
			//cout << i << " " << cnt << '\n';
		}
		if(tmp > 1)
			f[tmp]++;
	}
	for(int i = 1; i <= t; i++) {
		if(f[i])
			cout << i << " " << f[i] << '\n';
	}

	return 0;
}